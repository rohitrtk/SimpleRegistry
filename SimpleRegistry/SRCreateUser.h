#ifndef SRCreateUser_H_
#define SRCreateUser_H_

#include <QWidget>
#include "ui_SRCreateUser.h"
#include "SRConsants.h"
#include <QString>
#include <QEvent>
#include <sstream>
#include <string>
#include <memory>
#include <QCheckBox>
#include "SRPerson.h"

class PersonBuilder;
class SimpleRegistry;

enum class PersonType
{
	PARENT, CHILD, UNDEFINED
};

class SRCreateUser : public QWidget
{
	Q_OBJECT

public:
	SRCreateUser(QWidget *parent = Q_NULLPTR);
	~SRCreateUser();

	void SetupWindow(SimpleRegistry* mainWindow, PersonType type = PersonType::PARENT);

	inline void SetPersonList(std::vector<std::unique_ptr<Person>>& list) { this->personList = &list; }

public slots:
	void Create();
	void Cancel();
	void Clear();
	void HandlePrevAttended(int state);

private:
	Ui::SRCreateUser ui;

	SimpleRegistry* mainWindow;

	PersonType personType;

	const unsigned short int WindowWidth	= 465;
	const unsigned short int WindowHeight	= 400;

	const QString WindowTitleParent = "Create New Parent";
	const QString WindowTitleChild  = "Create New Child";
	
	std::vector<std::unique_ptr<Person>>* personList;
	bool paramMissing;
	
	void MakeFirstName		(PersonBuilder& builder);
	void MakeLastName		(PersonBuilder& builder);
	void MakeDateOfBirth	(PersonBuilder& builder);

	void MakeHomeAddress	(PersonBuilder& builder);
	void MakeHomePhone		(PersonBuilder& builder);
	void MakeCellPhone		(PersonBuilder& builder);
	void MakeEmailAddress	(PersonBuilder& builder);
	
	void MakePrevAttended	(PersonBuilder& builder);
	void MakePrevLocation	(PersonBuilder& builder);
	void MakeYearsAttended	(PersonBuilder& builder);

	void ParamMissing(PersonType type);
};

const QEvent::Type USER_CREATED_EVENT = static_cast<QEvent::Type>(4747);

class SRUserCreatedEvent : public QEvent
{
public:
	SRUserCreatedEvent(const PersonType& personType) :
		QEvent(USER_CREATED_EVENT),
		personType(personType) {}

	inline const PersonType GetPersonType() const { return this->personType; }

private:
	PersonType personType;
};

#endif