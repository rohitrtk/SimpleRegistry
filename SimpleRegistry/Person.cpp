#include "Person.h"

/* ========== PersonBuilder ========== */

std::shared_ptr<Person> PersonBuilder::Build()
{
	if (!firstName)		throw ERROR_PERSON_BUILDER_FIRST_NAME;
	if (!lastName)		throw ERROR_PERSON_BUILDER_LAST_NAME;
	if (!dateOfBirth)	throw ERROR_PERSON_BUILDER_DOB;
	if (!age)			throw ERROR_PERSON_BUILDER_AGE;

	std::shared_ptr<Person> person = std::make_shared<Person>(this);
	return person;
}

PersonBuilder* PersonBuilder::FirstName(std::string firstName)
{ 
	this->firstName = std::make_unique<std::string>(firstName);
	return this;
}

PersonBuilder* PersonBuilder::LastName(std::string lastName) 
{ 
	this->lastName = std::make_unique<std::string>(lastName); 
	return this;
}

PersonBuilder* PersonBuilder::DateOfBirth(QDate dateOfBirth) 
{ 
	this->dateOfBirth = std::make_unique<QDate>(dateOfBirth);
	return this;
}

PersonBuilder* PersonBuilder::Age(sr_int age) 
{ 
	this->age = std::make_unique<sr_int>(age);
	return this;
}

/* ========== ParentBuilder ========== */

std::shared_ptr<Parent> ParentBuilder::Build()
{
	if (!homeAddress)	throw ERROR_PARENT_BUILDER_HOME_ADDRESS;
	if (!emailAddress)	throw ERROR_PARENT_BUILDER_EMAIL_ADDRESS;
	if (!homePhone)		throw ERROR_PARENT_BUILDER_HOME_PHONE;
	if (!cellPhone)		throw ERROR_PARENT_BUILDER_CELL_PHONE;

	Person* p = PersonBuilder::Build().get();
	std::shared_ptr<Parent> parent(static_cast<Parent*>(p));

	return parent;
}

ParentBuilder* ParentBuilder::HomeAddress(std::string homeAddress) 
{ 
	this->homeAddress = std::make_unique<std::string>(homeAddress);
	return this;
}

ParentBuilder* ParentBuilder::EmailAddress(std::string emailAddress)
{ 
	this->emailAddress = std::make_unique<std::string>(emailAddress);
	return this;
}

ParentBuilder* ParentBuilder::HomePhone(std::string homePhone) 
{ 
	this->homePhone = std::make_unique<std::string>(homePhone);
	return this;
}

ParentBuilder* ParentBuilder::CellPhone(std::string cellPhone) 
{ 
	this->cellPhone = std::make_unique<std::string>(cellPhone);
	return this;
}

/* ========== ChildBuilder ========== */

std::shared_ptr<Child> ChildBuilder::Build()
{
	if (!previouslyAttended)	throw ERROR_CHILD_BUILDER_PREV_ATTENDED;
	if (!yearsAttended)			throw ERROR_CHILD_BUILDER_YEARS_ATTENDED;
	if (!previousLocation)		throw ERROR_CHILD_BUILDER_PREV_LOCATION;
	if (!allergies)				throw ERROR_CHILD_BUILDER_ALLERGIES;

	Person* c = PersonBuilder::Build().get();
	std::shared_ptr<Child> child(static_cast<Child*>(c));

	return child;
}

ChildBuilder* ChildBuilder::PreviouslyAttended(bool previouslyAttended)
{
	this->previouslyAttended = std::make_unique<bool>(previouslyAttended);
	return this;
}

ChildBuilder* ChildBuilder::YearsAttended(sr_int yearsAttended)
{
	this->yearsAttended = std::make_unique<sr_int>(yearsAttended);
	return this;
}

ChildBuilder* ChildBuilder::PreviousLocation(std::string previousLocation)
{
	this->previousLocation = std::make_unique<std::string>(previousLocation);
	return this;
}

ChildBuilder* ChildBuilder::Allergies(std::vector<std::string> allergies)
{
	this->allergies = std::make_unique<std::vector<std::string>>(allergies);
	return this;
}

/* ========== Person ========== */

Person::Person(PersonBuilder* builder)
{
	this->firstName =			*builder->firstName;
	this->lastName =			*builder->lastName;
	this->dateOfBirth =			*builder->dateOfBirth;
	this->age =					*builder->age;
}

/* ========== Parent ========== */

Parent::Parent(ParentBuilder* parentBuilder) : Person(parentBuilder)
{
	this->emailAddress =		*parentBuilder->emailAddress;
	this->homePhone =			*parentBuilder->homePhone;
	this->cellPhone =			*parentBuilder->cellPhone;
}

/* ========== Child ========== */

Child::Child(ChildBuilder* childBuilder) : Person(childBuilder)
{
	this->previouslyAttended =	*childBuilder->previouslyAttended;
	this->previousLocation =	*childBuilder->previousLocation;
	this->numYearsAttended =	*childBuilder->yearsAttended;
	this->allergies =			*childBuilder->allergies;
}
