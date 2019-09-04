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
#include "SRCSVHandler.h"
#include <QTableWidget>

SimpleRegistry::SimpleRegistry(std::unique_ptr<QSqlDatabase>&& db, QWidget* parent)
	: QMainWindow(parent),
	dataBase(std::move(db))
{
	ui.setupUi(this);

	this->parentWindow = std::make_unique<SRCreateParent>(this);
	this->childWindow  = std::make_unique<SRCreateChild>(this);
	this->tableManager = std::make_unique<TableManager>(this->ui.tableView);

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

TableManager::TableManager(QTableView* tv) :
	tableView(tv)
{	
	this->tableView->verticalHeader()->hide();
	this->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void TableManager::AddPersonToTable(const Person& p)
{
	/*
	this->tableWidget->insertRow(tableWidget->rowCount());
	int row = this->tableWidget->rowCount() - 1;

	tableWidget->setItem(row, static_cast<int>(TableTitleIndex::ID), new QTableWidgetItem(QString::number(p.GetID())));
	
	QTableWidgetItem* q;

	tableWidget->setItem(row, static_cast<int>(TableTitleIndex::FIRST_NAME),	new QTableWidgetItem(p.GetFirstName()));
	tableWidget->setItem(row, static_cast<int>(TableTitleIndex::LAST_NAME),		new QTableWidgetItem(p.GetLastName()));
	tableWidget->setItem(row, static_cast<int>(TableTitleIndex::GENDER),		new QTableWidgetItem(p.GetGender()));
	tableWidget->setItem(row, static_cast<int>(TableTitleIndex::AGE),			new QTableWidgetItem(QString::number(p.GetAge())));
	tableWidget->setItem(row, static_cast<int>(TableTitleIndex::DOB),			new QTableWidgetItem(p.GetDateOfBirth().toString()));
	tableWidget->setItem(row, static_cast<int>(TableTitleIndex::GROUP),			new QTableWidgetItem(p.GetGroupAsString()));
	tableWidget->setItem(row, static_cast<int>(TableTitleIndex::ALLERGIES),		new QTableWidgetItem(p.GetAllergies()));

	if (p.GetPersonType() == sr::PersonType::PARENT)
	{
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::TYPE),			new QTableWidgetItem("Parent"));
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::ADDRESS),		new QTableWidgetItem(p.GetHomeAddress()));
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::HOME_PHONE),	new QTableWidgetItem(p.GetHomePhone()));
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::CELL_PHONE),	new QTableWidgetItem(p.GetCellPhone()));
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::EMAIL_ADDRESS),	new QTableWidgetItem(p.GetEmailAddress()));
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::CHILDREN),		new QTableWidgetItem(p.GetChildren()));
	}
	else if (p.GetPersonType() == sr::PersonType::CHILD)
	{
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::TYPE),				new QTableWidgetItem("Child"));
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::PARENTS),			new QTableWidgetItem(p.GetParents()));
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::PREV_ATTENDED),		new QTableWidgetItem(p.GetPrevAttendedS()));
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::PREV_LOCATION),		new QTableWidgetItem(p.GetPrevLocation()));
		q = new QTableWidgetItem(QString::number(p.GetYearsAttended()));
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::YEARS_ATTENDED), q);
	}
	*/
}

void SimpleRegistry::LoadTable()
{
	QSqlQueryModel* model = new QSqlQueryModel();

	QSqlQuery* query = new QSqlQuery(dataBase->database());

	query->prepare("select * from test.registered");
	query->exec();

	model->setQuery(*query);
	this->ui.tableView->setModel(model);
}
