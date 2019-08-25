#include "SimpleRegistry.h"
#include "SRPerson.h"
#include <memory>
#include <QDebug>
#include <QDate>
#include <QAction>
#include <QTableWidgetItem>
#include <QLineEdit>
#include <QCloseEvent>
#include <QHeaderView>
#include "SRConsants.h"

SimpleRegistry::SimpleRegistry(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->parentWindow = nullptr;
	this->childWindow = nullptr;

	tableManager = std::make_unique<TableManager>(this->ui.tableWidget, &this->people);

	connect(ui.actionCreate_Parent, SIGNAL(triggered()), this, SLOT(CreateParent()));
	connect(ui.actionCreate_Child,  SIGNAL(triggered()), this, SLOT(CreateChild()));
}

void SimpleRegistry::CreateParent()
{
	if (!parentWindow || !parentWindow->isVisible())
	{
		this->parentWindow = std::make_unique<SRCreateUser>();
		this->parentWindow->SetPersonList(this->people);
		this->parentWindow->SetupWindow(this);
		this->parentWindow->show();
	}
}

void SimpleRegistry::CreateChild()
{
	if (!this->childWindow || !childWindow->isVisible())
	{
		this->childWindow = std::make_unique<SRCreateUser>();
		this->childWindow->SetPersonList(this->people);
		this->childWindow->SetupWindow(this, sr::PersonType::CHILD);
		this->childWindow->show();
	}
}

const std::vector<std::unique_ptr<Person>>& SimpleRegistry::GetPeople()
{
	return this->people;
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
	Person* p = people.at(people.size() - 1).get();
	tableManager->AddPersonToTable(p);
}

void SimpleRegistry::resizeEvent(QResizeEvent* event)
{
	QMainWindow::resizeEvent(event);

	const QSize& size = event->size();
	this->ui.tableWidget->setGeometry(0, 0, size.width(), size.height());
}

TableManager::TableManager(QTableWidget* tw, std::vector<std::unique_ptr<Person>>* people) :
	tableWidget(tw),
	people(people)
{	
	this->tableTitles 
		<< "ID"				<< "Type"					<< "First Name" 
		<< "Last Name"		<< "Age"					<< "Date Of Birth" 
		<< "Address"		<< "Home Phone"				<< "Cell Phone" 
		<< "Email Address"	<< "Previously Attended"	<< "Previous Location" 
		<< "Years Attended" << "Medical Allergies";

	qint16 numColumns = tableTitles.size();
	this->tableWidget->setColumnCount(numColumns);
	this->tableWidget->setRowCount(1);
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

	tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(p->GetID())));
	
	tableWidget->setItem(row, 2, new QTableWidgetItem(p->GetFirstName()));
	tableWidget->setItem(row, 3, new QTableWidgetItem(p->GetLastName()));
	tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(p->GetAge())));
	tableWidget->setItem(row, 5, new QTableWidgetItem(p->GetDateOfBirth().toString()));

	if (p->GetPersonType() == sr::PersonType::PARENT)
	{
		tableWidget->setItem(row, 1, new QTableWidgetItem("Parent"));

		tableWidget->setItem(row, 6, new QTableWidgetItem(p->GetHomeAddress()));
		tableWidget->setItem(row, 7, new QTableWidgetItem(p->GetHomePhone()));
		tableWidget->setItem(row, 8, new QTableWidgetItem(p->GetCellPhone()));
		tableWidget->setItem(row, 9, new QTableWidgetItem(p->GetEmailAddress()));
	}
	else if (p->GetPersonType() == sr::PersonType::CHILD)
	{
		tableWidget->setItem(row, 1, new QTableWidgetItem("Child"));

		QTableWidgetItem* q = new QTableWidgetItem();
		Qt::CheckState checkState = p->GetPrevAttendedS();
		q->setCheckState(checkState);
		tableWidget->setItem(row, 10, q);

		tableWidget->setItem(row, 11, new QTableWidgetItem(p->GetPrevLocation()));

		tableWidget->setItem(row, 12, new QTableWidgetItem(QString::number(p->GetYearsAttended())));
	}
}
