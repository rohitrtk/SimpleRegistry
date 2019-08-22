#ifndef SRCreateUser_H_
#define SRCreateUser_H_

#include <QWidget>
#include "ui_SRCreateUser.h"
#include "SRConsants.h"
#include <QString>
#include <QDate>
#include <QEvent>
#include <sstream>
#include <string>
#include <memory>

class PersonBuilder;
class SimpleRegistry;

enum class PersonType
{
	PARENT, CHILD
};

class SRCreateUser : public QWidget
{
	Q_OBJECT

public:
	SRCreateUser(QWidget *parent = Q_NULLPTR);
	~SRCreateUser();

	void SetupParentWindow(SimpleRegistry* mainWindow);
	void SetupChildWindow(SimpleRegistry* mainWindow);

	inline void SetPersonList(const std::shared_ptr<sr::_ppl>& list) { this->personList = list; }

public slots:
	void Create();
	void Cancel();
	void Clear();

private:
	Ui::SRCreateUser ui;

	SimpleRegistry* mainWindow;

	PersonType personType;

	const unsigned short int WindowWidth	= 465;
	const unsigned short int WindowHeight	= 400;

	const QString WindowTitleParent = "Create New Parent";
	const QString WindowTitleChild  = "Create New Child";

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
	void MakeDateOfBirth(PersonBuilder& builder);

	void MakeVar1(PersonBuilder& builder);
	void MakeVar2(PersonBuilder& builder);
	void MakeVar3(PersonBuilder& builder);
	void MakeVar4(PersonBuilder& builder);
};

const QEvent::Type USER_CREATED_EVENT = static_cast<QEvent::Type>(4747);

class SRUserCreatedEvent : public QEvent
{
public:
	SRUserCreatedEvent(const PersonType& personType) :
		QEvent(USER_CREATED_EVENT),
		personType(personType) {}

	inline const PersonType GetPersonType() const {	return this->personType; }

private:
	PersonType personType;
};

#endif