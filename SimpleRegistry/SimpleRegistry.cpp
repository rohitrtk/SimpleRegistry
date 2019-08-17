#include "SimpleRegistry.h"
#include "Person.h"
#include <QDebug>
#include <memory>

SimpleRegistry::SimpleRegistry(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.myPushButton, SIGNAL(clicked()), this, SLOT(ButtonClicked()));

	PersonBuilder personBuilder;
	ParentBuilder parentBuilder;
	ChildBuilder  childBuilder;

	std::shared_ptr<Person> person = 
		personBuilder.Age(20)->
		FirstName("Rohit")->
		LastName("Kisto")->
		DateOfBirth(QDate())->
		Build();
}
