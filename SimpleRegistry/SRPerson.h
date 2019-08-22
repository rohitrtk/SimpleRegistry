#ifndef SRPERSON_H_
#define SRPERSON_H_

#include "SRConsants.h"
#include <string>
#include <vector>
#include <memory>
#include <QDate>

class PersonBuilder;
class Person;
class Parent;
class Child;

class PersonBuilder
{
	friend class Person;
	friend class Parent;
	friend class Child;
public:

	template<typename T>
	std::unique_ptr<T> Build()
	{
		return std::make_unique<T>(this);
	}

	PersonBuilder* ID(sr::_int id);

	PersonBuilder* FirstName(QString firstName);
	PersonBuilder* LastName(QString lastName);
	PersonBuilder* DateOfBirth(QDate dateOfBirth);
	PersonBuilder* Age(sr::_int age);

	PersonBuilder* HomeAddress(QString homeAddress);
	PersonBuilder* EmailAddress(QString emailAddress);
	PersonBuilder* HomePhone(QString homePhone);
	PersonBuilder* CellPhone(QString cellPhone);

	PersonBuilder* PrevAttended(bool prevAttended);
	PersonBuilder* YearsAttended(sr::_int yearsAttended);
	PersonBuilder* PrevLocation(QString prevLocation);
	PersonBuilder* Allergies(sr::_list allergies);
	PersonBuilder* Interests(sr::_list interests);
	PersonBuilder* Group(sr::Group group);

private:
	std::unique_ptr<sr::_int>	id;
	
	std::unique_ptr<QString>	firstName;
	std::unique_ptr<QString>	lastName;
	std::unique_ptr<QDate>		dateOfBirth;
	std::unique_ptr<sr::_int>	age;

	std::unique_ptr<QString>	homeAddress;
	std::unique_ptr<QString>	homePhone;
	std::unique_ptr<QString>	cellPhone;
	std::unique_ptr<QString>	emailAddress;

	std::unique_ptr<bool>		prevAttended;
	std::unique_ptr<QString>	prevLocation;
	std::unique_ptr<sr::_int>	yearsAttended;
	std::unique_ptr<sr::_list>	allergies;
	std::unique_ptr<sr::_list>	interests;
	std::unique_ptr<sr::Group>	group;
};

class Person
{
public:
	Person(PersonBuilder* builder);

	inline const sr::_int&	GetID()				const { return *this->id; }
	inline const QString&	GetFirstName()		const { return *this->firstName; }
	inline const QString&	GetLastName()		const { return *this->lastName; }
	inline const sr::_int&	GetAge()			const { return *this->age; }
	inline const QDate&		GetDateOfBirth()	const { return *this->dateOfBirth; }

	virtual QString GetInfo();

protected:
	std::unique_ptr<sr::_int>	id;
	std::unique_ptr<QString>	firstName;
	std::unique_ptr<QString>	lastName;
	std::unique_ptr<sr::_int>	age;
	std::unique_ptr<QDate>		dateOfBirth;
};

class Parent : public Person
{
public:
	Parent(PersonBuilder* builder);

	inline const QString& GetEmailAddress()	const { return *this->emailAddress; }
	inline const QString& GetHomePhone()	const { return *this->homePhone; }
	inline const QString& GetCellPhone()	const { return *this->cellPhone; }
	inline const QString& GetHomeAddress()	const { return *this->homeAddress; }

	virtual QString GetInfo() override;

private:
	std::unique_ptr<QString> homeAddress;
	std::unique_ptr<QString> homePhone;
	std::unique_ptr<QString> cellPhone;
	std::unique_ptr<QString> emailAddress;

	std::unique_ptr<sr::_list> children;
};

class Child : public Person
{
public:
	Child(PersonBuilder* builder);

	inline const QString&	GetPrevLocation()	const { return *this->prevLocation; }
	inline const bool&		GetPrevAttended()	const { return *this->prevAttended; }
	inline const sr::_int&	GetYearsAttended()	const { return *this->yearsAttended; }
	inline const sr::_list& GetAllergies()		const { return *this->allergies; }
	inline const sr::_list& GetInterests()		const { return *this->interests; }
	inline const sr::Group& GetGroup()			const { return *this->group; }

	virtual QString GetInfo() override;

private:
	std::unique_ptr<QString>	prevLocation;
	std::unique_ptr<bool>		prevAttended;
	std::unique_ptr<sr::_int>	yearsAttended;
	std::unique_ptr<sr::_list>	allergies;
	std::unique_ptr<sr::_list>	interests;

	std::unique_ptr<sr::_list> guardians;
	std::unique_ptr<sr::Group> group;
};

#endif