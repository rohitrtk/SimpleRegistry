#ifndef SRPERSON_H_
#define SRPERSON_H_

#include <string>
#include <QDate>
#include <vector>
#include <memory>
#include "SRConsants.h"

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
	PersonBuilder() {}

	template<typename T>
	std::unique_ptr<T> Build()
	{
		return std::make_unique<T>(this);
	}

	PersonBuilder* ID(sr_int id);

	PersonBuilder* FirstName(std::string firstName);
	PersonBuilder* LastName(std::string lastName);
	PersonBuilder* DateOfBirth(QDate dateOfBirth);
	PersonBuilder* Age(sr_int age);

	PersonBuilder* HomeAddress(std::string homeAddress);
	PersonBuilder* EmailAddress(std::string emailAddress);
	PersonBuilder* HomePhone(std::string homePhone);
	PersonBuilder* CellPhone(std::string cellPhone);

	PersonBuilder* PrevAttended(bool prevAttended);
	PersonBuilder* YearsAttended(sr_int yearsAttended);
	PersonBuilder* PrevLocation(std::string prevLocation);
	PersonBuilder* Allergies(sr_list allergies);
	PersonBuilder* Interests(sr_list interests);

private:
	std::unique_ptr<sr_int>			id;
	
	std::unique_ptr<std::string>	firstName;
	std::unique_ptr<std::string>	lastName;
	std::unique_ptr<sr_int>			age;
	std::unique_ptr<QDate>			dateOfBirth;

	std::unique_ptr<std::string>	homeAddress;
	std::unique_ptr<std::string>	homePhone;
	std::unique_ptr<std::string>	cellPhone;
	std::unique_ptr<std::string>	emailAddress;

	std::unique_ptr<std::string>	prevLocation;
	std::unique_ptr<bool>			prevAttended;
	std::unique_ptr<sr_int>			yearsAttended;
	std::unique_ptr<sr_list>		allergies;
	std::unique_ptr<sr_list>		interests;
};

class Person
{
public:
	Person(PersonBuilder* builder);

	inline sr_int	   GetID()			const	{ return *this->id; }
	inline std::string GetFirstName()   const	{ return *this->firstName; }
	inline std::string GetLastName()    const	{ return *this->lastName; }
	inline sr_int      GetAge()         const	{ return *this->age; }
	inline QDate       GetDateOfBirth() const 	{ return *this->dateOfBirth; }

	virtual QString GetInfo();

protected:
	std::unique_ptr<sr_int>		 id;
	std::unique_ptr<std::string> firstName;
	std::unique_ptr<std::string> lastName;
	std::unique_ptr<sr_int>		 age;
	std::unique_ptr<QDate>		 dateOfBirth;
};

class Parent : public Person
{
public:
	Parent(PersonBuilder* builder);

	inline std::string GetEmailAddress()	const { return *this->emailAddress; }
	inline std::string GetHomePhone()		const { return *this->homePhone; }
	inline std::string GetCellPhone()		const { return *this->cellPhone; }
	inline std::string GetHomeAddress()		const { return *this->homeAddress; }

	virtual QString GetInfo() override;

private:
	std::unique_ptr<std::string> homeAddress;
	std::unique_ptr<std::string> homePhone;
	std::unique_ptr<std::string> cellPhone;
	std::unique_ptr<std::string> emailAddress;

	std::unique_ptr<sr_list> children;
};

class Child : public Person
{
public:
	Child(PersonBuilder* builder);

	inline std::string GetPrevLocation()	const { return *this->prevLocation; }
	inline bool GetPrevAttended()			const { return *this->prevAttended; }
	inline sr_int GetYearsAttended()		const { return *this->yearsAttended; }
	inline sr_list GetAllergies()			const { return *this->allergies; }
	inline sr_list GetInterests()			const { return *this->interests; }

	virtual QString GetInfo() override;

private:
	std::unique_ptr<std::string>	prevLocation;
	std::unique_ptr<bool>			prevAttended;
	std::unique_ptr<sr_int>			yearsAttended;
	std::unique_ptr<sr_list>		allergies;
	std::unique_ptr<sr_list>		interests;

	std::unique_ptr<sr_list> guardians;
};

#endif