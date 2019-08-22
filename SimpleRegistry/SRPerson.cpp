#include "SRPerson.h"
#include <sstream>
#include <QString>
#include <QDate>

Person::Person(PersonBuilder* builder) :
	id			(std::move(builder->id)),
	firstName	(std::move(builder->firstName)),
	lastName	(std::move(builder->lastName)),
	dateOfBirth	(std::move(builder->dateOfBirth))
{
	if (!id)			throw ERROR_BUILDER_NO_ID;
	if (!firstName)		throw ERROR_BUILDER_FIRST_NAME;
	if (!lastName)		throw ERROR_BUILDER_LAST_NAME;
	if (!dateOfBirth)	throw ERROR_BUILDER_DOB;

	// Setting age
	QDate currentDate = QDate::currentDate();
	this->age = std::make_unique<qint16>(currentDate.year() - dateOfBirth->year());

	if ((currentDate.month() - dateOfBirth->month() < 0) &&
		currentDate.day() - dateOfBirth->day() < 0)
	{
		*this->age -= 1;
	}
}

QString Person::GetInfo()
{
	std::stringstream ss;

	if (firstName)		ss << "First Name: "	<< firstName	<< " ";
	if (lastName)		ss << "Last Name: "		<< lastName		<< " ";
	if (id)				ss << "ID Number: "		<< *id			<< " ";
	if (age)			ss << "Age: "			<< *age			<< " ";
	if (dateOfBirth)	ss << "DOB: "			<< dateOfBirth->toString().toStdString() << " ";
	
	return std::move(ss.str().c_str());
}

QString Parent::GetInfo()
{
	std::stringstream ss;

	ss << Person::GetInfo().toStdString();

	if (homeAddress)	ss << "Home Address: "	<< homeAddress		<< " ";
	if (homePhone)		ss << "Home Phone: "	<< homePhone		<< " ";
	if (cellPhone)		ss << "Cell Phone: "	<< cellPhone		<< " ";
	if (emailAddress)	ss << "Email Address: " << emailAddress		<< " ";

	return std::move(ss.str().c_str());
}

QString Child::GetInfo()
{
	std::stringstream ss;

	ss << Person::GetInfo().toStdString();

	if (prevLocation)	ss << "Previous Location: "		<< prevLocation	<< " ";
	if (prevAttended)	ss << "Previously Attended: "	<< prevAttended	<< " ";
	if (yearsAttended)	ss << "Years Attended: "		<< yearsAttended	<< " ";

	return std::move(ss.str().c_str());
}

Parent::Parent(PersonBuilder* builder) : Person(builder),
	homeAddress		(std::move(builder->homeAddress)),
	homePhone		(std::move(builder->homePhone)),
	cellPhone		(std::move(builder->cellPhone)),
	emailAddress	(std::move(builder->emailAddress))
{
	if (!homeAddress)	throw ERROR_BUILDER_HOME_ADDRESS;
	if (!emailAddress)	throw ERROR_BUILDER_EMAIL_ADDRESS;
	if (!homePhone)		throw ERROR_BUILDER_HOME_PHONE;
	if (!cellPhone)		throw ERROR_BUILDER_CELL_PHONE;
}

Child::Child(PersonBuilder* builder) : Person(builder),
	prevLocation	(std::move(builder->prevLocation)),
	prevAttended	(std::move(builder->prevAttended)),
	yearsAttended	(std::move(builder->yearsAttended)),
	allergies		(std::move(builder->allergies))
{
	if (!prevAttended)	throw ERROR_BUILDER_PREV_ATTENDED;
	if (!yearsAttended) throw ERROR_BUILDER_YEARS_ATTENDED;

	this->group = std::move(builder->group);
}

PersonBuilder* PersonBuilder::ID(qint16 id)
{
	this->id = std::make_unique<qint16>(id);
	return this;
}

PersonBuilder* PersonBuilder::FirstName(QString firstName)
{
	this->firstName = std::make_unique<QString>(firstName);
	return this;
}

PersonBuilder* PersonBuilder::LastName(QString lastName)
{
	this->lastName = std::make_unique<QString>(lastName);
	return this;
}

PersonBuilder* PersonBuilder::DateOfBirth(QDate dateOfBirth)
{
	this->dateOfBirth = std::make_unique<QDate>(dateOfBirth);
	return this;
}

PersonBuilder* PersonBuilder::HomeAddress(QString homeAddress)
{
	this->homeAddress = std::make_unique<QString>(homeAddress);
	return this;
}

PersonBuilder* PersonBuilder::EmailAddress(QString emailAddress)
{
	this->emailAddress = std::make_unique<QString>(emailAddress);
	return this;
}

PersonBuilder* PersonBuilder::HomePhone(QString homePhone)
{
	this->homePhone = std::make_unique<QString>(homePhone);
	return this;
}

PersonBuilder* PersonBuilder::CellPhone(QString cellPhone)
{
	this->cellPhone = std::make_unique<QString>(cellPhone);
	return this;
}

PersonBuilder* PersonBuilder::PrevAttended(bool prevAttended)
{
	this->prevAttended = std::make_unique<bool>(prevAttended);
	return this;
}

PersonBuilder* PersonBuilder::YearsAttended(qint16 yearsAttended)
{
	this->yearsAttended = std::make_unique<qint16>(yearsAttended);
	return this;
}

PersonBuilder* PersonBuilder::Allergies(sr::_list allergies)
{
	this->allergies = std::make_unique<sr::_list>(allergies);
	return this;
}

PersonBuilder* PersonBuilder::PrevLocation(QString prevLocation)
{
	this->prevLocation = std::make_unique<QString>(prevLocation);
	return this;
}

PersonBuilder* PersonBuilder::Group(sr::Group group)
{
	this->group = std::make_unique<sr::Group>(group);
	return this;
}
