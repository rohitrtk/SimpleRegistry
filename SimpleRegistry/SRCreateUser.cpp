#include "SRCreateUser.h"
#include <QTextEdit>
#include <QObject>
#include <QLayoutItem>
#include "SRPopUp.h"
#include "SRPerson.h"

SRCreateUser::SRCreateUser(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton_create, SIGNAL(clicked()), this, SLOT(Create()));
	connect(ui.pushButton_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
	connect(ui.pushButton_clear,  SIGNAL(clicked()), this, SLOT(Clear()));

	this->paramMissing = 0;
}

SRCreateUser::~SRCreateUser()
{
}

void SRCreateUser::Create()
{
	if (!this->personList)
	{
		throw ERROR_CREATE_PARENT_NULL;
	}

	this->paramMissing = false;

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

	if (this->paramMissing)
	{
		popUp = std::make_unique<SRPopUp>();
		std::stringstream ss;
		ss << FIELD_MISSING_MSG << " parent!";

		popUp->SetMessage(ss.str().c_str());
		popUp->show();

		return;
	}

	this->personList->push_back(builder.Build<Parent>());
}

void SRCreateUser::Cancel()
{
	this->close();
}

void SRCreateUser::Clear()
{
	for (size_t i = 0; i < ui.formLayout->count(); ++i)
	{
		QTextEdit* q = dynamic_cast<QTextEdit*>(ui.formLayout->itemAt(i)->widget());
		if (q)
		{
			q->clear();
		}
	}
}

void SRCreateUser::MakeFirstName(PersonBuilder& builder)
{
	QString firstName = ui.textEdit_firstName->toPlainText().trimmed();
	if (!firstName.isEmpty())
	{
		builder.FirstName(std::move(firstName.toStdString()));
		return;
	}

	this->paramMissing = true;
}

void SRCreateUser::MakeLastName(PersonBuilder& builder)
{
	QString lastName = ui.textEdit_lastName->toPlainText().trimmed();
	if (!lastName.isEmpty())
	{
		builder.LastName(std::move(lastName.toStdString()));
		return;
	}

	this->paramMissing = true;
}

void SRCreateUser::MakeAge(PersonBuilder& builder)
{
	// *
	QString age_str = ui.textEdit_age->toPlainText().trimmed();
	if (!age_str.isEmpty())
	{
		builder.Age(age_str.toInt());
		return;
	}

	this->paramMissing = true;
}

void SRCreateUser::MakeDateOfBirth(PersonBuilder& builder)
{
	// *
	builder.DateOfBirth(QDate(1, 1, 1));
}

void SRCreateUser::MakeHomeAddress(PersonBuilder& builder)
{
	QString ha = ui.textEdit_homeAddress->toPlainText().trimmed();
	if (!ha.isEmpty())
	{
		builder.HomeAddress(std::move(ha.toStdString()));
		return;
	}

	this->paramMissing = true;
}

void SRCreateUser::MakeHomePhone(PersonBuilder& builder)
{
	QString homePhone = ui.textEdit_homePhone->toPlainText().trimmed();
	if (!homePhone.isEmpty())
	{
		builder.HomePhone(std::move(homePhone.toStdString()));
		return;
	}

	this->paramMissing = true;
}

void SRCreateUser::MakeCellPhone(PersonBuilder& builder)
{
	QString cellPhone = ui.textEdit_cellPhone->toPlainText().trimmed();
	if (!cellPhone.isEmpty())
	{
		builder.CellPhone(std::move(cellPhone.toStdString()));
		return;
	}

	this->paramMissing = true;
}

void SRCreateUser::MakeEmail(PersonBuilder& builder)
{
	QString email = ui.textEdit_emailAddress->toPlainText().trimmed();
	if (!email.isEmpty())
	{
		builder.EmailAddress(std::move(email.toStdString()));
		return;
	}

	this->paramMissing = true;
}
