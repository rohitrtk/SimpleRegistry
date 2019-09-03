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
#include "SRConsants.h"
#include "SRCSVHandler.h"
#include <QtSql>
#include <QSqlDatabase>

SimpleRegistry::SimpleRegistry(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->parentWindow = std::make_unique<SRCreateUser>();
	this->parentWindow->SetupWindow(this);

	this->childWindow  = std::make_unique<SRCreateUser>();
	this->childWindow->SetupWindow(this, sr::PersonType::CHILD);

	this->tableManager = std::make_unique<TableManager>(this->ui.tableWidget);

	connect(ui.actionCreate_Parent, SIGNAL(triggered()), this, SLOT(CreateParent()));
	connect(ui.actionCreate_Child,  SIGNAL(triggered()), this, SLOT(CreateChild()));
	connect(ui.actionSave,			SIGNAL(triggered()), this, SLOT(Save()));

	QSqlDatabase dataBase = QSqlDatabase::addDatabase("QMYSQL");
	dataBase.setHostName("localhost");
	dataBase.setUserName("root");
	dataBase.setPassword("");
	dataBase.setDatabaseName("test");

	if (dataBase.open())
	{
		qInfo() << "Connected!";
	}
	else
	{
		qInfo() << "Connection failed!";
	}
}

SimpleRegistry::~SimpleRegistry()
{
}

void SimpleRegistry::MakeWindow(const sr::PersonType&& person) const
{
	if (person == sr::PersonType::PARENT && !parentWindow->isVisible())
	{
		this->parentWindow->show();
	}
	else if (person == sr::PersonType::CHILD && !childWindow->isVisible())
	{
		this->childWindow->show();
	}
}

void SimpleRegistry::CreateParent() const
{
	MakeWindow(sr::PersonType::PARENT);
}

void SimpleRegistry::CreateChild() const
{
	MakeWindow(sr::PersonType::CHILD);
}

void SimpleRegistry::Save()
{
	const QTableWidget& tw = this->tableManager->GetTableWidget();
	std::ofstream f;

	f.open("test.csv");
	for (int i = 0; i < tw.rowCount(); i++)
	{
		for (int j = 0; j < tw.columnCount(); j++)
		{
			qInfo() << tw.itemAt(j, i)->data(0);
		}
	}
	f.close();
	//handler.WriteRecord(this->people);
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
	this->ui.tableWidget->setGeometry(0, 0, size.width(), size.height());
}

TableManager::TableManager(QTableWidget* tw) :
	tableWidget(tw)
{	
	this->tableTitles
		<< "ID"					<< "Type"				<< "First Name"
		<< "Last Name"			<< "Gender"				<< "Age"
		<< "Date Of Birth"		<< "Group"				<< "Address"
		<< "Home Phone"			<< "Cell Phone"			<< "Email Address"
		<< "Previously Attended"<< "Previous Location"	<< "Years Attended"
		<< "Parent/Guardian(s)" << "Children"			<< "Medical Allergies";

	qint16 numColumns = tableTitles.size();
	this->tableWidget->setColumnCount(numColumns);
	this->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	this->tableWidget->horizontalHeader()->setStretchLastSection(true);

	for (size_t i = 0; i < numColumns; i++)
	{
		tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(tableTitles[i]));
	}
}

void TableManager::AddPersonToTable(const Person& p)
{
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
}
