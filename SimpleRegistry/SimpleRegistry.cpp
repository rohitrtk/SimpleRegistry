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
#include "SRConsants.h"
#include "SRCSVHandler.h"

SimpleRegistry::SimpleRegistry(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->parentWindow = std::make_unique<SRCreateUser>();
	this->parentWindow->SetPersonList(&people);
	this->parentWindow->SetupWindow(this);

	this->childWindow  = std::make_unique<SRCreateUser>();
	this->childWindow->SetPersonList(&people);
	this->childWindow->SetupWindow(this, sr::PersonType::CHILD);

	this->tableManager = std::make_unique<TableManager>(this->ui.tableWidget, this->people);

	connect(ui.actionCreate_Parent, SIGNAL(triggered()), this, SLOT(CreateParent()));
	connect(ui.actionCreate_Child,  SIGNAL(triggered()), this, SLOT(CreateChild()));
	connect(ui.actionSave,			SIGNAL(triggered()), this, SLOT(Save()));
}

SimpleRegistry::~SimpleRegistry()
{
	for (const auto& c : this->people)
	{
		delete c;
	}
	this->people.clear();
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
	CSVHandler handler("test.csv");
	handler.WriteRecord(this->people);
}

void SimpleRegistry::customEvent(QEvent* event)
{
	if (event->type() == USER_CREATED_EVENT)
	{
		UserCreated(static_cast<SRUserCreatedEvent*>(event));
	}
}

void SimpleRegistry::closeEvent(QCloseEvent* event)
{
	event->accept();
}

void SimpleRegistry::UserCreated(SRUserCreatedEvent* event)
{
	Person* p = people.at(people.size() - 1);
	tableManager->AddPersonToTable(p);
}

void SimpleRegistry::resizeEvent(QResizeEvent* event)
{
	QMainWindow::resizeEvent(event);

	const QSize& size = event->size();
	this->ui.tableWidget->setGeometry(0, 0, size.width(), size.height());
}

TableManager::TableManager(QTableWidget* tw, std::vector<Person*>& people) :
	tableWidget(tw),
	people(people)
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

void TableManager::AddPersonToTable(Person* p)
{
	this->tableWidget->insertRow(tableWidget->rowCount());
	int row = this->tableWidget->rowCount() - 1;

	tableWidget->setItem(row, static_cast<int>(TableTitleIndex::ID), new QTableWidgetItem(QString::number(p->GetID())));
	
	tableWidget->setItem(row, static_cast<int>(TableTitleIndex::FIRST_NAME),	new QTableWidgetItem(p->GetFirstName()));
	tableWidget->setItem(row, static_cast<int>(TableTitleIndex::LAST_NAME),		new QTableWidgetItem(p->GetLastName()));
	tableWidget->setItem(row, static_cast<int>(TableTitleIndex::GENDER),		new QTableWidgetItem(p->GetGender()));
	tableWidget->setItem(row, static_cast<int>(TableTitleIndex::AGE),			new QTableWidgetItem(QString::number(p->GetAge())));
	tableWidget->setItem(row, static_cast<int>(TableTitleIndex::DOB),			new QTableWidgetItem(p->GetDateOfBirth().toString()));
	tableWidget->setItem(row, static_cast<int>(TableTitleIndex::GROUP),			new QTableWidgetItem(p->GetGroupAsString()));
	tableWidget->setItem(row, static_cast<int>(TableTitleIndex::ALLERGIES),		new QTableWidgetItem(p->GetAllergies()));

	if (p->GetPersonType() == sr::PersonType::PARENT)
	{
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::TYPE),			new QTableWidgetItem("Parent"));
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::ADDRESS),		new QTableWidgetItem(p->GetHomeAddress()));
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::HOME_PHONE),	new QTableWidgetItem(p->GetHomePhone()));
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::CELL_PHONE),	new QTableWidgetItem(p->GetCellPhone()));
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::EMAIL_ADDRESS),	new QTableWidgetItem(p->GetEmailAddress()));
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::CHILDREN),		new QTableWidgetItem(p->GetChildren()));
	}
	else if (p->GetPersonType() == sr::PersonType::CHILD)
	{
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::TYPE),		new QTableWidgetItem("Child"));
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::PARENTS),	new QTableWidgetItem(p->GetParents()));

		QTableWidgetItem* q = new QTableWidgetItem();
		Qt::CheckState checkState = p->GetPrevAttendedS();
		q->setCheckState(checkState);
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::PREV_ATTENDED), q);

		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::PREV_LOCATION),		new QTableWidgetItem(p->GetPrevLocation()));
		tableWidget->setItem(row, static_cast<int>(TableTitleIndex::YEARS_ATTENDED),	new QTableWidgetItem(QString::number(p->GetYearsAttended())));
	}
}
