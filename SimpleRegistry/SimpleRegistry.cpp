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

	this->currentRows = 1;
	this->ui.tableWidget->setRowCount(currentRows);
	this->ui.tableWidget->setColumnCount(MinimumCols);

	this->w_ID				= std::make_unique<QTableWidgetItem>(t_ID);
	this->w_FirstName		= std::make_unique<QTableWidgetItem>(t_FirstName);
	this->w_LastName		= std::make_unique<QTableWidgetItem>(t_LastName);
	this->w_Age				= std::make_unique<QTableWidgetItem>(t_Age);
	this->w_DOB				= std::make_unique<QTableWidgetItem>(t_DOB);
	this->w_HomeAddress		= std::make_unique<QTableWidgetItem>(t_HomeAddress);
	this->w_HomePhone		= std::make_unique<QTableWidgetItem>(t_HomePhone);
	this->w_CellPhone		= std::make_unique<QTableWidgetItem>(t_CellPhone);
	this->w_PrevLocation	= std::make_unique<QTableWidgetItem>(t_PrevLocation);
	this->w_PrevAttended	= std::make_unique<QTableWidgetItem>(t_PrevAttended);
	this->w_YearsAttended	= std::make_unique<QTableWidgetItem>(t_YearsAttended);

	this->ui.tableWidget->setItem(0, 0, w_ID.get());
	this->ui.tableWidget->setItem(0, 1, w_FirstName.get());
	this->ui.tableWidget->setItem(0, 2, w_LastName.get());
	this->ui.tableWidget->setItem(0, 3, w_Age.get());
	this->ui.tableWidget->setItem(0, 4, w_DOB.get());
	this->ui.tableWidget->setItem(0, 5, w_HomeAddress.get());
	this->ui.tableWidget->setItem(0, 6, w_HomePhone.get());
	this->ui.tableWidget->setItem(0, 7, w_CellPhone.get());
	this->ui.tableWidget->setItem(0, 8, w_PrevLocation.get());
	this->ui.tableWidget->setItem(0, 9, w_PrevAttended.get());
	this->ui.tableWidget->setItem(0, 10, w_YearsAttended.get());

	connect(ui.actionCreate_Parent, SIGNAL(triggered()), this, SLOT(CreateParent()));
	connect(ui.actionCreate_Child, SIGNAL(triggered()), this, SLOT(CreateChild()));

	people = std::make_shared<sr::_ppl>();
}

void SimpleRegistry::UpdateTable()
{
	this->currentRows++;
	
	QTableWidget& tw = *this->ui.tableWidget;
	tw.setRowCount(currentRows);

	Person& p = *people->at(people->size() - 1);

	// *
	tw.setItem(currentRows--, 0, new QTableWidgetItem(p.GetID()));
	tw.setItem(currentRows--, 1, new QTableWidgetItem(p.GetFirstName()));
	tw.setItem(currentRows--, 2, new QTableWidgetItem(p.GetLastName()));
	tw.setItem(currentRows--, 3, new QTableWidgetItem(p.GetAge()));
	tw.setItem(currentRows--, 4, new QTableWidgetItem(p.GetDateOfBirth().toString()));
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
		UpdateTable();
		qInfo() << "YEET";
	}
	else
	{
		QObject::customEvent(event);
	}
}
