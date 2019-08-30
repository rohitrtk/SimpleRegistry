#ifndef SRPERSON_H_
#define SRPERSON_H_

#include "SRConsants.h"
#include <string>
#include <vector>
#include <memory>
#include <map>

class PersonBuilder;
class Person;
class Parent;
class Child;
class QDate;

class PersonBuilder
{
	friend class Person;
	friend class Parent;
	friend class Child;
public:
	PersonBuilder() {}
	~PersonBuilder() {}

	template<typename T>
	std::unique_ptr<T> Build()
	{
		return std::make_unique<T>(this);
	}

	PersonBuilder* ID(qint16 id);

	PersonBuilder* FirstName	(const QString& firstName);
	PersonBuilder* LastName		(const QString& lastName);
	PersonBuilder* DateOfBirth	(const QDate& dateOfBirth);
	PersonBuilder* Gender		(const QString& gender);

	PersonBuilder* HomeAddress	(const QString& homeAddress);
	PersonBuilder* EmailAddress	(const QString& emailAddress);
	PersonBuilder* HomePhone	(const QString& homePhone);
	PersonBuilder* CellPhone	(const QString& cellPhone);

	PersonBuilder* PrevAttended	(bool prevAttended);
	PersonBuilder* YearsAttended(const qint16& yearsAttended);
	PersonBuilder* PrevLocation	(const QString& prevLocation);

	PersonBuilder* Allergies	(const QString& allergies);
	PersonBuilder* Group		(const sr::Group&& group);

	PersonBuilder* Parents		(const QString& parents);
	PersonBuilder* Children		(const QString& children);

private:
	std::unique_ptr<qint16>	id;
	
	std::unique_ptr<QString>	firstName;
	std::unique_ptr<QString>	lastName;
	std::unique_ptr<QDate>		dateOfBirth;
	std::unique_ptr<qint16>		age;
	std::unique_ptr<QString>	gender;

	std::unique_ptr<QString>	homeAddress;
	std::unique_ptr<QString>	homePhone;
	std::unique_ptr<QString>	cellPhone;
	std::unique_ptr<QString>	emailAddress;

	std::unique_ptr<bool>		prevAttended;
	std::unique_ptr<QString>	prevLocation;
	std::unique_ptr<qint16>		yearsAttended;
	std::unique_ptr<QString>	allergies;
	std::unique_ptr<sr::Group>	group;

	std::unique_ptr<QString>	parents;
	std::unique_ptr<QString>	children;
};

class Person
{
public:
	Person() = delete;
	Person(PersonBuilder* builder);
	virtual ~Person() {}

	inline const qint16&			GetID()				const { return *this->id; }
	inline const QString&			GetFirstName()		const { return *this->firstName; }
	inline const QString&			GetLastName()		const { return *this->lastName; }
	inline const qint16&			GetAge()			const { return *this->age; }
	inline const QDate&				GetDateOfBirth()	const { return *this->dateOfBirth; }
	inline const sr::PersonType&	GetPersonType()		const { return *this->personType; }
	inline const QString&			GetGender()			const { return *this->gender; }

	inline const QString&			GetHomeAddress()	const { return *this->homeAddress; }
	inline const QString&			GetHomePhone()		const { return *this->homePhone; }
	inline const QString&			GetCellPhone()		const { return *this->cellPhone; }
	inline const QString&			GetEmailAddress()	const { return *this->emailAddress; }

	inline const QString&			GetPrevLocation()	const { return *this->prevLocation; }
	inline const bool&				GetPrevAttended()	const { return *this->prevAttended; }
	inline Qt::CheckState			GetPrevAttendedS()	const { return (*this->prevAttended) ? Qt::Checked : Qt::Unchecked; }
	inline const qint16&			GetYearsAttended()	const { return *this->yearsAttended; }
	inline const QString&			GetAllergies()		const { return *this->allergies; }

	inline const sr::Group&			GetGroup()			const { return *this->group; }
	
	inline const QString&			GetParents()		const { return *this->parents; }
	inline const QString&			GetChildren()		const { return *this->children; }

	QString							GetGroupAsString()	const;

	friend std::ostream& operator << (std::ostream& stream, const Person& person);

protected:
	std::unique_ptr<qint16>			id;
	std::unique_ptr<QString>		firstName;
	std::unique_ptr<QString>		lastName;
	std::unique_ptr<QDate>			dateOfBirth;
	std::unique_ptr<QString>		gender;

	std::unique_ptr<QString>		homeAddress;
	std::unique_ptr<QString>		homePhone;
	std::unique_ptr<QString>		cellPhone;
	std::unique_ptr<QString>		emailAddress;

	std::unique_ptr<QString>		prevLocation;
	std::unique_ptr<bool>			prevAttended;
	std::unique_ptr<qint16>			yearsAttended;
	std::unique_ptr<QString>		allergies;

	std::unique_ptr<QString>		parents;
	std::unique_ptr<QString>		children;

	std::unique_ptr<qint16>			age;
	std::unique_ptr<sr::Group>		group;
	std::unique_ptr<sr::PersonType> personType;

private:
	qint16 AssignAge() const;
	sr::Group AssignGroup() const;
};

class Parent : public Person
{
public:
	Parent() = delete;
	Parent(PersonBuilder* builder);
};

class Child : public Person
{
public:
	Child() = delete;
	Child(PersonBuilder* builder);
};

#endif