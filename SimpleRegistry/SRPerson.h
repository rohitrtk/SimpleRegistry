#ifndef SRPERSON_H_
#define SRPERSON_H_

#include "SRConsants.h"
#include <vector>
#include <memory>
#include <map>
#include <QDate>
#include <QString>

class Person;
class Parent;
class Child;

template <class T>
class PersonBuilder
{
	friend class Person;
	friend class Parent;
	friend class Child;
public:
	PersonBuilder() {}
	~PersonBuilder() {}
	
	std::unique_ptr<T> Build();
	PersonBuilder<T>* FirstName(const QString& firstName);
	PersonBuilder<T>* LastName(const QString& lastName);
	PersonBuilder<T>* DateOfBirth(const QDate& dateOfBirth);
	PersonBuilder<T>* Gender(const QString& gender);
	PersonBuilder<T>* HomeAddress(const QString& homeAddress);
	PersonBuilder<T>* EmailAddress(const QString& emailAddress);
	PersonBuilder<T>* HomePhone(const QString& homePhone);
	PersonBuilder<T>* CellPhone(const QString& cellPhone);
	PersonBuilder<T>* PrevAttended(bool prevAttended);
	PersonBuilder<T>* YearsAttended(const qint16& yearsAttended);
	PersonBuilder<T>* PrevLocation(const QString& prevLocation);
	PersonBuilder<T>* Allergies(const QString& allergies);
	PersonBuilder<T>* Group(const sr::Group&& group);
	PersonBuilder<T>* Parents(const QString& parents);
	PersonBuilder<T>* Children(const QString& children);

private:
	
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

template <class T>
std::unique_ptr<T> PersonBuilder<T>::Build()
{
	return std::make_unique<T>(this);
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::FirstName(const QString& firstName)
{
	this->firstName = std::make_unique<QString>(firstName);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::LastName(const QString& lastName)
{
	this->lastName = std::make_unique<QString>(lastName);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::DateOfBirth(const QDate& dateOfBirth)
{
	this->dateOfBirth = std::make_unique<QDate>(dateOfBirth);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::Gender(const QString& gender)
{
	this->gender = std::make_unique<QString>(gender);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::HomeAddress(const QString& homeAddress)
{
	this->homeAddress = std::make_unique<QString>(homeAddress);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::EmailAddress(const QString& emailAddress)
{
	this->emailAddress = std::make_unique<QString>(emailAddress);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::HomePhone(const QString& homePhone)
{
	this->homePhone = std::make_unique<QString>(homePhone);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::CellPhone(const QString& cellPhone)
{
	this->cellPhone = std::make_unique<QString>(cellPhone);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::PrevAttended(bool prevAttended)
{
	this->prevAttended = std::make_unique<bool>(prevAttended);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::YearsAttended(const qint16& yearsAttended)
{
	this->yearsAttended = std::make_unique<qint16>(yearsAttended);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::PrevLocation(const QString& prevLocation)
{
	this->prevLocation = std::make_unique<QString>(prevLocation);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::Allergies(const QString& allergies)
{
	this->allergies = std::make_unique<QString>(allergies);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::Group(const sr::Group&& group)
{
	this->group = std::make_unique<QString>(group);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::Parents(const QString& parents)
{
	this->parents = std::make_unique<QString>(parents);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::Children(const QString& children)
{
	this->children = std::make_unique<QString>(children);
	return this;
}

class Person
{
public:
	Person() = delete;
	Person(PersonBuilder<Parent>* personBuilder);
	Person(PersonBuilder<Child>* personBuilder);
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
	inline QString					GetPrevAttendedS()	const { return (*this->prevAttended) ? "Yes" : "No"; }
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
	Parent(PersonBuilder<Parent>* builder);
};

class Child : public Person
{
public:
	Child() = delete;
	Child(PersonBuilder<Child>* builder);
};

#endif