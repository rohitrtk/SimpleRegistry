#include "SimpleRegistry.h"

#include <QDate>
#include <QAction>
#include <QLineEdit>
#include <QCloseEvent>
#include <QHeaderView>
#include <QMessageBox>
#include <QModelIndex>
#include <QVariant>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQueryModel>

#include "SRPerson.h"
#include "SRCreateParent.h"
#include "SRCreateChild.h"
#include "SRConsants.h"

/* ******************** SimpleRegsitry ******************** */

SimpleRegistry::SimpleRegistry(std::unique_ptr<QSqlDatabase>&& db, QWidget* parent)
	: QMainWindow(parent),
	dataBase(std::move(db))
{
	ui.setupUi(this);
	ui.tableView->setEditTriggers(QAbstractItemView::AllEditTriggers);
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);

	this->parentWindow = std::make_unique<SRCreateParent>(this);
	this->childWindow  = std::make_unique<SRCreateChild>(this);
	this->tableManager = std::make_unique<TableManager>(*this);
	this->tableManager ->LoadTable();

	connect(ui.actionCreate_Parent, SIGNAL(triggered()), this, SLOT(CreateParent()));
	connect(ui.actionCreate_Child,  SIGNAL(triggered()), this, SLOT(CreateChild()));
	connect(ui.tableView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(DoubleClick(const QModelIndex&)));
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

QTableView& SimpleRegistry::GetTableView() const
{
	return *this->ui.tableView;
}

QSqlDatabase& SimpleRegistry::GetDatabase() const
{
	return *this->dataBase.get();
}

void SimpleRegistry::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Delete)
	{
		tableManager->DeleteSelectedRow();
	}
	else if (event->key() == Qt::Key_Return)
	{
		this->ui.tableView->edit(ui.tableView->currentIndex());
	}

	QMainWindow::keyPressEvent(event);
}

void SimpleRegistry::DoubleClick(const QModelIndex& index) const
{
	if (index.isValid())
	{
		QString s = index.data().toString();
		QVariant id = index.sibling(index.row(), 0).data();
	}
}

/* ******************** TableManager ******************** */

TableManager::TableManager(SimpleRegistry& sr) :
	registry(sr), tableView(sr.GetTableView()), database(sr.GetDatabase())
{	
	this->tableView.verticalHeader()->hide();
	this->tableView.horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

	Titles[TableTitleIndex::ID]				= "Id";
	Titles[TableTitleIndex::FIRST_NAME]		= "First_Name";
	Titles[TableTitleIndex::LAST_NAME]		= "Last_Name";
	Titles[TableTitleIndex::GENDER]			= "Gender";
	Titles[TableTitleIndex::DATE_OF_BIRTH]	= "Date_of_Birth";
	Titles[TableTitleIndex::AGE]			= "Age";
	Titles[TableTitleIndex::AGE_31]			= "Age_Dec_31";
	Titles[TableTitleIndex::GROUP]			= "Group";
	Titles[TableTitleIndex::PARENTS_NAME]	= "Parents_Name";
	Titles[TableTitleIndex::RELATIONSHIP]	= "Relationship";
	Titles[TableTitleIndex::HOME_ADDRESS]	= "Address";
	Titles[TableTitleIndex::PRIMARY_PHONE]	= "Primary_#";
	Titles[TableTitleIndex::ALT_PHONE]		= "Alternate_#";
	Titles[TableTitleIndex::EMAIL]			= "Email";
	Titles[TableTitleIndex::REGISTERED]		= "Registered";
	Titles[TableTitleIndex::INTERESTS]		= "Interest";
	Titles[TableTitleIndex::MEDICAL]		= "Medical";
}

void TableManager::AddPersonToTable(const Person& p)
{
	QSqlQuery query;
	QString s = "INSERT INTO test.registered (";

	for (int i = 0; i < Titles.size(); i++)
	{
		s += "`" + Titles[static_cast<TableTitleIndex>(i)] + "`";

		if (i == Titles.size() - 1) break;

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
		LoadTable();
	}
	else
	{
		LOG("Error saving user!\n" + query.lastError().text());
	}

	registry.GetNextAvailableID();
}

void TableManager::LoadTable()
{
	QSqlQueryModel* model = new QSqlQueryModel();
	QSqlQuery*		query = new QSqlQuery(database.database());

	query->prepare("SELECT * FROM test.registered");
	query->exec();

	model->setQuery(*query);
	tableView.setModel(model);

	delete query;
}

void TableManager::DeleteSelectedRow()
{
	QModelIndex index = tableView.selectionModel()->currentIndex();

	QVariant id = index.sibling(index.row(), 0).data();
	
	QSqlQuery query;
	
	QString s("DELETE FROM test.registered WHERE `Id` = ");
	
	s += id.toString();
	
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
