#include "SRPerson.h"
#include <sstream>
#include <QString>
#include <QDate>

Person::Person(PersonBuilder* builder)
{
	this->id =					std::move(builder->id);
	this->firstName =			std::move(builder->firstName);
	this->lastName =			std::move(builder->lastName);
	this->dateOfBirth =			std::move(builder->dateOfBirth);
	this->age =					std::move(builder->age);

	if (!id)			throw ERROR_BUILDER_NO_ID;
	if (!firstName)		throw ERROR_BUILDER_FIRST_NAME;
	if (!lastName)		throw ERROR_BUILDER_LAST_NAME;
	if (!dateOfBirth)	throw ERROR_BUILDER_DOB;
	if (!age)			throw ERROR_BUILDER_AGE;
}

QString Person::GetInfo()
{
	std::stringstream ss;

	if (firstName)		ss << "First Name: "	<< *firstName		<< " ";
	if (lastName)		ss << "Last Name: "		<< *lastName		<< " ";
	if (id)				ss << "ID Number: "		<< *id				<< " ";
	if (age)			ss << "Age: "			<< *age				<< " ";
	if (dateOfBirth)	ss << "DOB: "			<< dateOfBirth->toString().toStdString() << " ";
	
	return std::move(ss.str().c_str());
}

QString Parent::GetInfo()
{
	std::stringstream ss;

	ss << Person::GetInfo().toStdString();

	if (homeAddress)	ss << "Home Address: "	<< *homeAddress		<< " ";
	if (homePhone)		ss << "Home Phone: "	<< *homePhone		<< " ";
	if (cellPhone)		ss << "Cell Phone: "	<< *cellPhone		<< " ";
	if (emailAddress)	ss << "Email Address: " << *emailAddress	<< " ";

	return std::move(ss.str().c_str());
}

QString Child::GetInfo()
{
	std::stringstream ss;

	ss << Person::GetInfo().toStdString();

	if (prevLocation)	ss << "Previous Location: "		<< *prevLocation	<< " ";
	if (prevAttended)	ss << "Previously Attended: "	<< *prevAttended	<< " ";
	if (yearsAttended)	ss << "Years Attended: "		<< *yearsAttended	<< " ";

	return std::move(ss.str().c_str());
}

Parent::Parent(PersonBuilder* builder) : Person(builder)
{
	this->emailAddress =	std::move(builder->emailAddress);
	this->homePhone =		std::move(builder->homePhone);
	this->cellPhone =		std::move(builder->cellPhone);
	this->homeAddress =		std::move(builder->homeAddress);

	if (!homeAddress)	throw ERROR_BUILDER_HOME_ADDRESS;
	if (!emailAddress)	throw ERROR_BUILDER_EMAIL_ADDRESS;
	if (!homePhone)		throw ERROR_BUILDER_HOME_PHONE;
	if (!cellPhone)		throw ERROR_BUILDER_CELL_PHONE;

	this->children = std::make_unique<sr::_list>();
}

Child::Child(PersonBuilder* builder) : Person(builder)
{
	this->prevAttended =	std::move(builder->prevAttended);
	this->yearsAttended =	std::move(builder->yearsAttended);
	this->allergies =		std::move(builder->allergies);
	this->interests =		std::move(builder->interests);
	this->group =			std::move(builder->group);

	if (!prevAttended)	throw ERROR_BUILDER_PREV_ATTENDED;
	if (!yearsAttended) throw ERROR_BUILDER_YEARS_ATTENDED;
	if (!group)			throw ERROR_BUILDER_GROUP;
	
	this->guardians = std::make_unique<sr::_list>();
}

PersonBuilder* PersonBuilder::ID(sr::_int id)
{
	this->id = std::make_unique<sr::_int>(id);
	return this;
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

PersonBuilder* PersonBuilder::Age(sr::_int age)
{
	this->age = std::make_unique<sr::_int>(age);
	return this;
}

PersonBuilder* PersonBuilder::HomeAddress(std::string homeAddress)
{
	this->homeAddress = std::make_unique<std::string>(homeAddress);
	return this;
}

PersonBuilder* PersonBuilder::EmailAddress(std::string emailAddress)
{
	this->emailAddress = std::make_unique<std::string>(emailAddress);
	return this;
}

PersonBuilder* PersonBuilder::HomePhone(std::string homePhone)
{
	this->homePhone = std::make_unique<std::string>(homePhone);
	return this;
}

PersonBuilder* PersonBuilder::CellPhone(std::string cellPhone)
{
	this->cellPhone = std::make_unique<std::string>(cellPhone);
	return this;
}

PersonBuilder* PersonBuilder::PrevAttended(bool prevAttended)
{
	this->prevAttended = std::make_unique<bool>(prevAttended);
	return this;
}

PersonBuilder* PersonBuilder::YearsAttended(sr::_int yearsAttended)
{
	this->yearsAttended = std::make_unique<sr::_int>(yearsAttended);
	return this;
}

PersonBuilder* PersonBuilder::Allergies(sr::_list allergies)
{
	this->allergies = std::make_unique<sr::_list>(allergies);
	return this;
}

PersonBuilder* PersonBuilder::Interests(sr::_list interests)
{
	this->interests = std::make_unique<sr::_list>(interests);
	return this;
}

PersonBuilder* PersonBuilder::PrevLocation(std::string prevLocation)
{
	this->prevLocation = std::make_unique<std::string>(prevLocation);
	return this;
}

PersonBuilder* PersonBuilder::Group(sr::Group group)
{
	this->group = std::make_unique<sr::Group>(group);
	return this;
}
