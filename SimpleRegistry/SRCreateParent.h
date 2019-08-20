#ifndef SRCREATEPARENT_H_
#define SRCREATEPARENT_H_

#include <QWidget>
#include "ui_SRCreateParent.h"
#include "SRConsants.h"
#include "SRPerson.h"
#include <string>
#include <QString>
#include <QDate>

class SRCreateParent : public QWidget
{
	Q_OBJECT

public:
	SRCreateParent(QWidget *parent = Q_NULLPTR);
	~SRCreateParent();

	inline void SetPersonList(sr_ppl* list)
	{
		this->personList = list;
	}

public slots:
	void CreateParent();
	void CancelParent();

private:
	Ui::SRCreateParent ui;

	sr_ppl* personList;

	inline void MakeFirstName(PersonBuilder& builder)
	{
		QString firstName = ui.textEdit_firstName->toPlainText().trimmed();
		if (!firstName.isEmpty())
		{
			builder.FirstName(std::move(firstName.toStdString()));
		}
	}

	inline void MakeLastName(PersonBuilder& builder)
	{
		QString lastName = ui.textEdit_lastName->toPlainText().trimmed();
		if (!lastName.isEmpty())
		{
			builder.LastName(std::move(lastName.toStdString()));
		}
	}

	inline void MakeAge(PersonBuilder& builder)
	{
		// *
		QString age_str = ui.textEdit_age->toPlainText().trimmed();
		if (!age_str.isEmpty())
		{
			builder.Age(age_str.toInt());
		}
	}

	inline void MakeDateOfBirth(PersonBuilder& builder)
	{
		// *
		builder.DateOfBirth(QDate(1,1,1));
	}

	inline void MakeHomeAddress(PersonBuilder& builder)
	{
		QString ha = ui.textEdit_homeAddress->toPlainText().trimmed();
		if (!ha.isEmpty())
		{
			builder.HomeAddress(std::move(ha.toStdString()));
		}
	}

	inline void MakeHomePhone(PersonBuilder& builder)
	{
		QString homePhone = ui.textEdit_homePhone->toPlainText().trimmed();
		if (!homePhone.isEmpty())
		{
			builder.HomePhone(std::move(homePhone.toStdString()));
		}
	}

	inline void MakeCellPhone(PersonBuilder& builder)
	{
		QString cellPhone = ui.textEdit_cellPhone->toPlainText().trimmed();
		if (!cellPhone.isEmpty())
		{
			builder.CellPhone(std::move(cellPhone.toStdString()));
		}
	}

	inline void MakeEmail(PersonBuilder& builder)
	{
		QString email = ui.textEdit_emailAddress->toPlainText().trimmed();
		if (!email.isEmpty())
		{
			builder.EmailAddress(std::move(email.toStdString()));
		}
	}
};

#endif