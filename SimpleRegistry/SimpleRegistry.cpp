#include "SimpleRegistry.h"
#include "SRPerson.h"
#include <memory>
#include <QDebug>
#include <QDate>
#include <QAction>
#include <QLineEdit>
#include <QCloseEvent>
#include <QHeaderView>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <fstream>
#include <QtSql>
#include <QSqlDatabase>
#include "SRConsants.h"
#include <QTableWidget>
#include <QMessageBox>

SimpleRegistry::SimpleRegistry(std::unique_ptr<QSqlDatabase>&& db, QWidget* parent)
	: QMainWindow(parent),
	dataBase(std::move(db))
{
	ui.setupUi(this);

	this->parentWindow = std::make_unique<SRCreateParent>(this);
	this->childWindow  = std::make_unique<SRCreateChild>(this);
	this->tableManager = std::make_unique<TableManager>(this, this->ui.tableView);

	connect(ui.actionCreate_Parent, SIGNAL(triggered()), this, SLOT(CreateParent()));
	connect(ui.actionCreate_Child,  SIGNAL(triggered()), this, SLOT(CreateChild()));
	connect(ui.actionSave,			SIGNAL(triggered()), this, SLOT(Save()));

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

void SimpleRegistry::Save()
{
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
		qInfo() << "Saved!";
		this->registry->LoadTable();
	}
	else
	{
		qInfo() << "Error saving user!" << query.lastError().text();
	}

	registry->GetNextAvailableID();
}

void SimpleRegistry::LoadTable()
{
	QSqlQueryModel* model = new QSqlQueryModel();

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
		qInfo() << "Query failed!";
	}

	return id;
}
