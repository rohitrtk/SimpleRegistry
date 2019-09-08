#include "SimpleRegistry.h"
#include "SRPerson.h"
#include "SRConsants.h"
#include <memory>
#include <QDate>
#include <QAction>
#include <QLineEdit>
#include <QCloseEvent>
#include <QHeaderView>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QtSql>
#include <QTableWidget>
#include <QMessageBox>
#include <QModelIndex>
#include <QVariant>

SimpleRegistry::SimpleRegistry(std::unique_ptr<QSqlDatabase>&& db, QWidget* parent)
	: QMainWindow(parent),
	dataBase(std::move(db))
{

	ui.setupUi(this);
	ui.tableView->installEventFilter(this);
	ui.tableView->setEditTriggers(QAbstractItemView::AllEditTriggers);
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);

	this->parentWindow = std::make_unique<SRCreateParent>(this);
	this->childWindow  = std::make_unique<SRCreateChild>(this);
	this->tableManager = std::make_unique<TableManager>(this, this->ui.tableView);

	connect(ui.actionCreate_Parent, SIGNAL(triggered()), this, SLOT(CreateParent()));
	connect(ui.actionCreate_Child,  SIGNAL(triggered()), this, SLOT(CreateChild()));
	connect(ui.tableView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(DoubleClick(const QModelIndex&)));
		
	LoadTable();
}

SimpleRegistry::~SimpleRegistry()
{
}

void SimpleRegistry::CreateParent() const
{
	this->parentWindow->show();
}

void SimpleRegistry::CreateChild() const
{
	this->childWindow->show();
}

void SimpleRegistry::customEvent(QEvent* event)
{
	if (event->type() == USER_CREATED_EVENT)
	{
		SRUserCreatedEvent* e = static_cast<SRUserCreatedEvent*>(event);
		
		tableManager->AddPersonToTable(e->GetPerson());
	}
}

void SimpleRegistry::closeEvent(QCloseEvent* event)
{
	event->accept();
}

void SimpleRegistry::resizeEvent(QResizeEvent* event)
{
	QMainWindow::resizeEvent(event);

	const QSize& size = event->size();
	this->ui.tableView->setGeometry(0, 0, size.width(), size.height());
}

TableManager::TableManager(SimpleRegistry* sr, QTableView* tv) :
	registry(sr), tableView(tv)
{	
	this->tableView->verticalHeader()->hide();
	this->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void TableManager::AddPersonToTable(const Person& p)
{
	QSqlQuery query;
	QString s = "INSERT INTO test.registered (";

	for (int i = 0; i < tableTitles.size(); i++)
	{
		s += "`" + tableTitles[i].string + "`";

		if (i == tableTitles.size() - 1) break;

		s += ",";
	}	

	s += ") VALUES (";
	s += "'" + QString::number(SimpleRegistry::GetNextAvailableID()) + "',";

	const auto& strings = p.GetValuesAsQStrings();
	for (int i = 0; i < strings.size()-1; i++)
	{
		s += "'" + strings[i] + "'";

		if (i == strings.size() - 2) break;

		s += ",";
	}

	s += ")";

	query.prepare(s);
	if (query.exec())
	{
		LOG("Saved!");
		this->registry->LoadTable();
	}
	else
	{
		LOG("Error saving user!\n" + query.lastError().text());
	}

	registry->GetNextAvailableID();
}

void SimpleRegistry::LoadTable()
{
	SRSqlQueryModel* model = new SRSqlQueryModel();
	
	QSqlQuery* query = new QSqlQuery(dataBase->database());

	query->prepare("SELECT * FROM test.registered");
	query->exec();

	model->setQuery(*query);
	this->ui.tableView->setModel(model);

	delete query;
}

int SimpleRegistry::GetNextAvailableID()
{
	static int id = 1;

	QSqlQuery query;
	query.prepare("SELECT Id from test.registered ORDER BY Id ASC");

	if (query.exec())
	{
		while (query.next())
		{
			if (id == query.value(NULL).toInt())
			{
				id++;
				continue;
			}
		}
	}
	else
	{
		LOG("Unable to get next available ID!");
	}

	return id;
}

bool SimpleRegistry::eventFilter(QObject*, QEvent* event)
{
	if (event->type() == QEvent::KeyPress)
	{
		QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

		if (keyEvent->key() == Qt::Key_Delete)
		{
			DeleteSelectedRow();
			return true;
		}
		else if (keyEvent->key() == Qt::Key_Return)
		{
			this->ui.tableView->edit(ui.tableView->currentIndex());
			return true;
		}
	}

	return false;
}

void SimpleRegistry::DeleteSelectedRow()
{
	QModelIndex index = ui.tableView->selectionModel()->currentIndex();

	QVariant id = index.sibling(index.row(), 0).data();
	
	QSqlQuery query;
	
	QString s("DELETE FROM test.registered WHERE `Id` = ");
	s += id.toString();
	qInfo() << s;
	query.prepare(s);

	if (query.exec())
	{
		LoadTable();
		LOG("Deletion successful!");
	}
	else
	{
		LOG("Unable to delete selected user!\n" + query.lastError().text());
	}
}

void SimpleRegistry::DoubleClick(const QModelIndex& index) const
{
	if (index.isValid())
	{
		QString s = index.data().toString();
		QVariant id = index.sibling(index.row(), 0).data();


	}
}

Qt::ItemFlags SRSqlQueryModel::flags(const QModelIndex& index) const
{
	Qt::ItemFlags flags = QSqlQueryModel::flags(index);

	//if (index.column() != 0)
	//{
	//	flags |= Qt::ItemIsEditable;
	//}

	return flags;
}
