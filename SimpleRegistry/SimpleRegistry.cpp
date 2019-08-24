#include "SimpleRegistry.h"
#include "SRPerson.h"
#include <memory>
#include <QDebug>
#include <QDate>
#include <QAction>
#include <QTableWidgetItem>
#include <QLineEdit>
#include <QCloseEvent>
#include "SRConsants.h"

SimpleRegistry::SimpleRegistry(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->parentWindow = nullptr;
	this->childWindow = nullptr;

	std::vector<QString> tableTitles;
	tableTitles.push_back("ID");
	tableTitles.push_back("First Name");
	tableTitles.push_back("Last Name");
	tableTitles.push_back("Age");
	tableTitles.push_back("Date Of Birth");
	tableTitles.push_back("Address");
	tableTitles.push_back("Home Phone");
	tableTitles.push_back("Cell Phone");
	tableTitles.push_back("Email Address");
	tableTitles.push_back("Previous Location");
	tableTitles.push_back("Previously Attended");
	tableTitles.push_back("Years Attended");

	this->MinimumCols = tableTitles.size();

	this->ui.tableWidget->setRowCount(1);
	this->ui.tableWidget->setColumnCount(MinimumCols);

	QTableWidget& tw = *this->ui.tableWidget;
	for (size_t i = 0; i < tableTitles.size(); i++)
	{
		tw.setItem(0, i, new QTableWidgetItem(tableTitles[i]));
	}

	connect(ui.actionCreate_Parent, SIGNAL(triggered()), this, SLOT(CreateParent()));
	connect(ui.actionCreate_Child, SIGNAL(triggered()), this, SLOT(CreateChild()));

	tableManager = std::make_unique<TableManager>(ui.tableWidget, &people);
}

void SimpleRegistry::UpdateTable(const sr::PersonType& personType)
{
	tableManager->AddPersonToTable(people.at(people.size() - 1).get());
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

TableManager::TableManager(QTableWidget* const tw, std::vector<std::unique_ptr<Person>>* const people) : 
	tableWidget(tw),
	people(people)
{
}

void TableManager::AddPersonToTable(Person* p)
{
	this->tableWidget->insertRow(tableWidget->rowCount());
	int row = this->tableWidget->rowCount() - 1;

	tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(p->GetID())));
	tableWidget->setItem(row, 1, new QTableWidgetItem(p->GetFirstName()));
	tableWidget->setItem(row, 2, new QTableWidgetItem(p->GetLastName()));
	tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(p->GetAge())));
	tableWidget->setItem(row, 4, new QTableWidgetItem(p->GetDateOfBirth().toString()));

	if (p->GetPersonType() == sr::PersonType::PARENT)
	{
		tableWidget->setItem(row, 5, new QTableWidgetItem(p->GetHomeAddress()));
		tableWidget->setItem(row, 6, new QTableWidgetItem(p->GetHomePhone()));
		tableWidget->setItem(row, 7, new QTableWidgetItem(p->GetCellPhone()));
		tableWidget->setItem(row, 8, new QTableWidgetItem(p->GetEmailAddress()));
	}
	else if (p->GetPersonType() == sr::PersonType::CHILD)
	{
		tableWidget->setItem(row, 9, new QTableWidgetItem(p->GetPrevLocation()));

		QTableWidgetItem* q = new QTableWidgetItem();
		Qt::CheckState checkState = p->GetPrevAttendedS();
		q->setCheckState(checkState);
		tableWidget->setItem(row, 10, q);

		tableWidget->setItem(row, 11, new QTableWidgetItem(QString::number(p->GetYearsAttended())));
	}
}
