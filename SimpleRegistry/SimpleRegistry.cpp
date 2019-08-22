#include "SimpleRegistry.h"
#include "SRPerson.h"
#include <memory>
#include <QDebug>
#include <QDate>
#include <QAction>
#include <QTableWidgetItem>
#include <QLineEdit>
#include "SRConsants.h"

SimpleRegistry::SimpleRegistry(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

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

	people = std::make_shared<sr::_ppl>();
}

void SimpleRegistry::UpdateTable(const PersonType& personType)
{
	QTableWidget* tw = this->ui.tableWidget;
	Person* p = this->people->at(this->people->size() - 1).get();
	
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
	if (!this->createParentForm)
	{
		this->createParentForm = std::make_unique<SRCreateUser>();
		this->createParentForm->SetPersonList(this->people);
		this->createParentForm->SetupParentWindow(this);
		this->createParentForm->show();
	}
}

void SimpleRegistry::CreateChild()
{
	if (!this->createChildForm)
	{
		this->createChildForm = std::make_unique<SRCreateUser>();
		this->createChildForm->SetPersonList(this->people);
		this->createChildForm->SetupChildWindow(this);
		this->createChildForm->show();
	}
}

std::shared_ptr<sr::_ppl> SimpleRegistry::GetPeople()
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

void SimpleRegistry::UserCreated(SRUserCreatedEvent *event)
{
	this->ui.tableWidget->insertRow(ui.tableWidget->rowCount());
	UpdateTable(event->GetPersonType());
}
