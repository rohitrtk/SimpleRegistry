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
#include <QKeyEvent>
#include "SRPerson.h"
#include "SRConsants.h"
#include "SimpleRegistry.h"
#include <QWidget>

qint16 SRCreateUser::idAssign = 1;

SRCreateUser::SRCreateUser(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->ui.textEdit_firstName->		installEventFilter(this);
	this->ui.textEdit_lastName->		installEventFilter(this);
	this->ui.dateEdit_dateOfBirth->		installEventFilter(this);
	this->ui.textEdit_homeAddress->		installEventFilter(this);
	this->ui.textEdit_homePhone->		installEventFilter(this);
	this->ui.textEdit_cellPhone->		installEventFilter(this);
	this->ui.textEdit_emailAddress->	installEventFilter(this);
	this->ui.checkBox_prevAttended->	installEventFilter(this);
	this->ui.textEdit_prevLocation->	installEventFilter(this);
	this->ui.textEdit_yearsAttended->	installEventFilter(this);
	
	connect(ui.pushButton_create, SIGNAL(clicked()), this, SLOT(Create()));
	connect(ui.pushButton_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
	connect(ui.pushButton_clear,  SIGNAL(clicked()), this, SLOT(Clear()));
	connect(ui.checkBox_prevAttended, SIGNAL(stateChanged(int)), this, SLOT(HandlePrevAttended(int)));

	this->resize(WindowWidth, WindowHeight);

	this->paramMissing = false;
	this->personType = sr::PersonType::UNDEFINED;
	
	QWidget::setTabOrder(ui.textEdit_firstName,		ui.textEdit_lastName);
	QWidget::setTabOrder(ui.textEdit_lastName,		ui.dateEdit_dateOfBirth);
	QWidget::setTabOrder(ui.dateEdit_dateOfBirth,	ui.textEdit_homeAddress);
	QWidget::setTabOrder(ui.textEdit_homeAddress,	ui.textEdit_homePhone);
	QWidget::setTabOrder(ui.textEdit_homePhone,		ui.textEdit_cellPhone);
	QWidget::setTabOrder(ui.textEdit_cellPhone,		ui.textEdit_emailAddress);
	QWidget::setTabOrder(ui.textEdit_emailAddress,	ui.checkBox_prevAttended);
	QWidget::setTabOrder(ui.checkBox_prevAttended,	ui.textEdit_prevLocation);
	QWidget::setTabOrder(ui.textEdit_prevLocation,	ui.textEdit_yearsAttended);
}

SRCreateUser::~SRCreateUser()
{
}

void SRCreateUser::SetupWindow(SimpleRegistry* mainWindow, sr::PersonType type)
{
	this->mainWindow = mainWindow;
	this->personType = type;

	this->ui.label_firstName->setText(ui.label_firstName->text() + "*");
	this->ui.label_lastName->setText(ui.label_lastName->text() + "*");
	this->ui.label_dateOfBirth->setText(ui.label_dateOfBirth->text() + "*");

	if (type == sr::PersonType::PARENT)
	{
		this->setWindowTitle(WindowTitleParent);
		this->ui.label_homeAddress->setText(ui.label_homeAddress->text() + "*");
		this->ui.label_homePhone->setText(ui.label_homePhone->text() + "*");
		this->ui.label_cellPhone->setText(ui.label_cellPhone->text() + "*");
		this->ui.label_emailAddress->setText(ui.label_emailAddress->text() + "*");
	}
	else if (type == sr::PersonType::CHILD)
	{
		this->setWindowTitle(WindowTitleChild);
		this->ui.checkBox_prevAttended->setText(ui.checkBox_prevAttended->text() + "*");
	}
}

void SRCreateUser::Create()
{
	if (!this->personList)
	{
		throw ERROR_CREATE_PARENT_NULL;
	}

	this->paramMissing = false;

	PersonBuilder builder;

	builder.ID(idAssign);
	MakeFirstName(builder);
	MakeLastName(builder);
	MakeDateOfBirth(builder);
	MakeHomeAddress(builder);
	MakeHomePhone(builder);
	MakeCellPhone(builder);
	MakeEmailAddress(builder);
	MakePrevAttended(builder);
	MakePrevLocation(builder);
	MakeYearsAttended(builder);

	if (this->paramMissing)
	{
		QString s("Missing one or more fields(*) to create");

		if(personType == sr::PersonType::PARENT) s += " parent!";
		else if(personType == sr::PersonType::CHILD) s += " child!";

		QMessageBox::information(this, "Error", s);

		return;
	}

	if (personType == sr::PersonType::PARENT)
	{
		this->personList->push_back(builder.Build<Parent>());
	}
	else if(personType == sr::PersonType::CHILD)
	{
		this->personList->push_back(builder.Build<Child>());
	}

	SRCreateUser::idAssign++;
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

	ParamMissing(sr::PersonType::PARENT);
}

void SRCreateUser::MakeLastName(PersonBuilder& builder)
{
	QString lastName = ui.textEdit_lastName->toPlainText().trimmed();
	if (!lastName.isEmpty())
	{
		builder.LastName(std::move(lastName));
		return;
	}

	ParamMissing(sr::PersonType::PARENT);
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
		ParamMissing(sr::PersonType::PARENT);
		return;
	}

	builder.HomeAddress(std::move(s));
}

