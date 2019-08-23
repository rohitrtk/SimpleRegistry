#include "SRCreateUser.h"
#include <QTextEdit>
#include <QObject>
#include <QLayoutItem>
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QDebug>
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

	this->paramMissing = false;
}

SRCreateUser::~SRCreateUser()
{
}

void SRCreateUser::SetupWindow(SimpleRegistry* mainWindow, PersonType type)
{
	this->mainWindow = mainWindow;
	this->personType = type;

	if(type == PersonType::PARENT) this->setWindowTitle(WindowTitleParent);
	else if(type == PersonType::CHILD) this->setWindowTitle(WindowTitleChild);
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
	MakeDateOfBirth(builder);
	
	if (personType == PersonType::PARENT)
	{
		MakeHomeAddress(builder);
		MakeHomePhone(builder);
		MakeCellPhone(builder);
		MakeEmailAddress(builder);
	}
	else if (personType == PersonType::CHILD)
	{
		MakePrevAttended(builder);
		MakePrevLocation(builder);
		MakeYearsAttended(builder);
	}

	if (this->paramMissing)
	{
		std::stringstream ss;
		ss << "Missing field to create ";

		if(personType == PersonType::PARENT) ss << " parent!";
		else ss << " child!";

		QMessageBox::information(this, "Missing fields", ss.str().c_str());

		return;
	}

	if (personType == PersonType::PARENT)
	{
		this->personList->push_back(builder.Build<Parent>());
	}
	else if(personType == PersonType::CHILD)
	{
		this->personList->push_back(builder.Build<Child>());
	}

	QApplication::postEvent(mainWindow, new SRUserCreatedEvent(this->personType));
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

void SRCreateUser::MakeDateOfBirth(PersonBuilder& builder)
{
	builder.DateOfBirth(QDate(ui.dateEdit_dateOfBirth->date()));
}

void SRCreateUser::MakeHomeAddress(PersonBuilder& builder)
{
	QString s = ui.textEdit_homeAddress->toPlainText().trimmed();
	
	if (s.isEmpty())
	{
		this->paramMissing = true;
		return;
	}

	builder.HomeAddress(std::move(s));
}

void SRCreateUser::MakeHomePhone(PersonBuilder& builder)
{
	QString s = ui.textEdit_homePhone->toPlainText().trimmed();

	if (s.isEmpty())
	{
		this->paramMissing = true;
		return;
	}

	builder.HomePhone(std::move(s));
}

void SRCreateUser::MakeCellPhone(PersonBuilder& builder)
{
	QString s = ui.textEdit_cellPhone->toPlainText().trimmed();

	if (s.isEmpty())
	{
		this->paramMissing = true;
		return;
	}

	builder.CellPhone(std::move(s));
}

void SRCreateUser::MakeEmailAddress(PersonBuilder& builder)
{
	if (this->personType == PersonType::CHILD) return;

	QString email = ui.textEdit_emailAddress->toPlainText().trimmed();
	if (!email.isEmpty())
	{
		builder.EmailAddress(std::move(email));
		return;
	}

	this->paramMissing = true;
}

void SRCreateUser::MakePrevAttended(PersonBuilder& builder)
{
	Qt::CheckState checked = ui.checkBox_prevAttended->checkState();

	if (checked == 2) builder.PrevAttended(true);
	else if (checked == 0) builder.PrevAttended(false);
}

void SRCreateUser::MakePrevLocation(PersonBuilder& builder)
{
	QString s = ui.textEdit_prevLocation->toPlainText().trimmed();

	if (s.isEmpty())
	{
		this->paramMissing = true;
		return;
	}
	
	builder.PrevLocation(s);
}

void SRCreateUser::MakeYearsAttended(PersonBuilder& builder)
{
	QString s = ui.textEdit_yearsAttended->toPlainText().trimmed();

	if (s.isEmpty())
	{
		this->paramMissing = true;
		return;
	}

	builder.YearsAttended(s.toUInt());
}
