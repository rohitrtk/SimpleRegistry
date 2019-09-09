#ifndef SRCreateUser_H_
#define SRCreateUser_H_

#include <QWidget>

#include <sstream>
#include <string>
#include <memory>

#include <QEvent>

class SimpleRegistry;
class Person;

constexpr auto WindowTitle_CreateChild		= "Create Child";
constexpr auto WindowTitle_CreateParent		= "Create Parent";

constexpr auto ComboBoxGender_Male			= "Male";
constexpr auto ComboBoxGender_Female		= "Female";
constexpr auto ComboBoxRelation_Parents		= "Parents";
constexpr auto ComboBoxRelation_Mother		= "Mother";
constexpr auto ComboBoxRelation_Father		= "Father";
constexpr auto ComboBoxRelation_Guardian	= "Guardian";

class SRCreateUser
{
public:
	SRCreateUser() {}
	SRCreateUser(SimpleRegistry* mainWindow) : 
		mainWindow(mainWindow), paramMissing(false) {};
	~SRCreateUser() {}

public slots:
	virtual void Create() = 0;
	virtual void Cancel() = 0;
	virtual void Clear()  = 0;

protected:
	SimpleRegistry* mainWindow;
	
	bool paramMissing;
};

const QEvent::Type USER_CREATED_EVENT = static_cast<QEvent::Type>(4747);

class SRUserCreatedEvent : public QEvent
{
public:
	SRUserCreatedEvent(const Person& person) :
		QEvent(USER_CREATED_EVENT),
		person(person) {}

	inline const Person& GetPerson() const { return this->person; }

private:
	const Person& person;
};

#endif
