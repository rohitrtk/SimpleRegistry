#include "SRPerson.h"
#include <sstream>
#include <QDebug>

Person::Person(PersonBuilder* builder)
{
	this->firstName =			std::move(builder->firstName);
	this->lastName =			std::move(builder->lastName);
	this->dateOfBirth =			std::move(builder->dateOfBirth);
	this->age =					std::move(builder->age);

	if (!firstName)		throw ERROR_PERSON_BUILDER_FIRST_NAME;
	if (!lastName)		throw ERROR_PERSON_BUILDER_LAST_NAME;
	if (!dateOfBirth)	throw ERROR_PERSON_BUILDER_DOB;
	if (!age)			throw ERROR_PERSON_BUILDER_AGE;
}

void Person::PrintInfo()
{
	qInfo() << "First Name: " << firstName->c_str();
}

Parent::Parent(PersonBuilder* builder) : Person(builder)
{
	this->emailAddress =	std::move(builder->emailAddress);
	this->homePhone =		std::move(builder->homePhone);
	this->cellPhone =		std::move(builder->cellPhone);
	this->homeAddress =		std::move(builder->homeAddress);

	if (!homeAddress)	throw ERROR_PARENT_BUILDER_HOME_ADDRESS;
	if (!emailAddress)	throw ERROR_PARENT_BUILDER_EMAIL_ADDRESS;
	if (!homePhone)		throw ERROR_PARENT_BUILDER_HOME_PHONE;
	if (!cellPhone)		throw ERROR_PARENT_BUILDER_CELL_PHONE;
}
