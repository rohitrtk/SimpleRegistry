#ifndef SRPERSON_H_
#define SRPERSON_H_

#include "SRConsants.h"
#include <array>
#include <memory>
#include <QDate>
#include <QString>

#define CHECK_NULL_STRING(string) ((!string) ? "" : *string)

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
	PersonBuilder<T>* FirstName			(const QString& firstName);
	PersonBuilder<T>* LastName			(const QString& lastName);
	PersonBuilder<T>* DateOfBirth		(const QDate& dateOfBirth);
	PersonBuilder<T>* Gender			(const QString& gender);
	PersonBuilder<T>* HomeAddress		(const QString& homeAddress);
	PersonBuilder<T>* EmailAddress		(const QString& emailAddress);
	PersonBuilder<T>* PrimaryPhone		(const QString& primaryPhone);
	PersonBuilder<T>* SecondaryPhone	(const QString& secondaryPhone);
	PersonBuilder<T>* PrevAttended		(bool prevAttended);
	PersonBuilder<T>* Medical			(const QString& allergies);
	PersonBuilder<T>* Group				(const sr::Group&& group);
	PersonBuilder<T>* Parents			(const QString& parents);
	PersonBuilder<T>* Children			(const QString& children);

private:
	
	std::unique_ptr<QString>	firstName;
	std::unique_ptr<QString>	lastName;
	std::unique_ptr<QString>	gender;
	std::unique_ptr<QDate>		dateOfBirth;
	std::unique_ptr<qint16>		age;
	std::unique_ptr<qint16>		age31;
	std::unique_ptr<sr::Group>	group;
	std::unique_ptr<QString>	parents;
	std::unique_ptr<QString>	relation;
	std::unique_ptr<QString>	homeAddress;
	std::unique_ptr<QString>	primaryPhone;
	std::unique_ptr<QString>	secondaryPhone;
	std::unique_ptr<QString>	emailAddress;
	std::unique_ptr<bool>		prevAttended;
	std::unique_ptr<QString>	medical;

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
PersonBuilder<T>* PersonBuilder<T>::PrimaryPhone(const QString& primaryPhone)
{
	this->primaryPhone = std::make_unique<QString>(primaryPhone);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::SecondaryPhone(const QString& secondaryPhone)
{
	this->secondaryPhone = std::make_unique<QString>(secondaryPhone);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::PrevAttended(bool prevAttended)
{
	this->prevAttended = std::make_unique<bool>(prevAttended);
	return this;
}

template <class T>
PersonBuilder<T>* PersonBuilder<T>::Medical(const QString& medical)
{
	this->medical = std::make_unique<QString>(medical);
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

const QString dobFormat = "yyyy-M-d";

class Person
{
public:
	Person() = delete;
	Person(PersonBuilder<Parent>* personBuilder);
	Person(PersonBuilder<Child>* personBuilder);
	virtual ~Person() = 0;

	inline const QString&			GetFirstName()		const { return *this->firstName; }
	inline const QString&			GetLastName()		const { return *this->lastName; }
	inline const qint16&			GetAge()			const { return *this->age; }
	inline const QDate&				GetDateOfBirth()	const { return *this->dateOfBirth; }
	inline const QString&			GetGender()			const { return *this->gender; }

	inline const QString&			GetHomeAddress()	const { return *this->homeAddress; }
	inline const QString&			GetPrimaryPhone()	const { return *this->primaryPhone; }
	inline const QString&			GetSecondaryPhone()	const { return *this->secondaryPhone; }
	inline const QString&			GetEmailAddress()	const { return *this->emailAddress; }

	inline const bool&				GetPrevAttended()	const { return *this->prevAttended; }
	inline const QString&&			GetPrevAttendedS()	const { return (*this->prevAttended) ? "Yes" : "No"; }
	inline const QString&			GetMedical()		const { return *this->medical; }

	inline const sr::Group&			GetGroup()			const { return *this->group; }
	
	inline const QString&			GetParents()		const { return *this->parents; }
	inline const QString&			GetChildren()		const { return *this->children; }

	QString							GetGroupAsString()	const;

	const std::array<QString, 17>&	GetValuesAsQStrings() const { return this->values; }

	friend std::ostream& operator << (std::ostream& stream, const Person& person);

protected:
	std::unique_ptr<QString>		firstName;
	std::unique_ptr<QString>		lastName;
	std::unique_ptr<QDate>			dateOfBirth;
	std::unique_ptr<QString>		gender;

	std::unique_ptr<QString>		homeAddress;
	std::unique_ptr<QString>		primaryPhone;
	std::unique_ptr<QString>		secondaryPhone;
	std::unique_ptr<QString>		emailAddress;

	std::unique_ptr<bool>			prevAttended;
	std::unique_ptr<QString>		medical;

	std::unique_ptr<QString>		parents;
	std::unique_ptr<QString>		children;

	std::unique_ptr<qint16>			age;
	std::unique_ptr<qint16>			age31;
	std::unique_ptr<sr::Group>		group;

	std::array<QString, 17> values;

private:
	qint16 AssignAge()		const;
	qint16 AssignAge31()	const;
	sr::Group AssignGroup() const;
};

class Parent : public Person
{
public:
	Parent() = delete;
	Parent(PersonBuilder<Parent>* builder);
	~Parent() override {}
};

class Child : public Person
{
public:
	Child() = delete;
	Child(PersonBuilder<Child>* builder);
	~Child() override {}
};

#endif