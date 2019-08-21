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
	PersonBuilder() {}

	template<typename T>
	std::unique_ptr<T> Build()
	{
		return std::make_unique<T>(this);
	}

	PersonBuilder* ID(sr::_int id);

	PersonBuilder* FirstName(std::string firstName);
	PersonBuilder* LastName(std::string lastName);
	PersonBuilder* DateOfBirth(QDate dateOfBirth);
	PersonBuilder* Age(sr::_int age);

	PersonBuilder* HomeAddress(std::string homeAddress);
	PersonBuilder* EmailAddress(std::string emailAddress);
	PersonBuilder* HomePhone(std::string homePhone);
	PersonBuilder* CellPhone(std::string cellPhone);

	PersonBuilder* PrevAttended(bool prevAttended);
	PersonBuilder* YearsAttended(sr::_int yearsAttended);
	PersonBuilder* PrevLocation(std::string prevLocation);
	PersonBuilder* Allergies(sr::_list allergies);
	PersonBuilder* Interests(sr::_list interests);
	PersonBuilder* Group(sr::Group group);

private:
	std::unique_ptr<sr::_int>		id;
	
	std::unique_ptr<std::string>	firstName;
	std::unique_ptr<std::string>	lastName;
	std::unique_ptr<sr::_int>		age;
	std::unique_ptr<QDate>			dateOfBirth;

	std::unique_ptr<std::string>	homeAddress;
	std::unique_ptr<std::string>	homePhone;
	std::unique_ptr<std::string>	cellPhone;
	std::unique_ptr<std::string>	emailAddress;

	std::unique_ptr<std::string>	prevLocation;
	std::unique_ptr<bool>			prevAttended;
	std::unique_ptr<sr::_int>		yearsAttended;
	std::unique_ptr<sr::_list>		allergies;
	std::unique_ptr<sr::_list>		interests;
	std::unique_ptr<sr::Group>		group;
};

class Person
{
public:
	Person(PersonBuilder* builder);

	inline const sr::_int&	  GetID()		   const { return *this->id; }
	inline const std::string& GetFirstName()   const { return *this->firstName; }
	inline const std::string& GetLastName()    const { return *this->lastName; }
	inline const sr::_int&	  GetAge()         const { return *this->age; }
	inline const QDate&       GetDateOfBirth() const { return *this->dateOfBirth; }

	virtual QString GetInfo();

protected:
	std::unique_ptr<sr::_int>		 id;
	std::unique_ptr<std::string> firstName;
	std::unique_ptr<std::string> lastName;
	std::unique_ptr<sr::_int>		 age;
	std::unique_ptr<QDate>		 dateOfBirth;
};

class Parent : public Person
{
public:
	Parent(PersonBuilder* builder);

	inline const std::string& GetEmailAddress()	const { return *this->emailAddress; }
	inline const std::string& GetHomePhone()	const { return *this->homePhone; }
	inline const std::string& GetCellPhone()	const { return *this->cellPhone; }
	inline const std::string& GetHomeAddress()	const { return *this->homeAddress; }

	virtual QString GetInfo() override;

private:
	std::unique_ptr<std::string> homeAddress;
	std::unique_ptr<std::string> homePhone;
	std::unique_ptr<std::string> cellPhone;
	std::unique_ptr<std::string> emailAddress;

	std::unique_ptr<sr::_list> children;
};

class Child : public Person
{
public:
	Child(PersonBuilder* builder);

	inline const std::string& GetPrevLocation()	const { return *this->prevLocation; }
	inline const bool& GetPrevAttended()		const { return *this->prevAttended; }
	inline const sr::_int& GetYearsAttended()	const { return *this->yearsAttended; }
	inline const sr::_list& GetAllergies()		const { return *this->allergies; }
	inline const sr::_list& GetInterests()		const { return *this->interests; }
	inline const sr::Group& GetGroup()			const { return *this->group; }

	virtual QString GetInfo() override;

private:
	std::unique_ptr<std::string>	prevLocation;
	std::unique_ptr<bool>			prevAttended;
	std::unique_ptr<sr::_int>		yearsAttended;
	std::unique_ptr<sr::_list>		allergies;
	std::unique_ptr<sr::_list>		interests;

	std::unique_ptr<sr::_list> guardians;
	std::unique_ptr<sr::Group> group;
};

#endif