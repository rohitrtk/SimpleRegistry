#include "SRCreateUser.h"
#include "SRPerson.h"
#include "SimpleRegistry.h"
#include "SRConsants.h"
#include <QTextEdit>
#include <QLayoutItem>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>
#include <QKeyEvent>
#include <QCheckBox>
#include <QEvent>
#include <QString>

/*
void SRCreateUser::SetupWindow(SimpleRegistry* mainWindow, sr::PersonType type)
{
	this->mainWindow = mainWindow;
	this->personType = type;

	this->ui.label_firstName->setText(ui.label_firstName->text() + "*");
	this->ui.label_lastName->setText(ui.label_lastName->text() + "*");
	this->ui.label_dateOfBirth->setText(ui.label_dateOfBirth->text() + "*");

	if (type == sr::PersonType::PARENT)
	{
		this->ui.label_homeAddress->setText(ui.label_homeAddress->text() + "*");
		this->ui.label_homePhone->setText(ui.label_homePhone->text() + "*");
		this->ui.label_cellPhone->setText(ui.label_cellPhone->text() + "*");
		this->ui.label_emailAddress->setText(ui.label_emailAddress->text() + "*");
		this->ui.label_kin->setText("Children");
	}
	else if (type == sr::PersonType::CHILD)
	{
		this->ui.checkBox_prevAttended->setText(ui.checkBox_prevAttended->text() + "*");
		this->ui.label_prevLocation->setText(ui.label_prevLocation->text() + "*");
		this->ui.label_YearsAttended->setText(ui.label_YearsAttended->text() + "*");
		this->ui.label_kin->setText("Parent/Guardian(s)");
	}
}

void SRCreateUser::Create()
{
	this->paramMissing = false;

	PersonBuilder builder;

	MakeFirstName(builder);
	MakeLastName(builder);
	MakeDateOfBirth(builder);
	MakeGender(builder);
	MakeHomeAddress(builder);
	MakeHomePhone(builder);
	MakeCellPhone(builder);
	MakeEmailAddress(builder);
	MakePrevAttended(builder);
	MakePrevLocation(builder);
	MakeYearsAttended(builder);
	MakeAllergies(builder);

	if (personType == sr::PersonType::PARENT) MakeChildren(builder);
	else if (personType == sr::PersonType::CHILD) MakeParents(builder);

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
		this->person = builder.Build<Parent>();
	}
	else if(personType == sr::PersonType::CHILD)
	{
		this->person = builder.Build<Child>();
	}

	SRCreateUser::idAssign++;
	QApplication::postEvent(mainWindow, new SRUserCreatedEvent(*this->person));
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
		else
		{
			QCheckBox* c = dynamic_cast<QCheckBox*>(ui.formLayout->itemAt(i)->widget());
			if (c)
			{
				c->setCheckState(Qt::CheckState::Unchecked);
			}
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

void SRCreateUser::MakeGender(PersonBuilder& builder)
{
	QString gender = ui.comboBox_gender->currentText();
	builder.Gender(gender);
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
		return;
	}

	builder.YearsAttended(-1);
}

void SRCreateUser::MakeAllergies(PersonBuilder& builder)
{
	QString s = ui.textEdit_allergies->toPlainText().trimmed();
	
	builder.Allergies(s);
}

void SRCreateUser::MakeParents(PersonBuilder& builder)
{
	QString s = ui.textEdit_kin->toPlainText().trimmed();

	builder.Parents(s);
}

void SRCreateUser::MakeChildren(PersonBuilder& builder)
{
	QString s = ui.textEdit_kin->toPlainText().trimmed();

	builder.Children(s);
}

void SRCreateUser::ParamMissing()
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
	else if (event->type() == QEvent::Hide)
	{
		this->Clear();
	}

	return false;
}
*/