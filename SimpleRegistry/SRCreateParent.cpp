#include "SRCreateParent.h"

SRCreateParent::SRCreateParent(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton_create, SIGNAL(clicked()), this, SLOT(CreateParent()));
	connect(ui.pushButton_cancel, SIGNAL(clicked()), this, SLOT(CancelParent()));
}

SRCreateParent::~SRCreateParent()
{
}

void SRCreateParent::CreateParent()
{
	if (!this->personList)
	{
		throw ERROR_CREATE_PARENT_NULL;
	}

	PersonBuilder builder;

	builder.ID(10);
	MakeFirstName(builder);
	MakeLastName(builder);
	MakeAge(builder);
	MakeDateOfBirth(builder);
	MakeHomeAddress(builder);
	MakeHomePhone(builder);
	MakeCellPhone(builder);
	MakeEmail(builder);

	this->personList->push_back(builder.Build<Parent>());
}

void SRCreateParent::CancelParent()
{
	this->close();
}
