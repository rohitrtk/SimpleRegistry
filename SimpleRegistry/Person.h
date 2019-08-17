#ifndef PERSON_H_
#define PERSON_H_

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
class EmergencyContact;

using sr_int = unsigned char;

class PersonBuilder
{
	friend class Person;
public:
	PersonBuilder() {}
	virtual ~PersonBuilder() {}

	std::shared_ptr<Person> Build();

	virtual PersonBuilder* FirstName(std::string firstName);
	virtual PersonBuilder* LastName(std::string lastName);
	virtual PersonBuilder* DateOfBirth(QDate dateOfBirth);
	virtual PersonBuilder* Age(sr_int age);

private:
	std::unique_ptr<std::string> firstName;
	std::unique_ptr<std::string> lastName;
	std::unique_ptr<QDate> dateOfBirth;
	std::unique_ptr<sr_int> age;
};

class ParentBuilder : public PersonBuilder
{
	friend class Parent;
public:
	std::shared_ptr<Parent> Build();

	virtual ParentBuilder* HomeAddress(std::string homeAddress);
	virtual ParentBuilder* EmailAddress(std::string emailAddress);
	virtual ParentBuilder* HomePhone(std::string homePhone);
	virtual ParentBuilder* CellPhone(std::string cellPhone);

private:
	std::unique_ptr<std::string> homeAddress;
	std::unique_ptr<std::string> emailAddress;
	std::unique_ptr<std::string> homePhone;
	std::unique_ptr<std::string> cellPhone;
};

class ChildBuilder : public PersonBuilder
{
	friend class Child;
public:
	std::shared_ptr<Child> Build();

	virtual ChildBuilder* PreviouslyAttended(bool previouslyAttended);
	virtual ChildBuilder* YearsAttended(sr_int yearsAttended);
	virtual ChildBuilder* PreviousLocation(std::string previousLocation);
	virtual ChildBuilder* Allergies(std::vector<std::string> allergies);

private:
	std::unique_ptr<bool>						previouslyAttended;
	std::unique_ptr<sr_int>						yearsAttended;
	std::unique_ptr<std::string>				previousLocation;
	std::unique_ptr<std::vector<std::string>>	allergies;
};

class Person
{
public:
	Person(PersonBuilder* builder);

	inline const std::string& GetFirstName() const	{ return this->firstName; }
	inline const std::string& GetLastName() const	{ return this->lastName; }
	inline const sr_int& GetAge() const				{ return this->age; }
	inline const QDate& GetDateOfBirth() const 		{ return this->dateOfBirth; }

protected:
	Person() {}

	std::string firstName;
	std::string lastName;
	sr_int age;
	QDate dateOfBirth;
};

class Parent : public Person
{
public:
	Parent(ParentBuilder* parentBuilder);

	inline const std::string& GetEmailAddress()		{ return this->emailAddress; }
	inline const std::string& GetHomePhone()		{ return this->homePhone; }
	inline const std::string& GetCellPhone()		{ return this->cellPhone; }

private:
	std::string emailAddress;
	std::string homePhone;
	std::string cellPhone;

	std::vector<Child> children;
};

class Child : public Person 
{
public:
	Child(ChildBuilder* childBuilder);

private:
	std::vector<Parent> parents;

	bool previouslyAttended;
	sr_int numYearsAttended;
	std::string previousLocation;
	std::vector<std::string> allergies;
	std::vector<std::string> interests;
};

#endif