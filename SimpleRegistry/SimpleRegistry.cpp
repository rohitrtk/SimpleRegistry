#include "SimpleRegistry.h"
#include "SRPerson.h"
#include "SRPerson.h"
#include <memory>
#include <QDebug>
#include <QDate>
#include <QAction>

SimpleRegistry::SimpleRegistry(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	this->ui.myPushButton->setText("WEE");

	connect(ui.myPushButton, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
	connect(ui.actionCreate_Parent, SIGNAL(triggered()), this, SLOT(CreateUser()));

	people = std::make_shared<sr::_ppl>();

	PersonBuilder builder;

	std::unique_ptr<Person> p = builder.ID(1)->FirstName("Rohit")->LastName("Terry")->Age(20)->DateOfBirth(QDate(1, 1, 1))->Build<Person>();

	std::unique_ptr<Parent> pa = builder.ID(2)->FirstName("Big Rohit")->LastName("Terry")->Age(20)
		->DateOfBirth(QDate(1,1,1))->HomeAddress("Dank St")->EmailAddress("Dank@hotmail.com")
		->HomePhone("123456789")->CellPhone("12353427548")->Build<Parent>();

	std::unique_ptr<Child> cb = builder.ID(3)->FirstName("Small Rohit")->LastName("Terry")->Age(20)
		->DateOfBirth(QDate(1, 1, 1))->PrevAttended(false)->YearsAttended(0)
		->PrevLocation("Yeet")->Group(sr::Group::GROUP_1)->Build<Child>();

	people->push_back(std::move(p));
	people->push_back(std::move(pa));
	people->push_back(std::move(cb));
}

void SimpleRegistry::ButtonClicked()
{
	static int i = 0;

	if(i % 2 == 0) ui.myPushButton->setText("WOO");
	else
	{
		ui.myPushButton->setText("WEE");
		i = -1;
	}

	i++;

	for (const auto& c : *people)
	{
		qInfo() << c->GetInfo();
	}
}

void SimpleRegistry::CreateUser()
{
	if (!this->createUserForm)
	{
		this->createUserForm = std::make_unique<SRCreateUser>();
		this->createUserForm->SetPersonList(this->people);
		this->createUserForm->show();
	}
}

std::shared_ptr<sr::_ppl> SimpleRegistry::GetPeople()
{
	return this->people;
}
