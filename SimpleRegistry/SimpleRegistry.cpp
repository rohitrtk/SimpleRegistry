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

	this->ui.tableWidget->setRowCount(1);
	this->ui.tableWidget->setColumnCount(MinimumCols);

	std::array<QString, MinimumCols> tableTitles;
	tableTitles[0]	= "ID";
	tableTitles[1]	= "First Name";
	tableTitles[2]	= "Last Name";
	tableTitles[3]	= "Age";
	tableTitles[4]	= "Date Of Birth";
	tableTitles[5]	= "Address";
	tableTitles[6]	= "Home Phone";
	tableTitles[7]	= "Cell Phone";
	tableTitles[8]	= "Email Address";
	tableTitles[9]	= "Previous Location";
	tableTitles[10]	= "Previously Attended";
	tableTitles[11]	= "Years Attended";

	QTableWidget& tw = *this->ui.tableWidget;
	for (size_t i = 0; i < tableTitles.size(); i++)
	{
		tw.setItem(0, i, new QTableWidgetItem(tableTitles[i]));
	}

	connect(ui.actionCreate_Parent, SIGNAL(triggered()), this, SLOT(CreateParent()));
	connect(ui.actionCreate_Child, SIGNAL(triggered()), this, SLOT(CreateChild()));
}

void SimpleRegistry::UpdateTable(const PersonType& personType)
{
	QTableWidget* tw = this->ui.tableWidget;
	Person* p = this->people.at(this->people.size() - 1).get();
	
	int row = this->ui.tableWidget->rowCount() - 1;

	tw->setItem(row, 0, new QTableWidgetItem(p->GetID()));
	tw->setItem(row, 1, new QTableWidgetItem(p->GetFirstName()));
	tw->setItem(row, 2, new QTableWidgetItem(p->GetLastName()));
	tw->setItem(row, 3, new QTableWidgetItem(QString::number(p->GetAge())));
	tw->setItem(row, 4, new QTableWidgetItem(p->GetDateOfBirth().toString()));

	if (personType == PersonType::PARENT)
	{
		Parent* pa = static_cast<Parent*>(p);
		tw->setItem(row, 5, new QTableWidgetItem(pa->GetHomeAddress()));
		tw->setItem(row, 6, new QTableWidgetItem(pa->GetHomePhone()));
		tw->setItem(row, 7, new QTableWidgetItem(pa->GetCellPhone()));
		tw->setItem(row, 8, new QTableWidgetItem(pa->GetEmailAddress()));
	}
	else if (personType == PersonType::CHILD)
	{
		Child* c = static_cast<Child*>(p);
		tw->setItem(row, 9, new QTableWidgetItem(c->GetPrevLocation()));
		tw->setItem(row, 10, new QTableWidgetItem(c->GetPrevAttended()));
		tw->setItem(row, 11, new QTableWidgetItem(c->GetYearsAttended()));
	}
}

void SimpleRegistry::CreateParent()
{
	if (!parentWindow || !parentWindow->isVisible())
	{
		this->parentWindow = std::make_unique<SRCreateUser>();
		this->parentWindow->SetPersonList(this->people);
		this->parentWindow->SetupParentWindow(this);
		this->parentWindow->show();
	}
}

void SimpleRegistry::CreateChild()
{
	if (!this->childWindow || !childWindow->isVisible())
	{
		this->childWindow = std::make_unique<SRCreateUser>();
		this->childWindow->SetPersonList(this->people);
		this->childWindow->SetupChildWindow(this);
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
	this->ui.tableWidget->insertRow(ui.tableWidget->rowCount());
	UpdateTable(event->GetPersonType());
}
