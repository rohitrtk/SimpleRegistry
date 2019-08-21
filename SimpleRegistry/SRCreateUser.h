#ifndef SRCreateUser_H_
#define SRCreateUser_H_

#include <QWidget>
#include "ui_SRCreateUser.h"
#include "SRConsants.h"
#include <QString>
#include <QDate>
#include <sstream>
#include <string>
#include <memory>

class SRCreateUser : public QWidget
{
	Q_OBJECT

public:
	SRCreateUser(QWidget *parent = Q_NULLPTR);
	~SRCreateUser();

	inline void SetPersonList(std::shared_ptr<sr::_ppl> list)
	{
		this->personList = list;
	}

public slots:
	void Create();
	void Cancel();
	void Clear();

private:
	Ui::SRCreateUser ui;

	std::unique_ptr<class SRPopUp> popUp;
	std::shared_ptr<sr::_ppl> personList;
	bool paramMissing;

	void MakeFirstName(class PersonBuilder& builder);
	void MakeLastName(class PersonBuilder& builder);
	void MakeAge(class PersonBuilder& builder);
	void MakeDateOfBirth(class PersonBuilder& builder);
	void MakeHomeAddress(class PersonBuilder& builder);
	void MakeHomePhone(class PersonBuilder& builder);
	void MakeCellPhone(class PersonBuilder& builder);
	void MakeEmail(class PersonBuilder& builder);
};

#endif