void SRCreateUser::MakeHomePhone(PersonBuilder& builder)
{
	QString s = ui.textEdit_homePhone->toPlainText().trimmed();

	if (s.isEmpty())
	{
		ParamMissing(sr::PersonType::PARENT);
		return;
	}

	builder.HomePhone(std::move(s));
}

void SRCreateUser::MakeCellPhone(PersonBuilder& builder)
{
	QString s = ui.textEdit_cellPhone->toPlainText().trimmed();

	if (s.isEmpty())
	{
		ParamMissing(sr::PersonType::PARENT);
		return;
	}

	builder.CellPhone(std::move(s));
}

void SRCreateUser::MakeEmailAddress(PersonBuilder& builder)
{
	QString email = ui.textEdit_emailAddress->toPlainText().trimmed();
	
	if (email.isEmpty())
	{
		ParamMissing(sr::PersonType::PARENT);
		return;
	}

	builder.EmailAddress(std::move(email));
}

void SRCreateUser::MakePrevAttended(PersonBuilder& builder)
{
	Qt::CheckState checked = ui.checkBox_prevAttended->checkState();

	if (checked == Qt::Checked) builder.PrevAttended(true);
	else if (checked == Qt::Unchecked) builder.PrevAttended(false);
}

void SRCreateUser::MakePrevLocation(PersonBuilder& builder)
{
	if (ui.textEdit_prevLocation->isEnabled())
	{
		QString s = ui.textEdit_prevLocation->toPlainText().trimmed();

		if (s.isEmpty())
		{
			ParamMissing(sr::PersonType::CHILD);
			return;
		}

		builder.PrevLocation(s);
	}

	builder.PrevLocation(QString());
}

void SRCreateUser::MakeYearsAttended(PersonBuilder& builder)
{
	if (ui.textEdit_yearsAttended->isEnabled())
	{
		QString s = ui.textEdit_yearsAttended->toPlainText().trimmed();

		if (s.isEmpty())
		{
			ParamMissing(sr::PersonType::CHILD);
			return;
		}

		builder.YearsAttended(s.toUInt());
	}

	builder.YearsAttended(0);
}

void SRCreateUser::ParamMissing(sr::PersonType type)
{
	if (this->personType == type)
	{
		this->paramMissing = true;
	}
}

void SRCreateUser::HandlePrevAttended(int state)
{
	if (state == Qt::Checked)
	{
		this->ui.textEdit_prevLocation->setEnabled(false);
		this->ui.textEdit_yearsAttended->setEnabled(false);
	}
	else if (state == Qt::Unchecked)
	{
		this->ui.textEdit_prevLocation->setEnabled(true);
		this->ui.textEdit_yearsAttended->setEnabled(true);
	}
}

bool SRCreateUser::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::KeyPress)
	{
		QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
		
		if (keyEvent->key() == Qt::Key_Tab)
		{
			QWidget::focusNextChild();
			return true;
		}
	}

	return false;
}
