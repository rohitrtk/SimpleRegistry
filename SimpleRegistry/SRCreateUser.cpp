#include "SRCreateUser.h"
#include <QTextEdit>
#include <QObject>
#include <QLayoutItem>
#include "SRPopUp.h"
#include "SRPerson.h"
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>

SRCreateUser::SRCreateUser(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton_create, SIGNAL(clicked()), this, SLOT(Create()));
	connect(ui.pushButton_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
	connect(ui.pushButton_clear,  SIGNAL(clicked()), this, SLOT(Clear()));

	this->resize(WindowWidth, WindowHeight);

	this->paramMissing = 0;
}

SRCreateUser::~SRCreateUser()
{
}

void SRCreateUser::SetupParentWindow()
{
	this->formType = FormType::PARENT;

	this->ui.label_var1->setText(p_homeAddress);
	this->ui.label_var2->setText(p_homePhone);
	this->ui.label_var3->setText(p_cellPhone);
	this->ui.label_var4->setText(p_emailAddress);
}

void SRCreateUser::SetupChildWindow()
{
	this->formType = FormType::CHILD;

	this->ui.label_var1->setText(c_prevLocation);
	this->ui.label_var2->setText(c_prevAttended);
	this->ui.label_var3->setText(c_yearsAttended);
	this->ui.label_var4->setEnabled(false);
	this->ui.label_var4->setHidden(true);
	this->ui.textEdit_var4->setEnabled(false);
	this->ui.textEdit_var4->setHidden(true);
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
	MakeVar1(builder);
	MakeVar2(builder);
	MakeVar3(builder);
	MakeVar4(builder);

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
	// *TODO
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
	// *TODO
	builder.DateOfBirth(QDate(1, 1, 1));
}

void SRCreateUser::MakeVar1(PersonBuilder& builder)
{
	QString s = ui.textEdit_var1->toPlainText().trimmed();

	if (s.isEmpty())
	{
		this->paramMissing = true;
	}

	if (this->formType == FormType::PARENT) builder.HomeAddress(std::move(s.toStdString()));
	else builder.PrevLocation(std::move(s.toStdString()));
}

void SRCreateUser::MakeVar2(PersonBuilder& builder)
{
	QString s = ui.textEdit_var2->toPlainText().trimmed();

	if (s.isEmpty())
	{
		this->paramMissing = true;
	}

	if (this->formType == FormType::PARENT) builder.HomePhone(std::move(s.toStdString()));
	// *TODO
	else builder.PrevAttended(true);
}

void SRCreateUser::MakeVar3(PersonBuilder& builder)
{
	QString s = ui.textEdit_var2->toPlainText().trimmed();

	if (s.isEmpty())
	{
		this->paramMissing = true;
	}

	if (this->formType == FormType::PARENT) builder.CellPhone(std::move(s.toStdString()));
	// *
	else builder.YearsAttended(1);
}

void SRCreateUser::MakeVar4(PersonBuilder& builder)
{
	QString email = ui.textEdit_var4->toPlainText().trimmed();
	if (!email.isEmpty())
	{
		builder.EmailAddress(std::move(email.toStdString()));
		return;
	}

	this->paramMissing = true;
}
