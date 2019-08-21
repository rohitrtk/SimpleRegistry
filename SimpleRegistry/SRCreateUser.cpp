#include "SRCreateUser.h"
#include <QTextEdit>
#include <QObject>
#include <QLayoutItem>
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include "SRPopUp.h"
#include "SRPerson.h"
#include "SRConsants.h"
#include "SimpleRegistry.h"

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

void SRCreateUser::SetupParentWindow(SimpleRegistry* mainWindow)
{
	this->personType = PersonType::PARENT;
	this->mainWindow = mainWindow;
	this->setWindowTitle(WindowTitleParent);

	this->ui.label_var1->setText(p_homeAddress);
	this->ui.label_var2->setText(p_homePhone);
	this->ui.label_var3->setText(p_cellPhone);
	this->ui.label_var4->setText(p_emailAddress);
}

void SRCreateUser::SetupChildWindow(SimpleRegistry* mainWindow)
{
	this->personType = PersonType::CHILD;
	this->mainWindow = mainWindow;
	this->setWindowTitle(WindowTitleChild);

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

	QApplication::postEvent(mainWindow, new QEvent(sr::UserCreatedEvent));
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
		builder.FirstName(std::move(firstName));
		return;
	}

	this->paramMissing = true;
}

void SRCreateUser::MakeLastName(PersonBuilder& builder)
{
	QString lastName = ui.textEdit_lastName->toPlainText().trimmed();
	if (!lastName.isEmpty())
	{
		builder.LastName(std::move(lastName));
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

	if (this->personType == PersonType::PARENT) builder.HomeAddress(std::move(s));
	else builder.PrevLocation(std::move(s));
}

void SRCreateUser::MakeVar2(PersonBuilder& builder)
{
	QString s = ui.textEdit_var2->toPlainText().trimmed();

	if (s.isEmpty())
	{
		this->paramMissing = true;
	}

	if (this->personType == PersonType::PARENT) builder.HomePhone(std::move(s));
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

	if (this->personType == PersonType::PARENT) builder.CellPhone(std::move(s));
	// *
	else builder.YearsAttended(1);
}

void SRCreateUser::MakeVar4(PersonBuilder& builder)
{
	QString email = ui.textEdit_var4->toPlainText().trimmed();
	if (!email.isEmpty())
	{
		builder.EmailAddress(std::move(email));
		return;
	}

	this->paramMissing = true;
}
