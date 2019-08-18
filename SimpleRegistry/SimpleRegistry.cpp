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

	Person* p = builder.FirstName("Rohit")->LastName("Terry")->Age(20)->DateOfBirth(QDate(1, 1, 1))->Build<Person>();
	qInfo() << p->GetInfo();

	Parent* pa = builder.FirstName("Big Rohit")->LastName("Terry")->Age(20)
		->DateOfBirth(QDate(1,1,1))->HomeAddress("Dank St")->EmailAddress("Dank@hotmail.com")
		->HomePhone("123456789")->CellPhone("12353427548")->Build<Parent>();
	qInfo() << pa->GetInfo();

	Child* cb = builder.FirstName("Small Rohit")->LastName("Terry")->Age(20)
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
