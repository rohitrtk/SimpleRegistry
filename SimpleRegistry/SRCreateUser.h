#ifndef SRCreateUser_H_
#define SRCreateUser_H_

#include <QWidget>
#include "SRConsants.h"
#include "SRPerson.h"
#include <sstream>
#include <string>
#include <memory>

class SimpleRegistry;
class SRUserCreatedEventFilter;
class QString;
class QEvent;
class QCheckBox;

class SRCreateUser
{
public:
	SRCreateUser() {}
	SRCreateUser(SimpleRegistry* mainWindow) : 
		mainWindow(mainWindow), personType(sr::PersonType::UNDEFINED), paramMissing(false) {};
	~SRCreateUser() {};

public slots:
	virtual void Create() = 0;
	virtual void Cancel() = 0;
	virtual void Clear()  = 0;

protected:

	SimpleRegistry* mainWindow;

	sr::PersonType personType;
	
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
