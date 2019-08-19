#include "SimpleRegistry.h"
#include "SRPerson.h"
#include <QDebug>
#include <memory>

SimpleRegistry::SimpleRegistry(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.myPushButton->setText("WEE");
	connect(ui.myPushButton, SIGNAL(clicked()), this, SLOT(ButtonClicked()));

	PersonBuilder builder;

	std::unique_ptr<Person> p = builder.ID(1)->FirstName("Rohit")->LastName("Terry")->Age(20)->DateOfBirth(QDate(1, 1, 1))->Build<Person>();
	qInfo() << p->GetInfo();

	std::unique_ptr<Parent> pa = builder.ID(2)->FirstName("Big Rohit")->LastName("Terry")->Age(20)
		->DateOfBirth(QDate(1,1,1))->HomeAddress("Dank St")->EmailAddress("Dank@hotmail.com")
		->HomePhone("123456789")->CellPhone("12353427548")->Build<Parent>();
	qInfo() << pa->GetInfo();

	std::unique_ptr<Child> cb = builder.ID(3)->FirstName("Small Rohit")->LastName("Terry")->Age(20)
		->DateOfBirth(QDate(1, 1, 1))->PrevAttended(false)->YearsAttended(0)
		->PrevLocation("Yeet")->Build<Child>();
	qInfo() << cb->GetInfo();
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
}
