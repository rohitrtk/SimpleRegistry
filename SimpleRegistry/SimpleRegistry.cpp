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

void SimpleRegistry::UpdateTable()
{
	QTableWidget& tw = *this->ui.tableWidget;
	Person* p = this->people->at(this->people->size() - 1).get();
	
	tw.setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(p->GetID()));
	tw.setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(p->GetFirstName()));
	tw.setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(p->GetLastName()));
	tw.setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(static_cast<QString>(p->GetAge())));
	tw.setItem(ui.tableWidget->rowCount() - 1, 4, new QTableWidgetItem(p->GetDateOfBirth().toString()));

	Parent* pa = static_cast<Parent*>(p);
	Child* c = static_cast<Child*>(p);
	if (pa)
	{
		tw.setItem(ui.tableWidget->rowCount(), 5, new QTableWidgetItem(pa->GetHomeAddress()));
		tw.setItem(ui.tableWidget->rowCount(), 6, new QTableWidgetItem(pa->GetHomePhone()));
		tw.setItem(ui.tableWidget->rowCount(), 7, new QTableWidgetItem(pa->GetCellPhone()));
		tw.setItem(ui.tableWidget->rowCount(), 8, new QTableWidgetItem(pa->GetEmailAddress()));
	}
	else if (c)
	{
		tw.setItem(ui.tableWidget->rowCount(), 9, new QTableWidgetItem(c->GetPrevAttended()));
		tw.setItem(ui.tableWidget->rowCount(), 10, new QTableWidgetItem(c->GetPrevLocation()));
		tw.setItem(ui.tableWidget->rowCount(), 11, new QTableWidgetItem(c->GetYearsAttended()));
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
	if (event->type() == sr::UserCreatedEvent)
	{
		this->ui.tableWidget->insertRow(ui.tableWidget->rowCount());
		UpdateTable();
	}
	else
	{
		QObject::customEvent(event);
	}
}
