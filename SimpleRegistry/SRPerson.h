#ifndef SRPERSON_H_
#define SRPERSON_H_

#include <string>
#include <QDate>
#include <vector>
#include <memory>

#define ERROR_PERSON_BUILDER_FIRST_NAME		"NULL FIRST NAME"
#define ERROR_PERSON_BUILDER_LAST_NAME		"NULL LAST NAME"
#define ERROR_PERSON_BUILDER_DOB			"NULL DOB"
#define ERROR_PERSON_BUILDER_AGE			"NULL AGE"

#define ERROR_PARENT_BUILDER_HOME_ADDRESS	"NULL HOME ADDRESS"
#define ERROR_PARENT_BUILDER_EMAIL_ADDRESS	"NULL EMAIL ADDRESS"
#define ERROR_PARENT_BUILDER_HOME_PHONE		"NULL HOME PHONE"
#define ERROR_PARENT_BUILDER_CELL_PHONE		"NULL CELL PHONE"

#define ERROR_CHILD_BUILDER_PREV_ATTENDED	"NULL PREVIOUSLY ATTENDED"
#define ERROR_CHILD_BUILDER_YEARS_ATTENDED	"NULL YEARS ATTENDED"
#define ERROR_CHILD_BUILDER_PREV_LOCATION	"NULL PREVIOUS LOCATION"
#define ERROR_CHILD_BUILDER_ALLERGIES		"NULL ALLERGIES"

class PersonBuilder;
class ParentBuilder;
class ChildBuilder;
class Person;
class Parent;
class Child;

using sr_int = unsigned char;

class PersonBuilder
{
	friend class Person;
	friend class Parent;
public:
	PersonBuilder() {}

	template<typename T>
	T* Build()
	{
		return new T(this);
	}

	PersonBuilder* FirstName(std::string firstName)
	{
		this->firstName = std::make_unique<std::string>(firstName);
		return this;
	}

	PersonBuilder* LastName(std::string lastName)
	{
		this->lastName = std::make_unique<std::string>(lastName);
		return this;
	}

	PersonBuilder* DateOfBirth(QDate dateOfBirth)
	{
		this->dateOfBirth = std::make_unique<QDate>(dateOfBirth);
		return this;
	}

	PersonBuilder* Age(sr_int age)
	{
		this->age = std::make_unique<sr_int>(age);
		return this;
	}

	PersonBuilder* HomeAddress(std::string homeAddress)
	{
		this->homeAddress = std::make_unique<std::string>(homeAddress);
		return this;
	}
	
	PersonBuilder* EmailAddress(std::string emailAddress)
	{
		this->emailAddress = std::make_unique<std::string>(emailAddress);
		return this;
	}
	
	PersonBuilder* HomePhone(std::string homePhone)
	{
		this->homePhone = std::make_unique<std::string>(homePhone);
		return this;
	}
	
	PersonBuilder* CellPhone(std::string cellPhone)
	{
		this->cellPhone = std::make_unique<std::string>(cellPhone);
		return this;
	}

private:
	std::unique_ptr<std::string>	firstName;
	std::unique_ptr<std::string>	lastName;
	std::unique_ptr<sr_int>			age;
	std::unique_ptr<QDate>			dateOfBirth;
	std::unique_ptr<std::string>	homeAddress;
	std::unique_ptr<std::string>	homePhone;
	std::unique_ptr<std::string>	cellPhone;
	std::unique_ptr<std::string>	emailAddress;
};

class Person
{
public:
	Person(PersonBuilder* builder);

	inline std::string GetFirstName()   const	{ return *this->firstName; }
	inline std::string GetLastName()    const	{ return *this->lastName; }
	inline sr_int      GetAge()         const	{ return *this->age; }
	inline QDate       GetDateOfBirth() const 	{ return *this->dateOfBirth; }

	void PrintInfo();

protected:
	std::unique_ptr<std::string> firstName;
	std::unique_ptr<std::string> lastName;
	std::unique_ptr<sr_int>		 age;
	std::unique_ptr<QDate>		 dateOfBirth;
};

class Parent : public Person
{
public:
	Parent(PersonBuilder* parentBuilder);

	inline std::string GetEmailAddress()	const { return *this->emailAddress; }
	inline std::string GetHomePhone()		const { return *this->homePhone; }
	inline std::string GetCellPhone()		const { return *this->cellPhone; }
	inline std::string GetHomeAddress()		const { return *this->homeAddress; }

private:
	std::unique_ptr<std::string> homeAddress;
	std::unique_ptr<std::string> homePhone;
	std::unique_ptr<std::string> cellPhone;
	std::unique_ptr<std::string> emailAddress;
};

#endif