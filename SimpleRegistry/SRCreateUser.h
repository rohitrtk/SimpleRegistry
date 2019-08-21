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

class PersonBuilder;

enum class FormType
{
	PARENT, CHILD
};

class SRCreateUser : public QWidget
{
	Q_OBJECT

public:
	SRCreateUser(QWidget *parent = Q_NULLPTR);
	~SRCreateUser();

	void SetupParentWindow();
	void SetupChildWindow();

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

	FormType formType;

	const unsigned short int WindowWidth	= 465;
	const unsigned short int WindowHeight	= 400;

	// Label Stuff
	const QString p_homeAddress					= "Home Address";
	const QString p_homePhone					= "Home Phone";
	const QString p_cellPhone					= "Cell Phone";
	const QString p_emailAddress				= "Email Address";
	const QString c_prevLocation				= "Previous Location";
	const QString c_prevAttended				= "Previously Attended";
	const QString c_yearsAttended				= "Years Attended";

	std::unique_ptr<class SRPopUp> popUp;
	std::shared_ptr<sr::_ppl> personList;
	bool paramMissing;

	void MakeFirstName(PersonBuilder& builder);
	void MakeLastName(PersonBuilder& builder);
	void MakeAge(PersonBuilder& builder);
	void MakeDateOfBirth(PersonBuilder& builder);

	void MakeVar1(PersonBuilder& builder);
	void MakeVar2(PersonBuilder& builder);
	void MakeVar3(PersonBuilder& builder);
	void MakeVar4(PersonBuilder& builder);
};

#endif