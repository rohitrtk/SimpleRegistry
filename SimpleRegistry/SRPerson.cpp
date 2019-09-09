#include "SRPerson.h"

#include <QDebug>

/* ******************** Person ******************** */

Person::Person(PersonBuilder<Parent>* builder) :
	firstName		(std::move(builder->firstName)),
	lastName		(std::move(builder->lastName)),
	dateOfBirth		(std::move(builder->dateOfBirth)),
	gender			(std::move(builder->gender)),
	homeAddress		(std::move(builder->homeAddress)),
	primaryPhone	(std::move(builder->primaryPhone)),
	secondaryPhone	(std::move(builder->secondaryPhone)),
	emailAddress	(std::move(builder->emailAddress)),
	prevAttended	(std::move(builder->prevAttended)),
	medical			(std::move(builder->medical)),
	parents			(std::move(builder->parents)),
	children		(nullptr),
	relation		(nullptr),
	interests		(std::move(builder->interests))
{
	if (!firstName)		throw ErrorBuilderFirstName;
	if (!lastName)		throw ErrorBuilderLastName;
	if (!dateOfBirth)	throw ErrorBuilderDOB;
	if (!gender)		throw ErrorBuilderGender;

	this->age	= std::make_unique<qint16>(AssignAge());
	this->age31 = std::make_unique<qint16>(AssignAge31());
	this->group	= std::make_unique<sr::Group>(sr::Group::ADULT);

	this->values[0] = *firstName;
	this->values[1] = *lastName;
	this->values[2] = gender->at(0);
	this->values[3] = dateOfBirth->toString(dobFormat);
	this->values[4] = QString::number(*age);
	this->values[5] = QString::number(*age31);
	this->values[6] = this->GetGroupAsString();
	this->values[7] = CHECK_NULL_STRING(parents);
	this->values[8] = CHECK_NULL_STRING(relation);
	this->values[9] = CHECK_NULL_STRING(homeAddress);
	this->values[10] = CHECK_NULL_STRING(primaryPhone);
	this->values[11] = CHECK_NULL_STRING(secondaryPhone);
	this->values[12] = CHECK_NULL_STRING(emailAddress);
	this->values[13] = "";
	this->values[14] = CHECK_NULL_STRING(interests);
	this->values[15] = CHECK_NULL_STRING(medical);
	this->values[16] = CHECK_NULL_STRING(children);
}

Person::Person(PersonBuilder<Child>* builder) :
	firstName		(std::move(builder->firstName)),
	lastName		(std::move(builder->lastName)),
	dateOfBirth		(std::move(builder->dateOfBirth)),
	gender			(std::move(builder->gender)),
	homeAddress		(std::move(builder->homeAddress)),
	primaryPhone	(std::move(builder->primaryPhone)),
	secondaryPhone	(std::move(builder->secondaryPhone)),
	emailAddress	(std::move(builder->emailAddress)),
	prevAttended	(std::move(builder->prevAttended)),
	medical			(std::move(builder->medical)),
	parents			(std::move(builder->parents)),
	children		(nullptr),
	relation		(std::move(builder->relation)),
	interests		(std::move(builder->interests))
{
	if (!firstName)		throw ErrorBuilderFirstName;
	if (!lastName)		throw ErrorBuilderLastName;
	if (!dateOfBirth)	throw ErrorBuilderDOB;
	if (!gender)		throw ErrorBuilderGender;

	this->age	= std::make_unique<qint16>(AssignAge());
	this->age31 = std::make_unique<qint16>(AssignAge31());
	this->group = std::make_unique<sr::Group>(AssignGroup());

	this->values[0] = *firstName;
	this->values[1] = *lastName;
	this->values[2] = gender->at(0);
	this->values[3] = dateOfBirth->toString(dobFormat);
	this->values[4] = QString::number(*age);
	this->values[5] = QString::number(*age31);
	this->values[6] = this->GetGroupAsString();
	this->values[7] = CHECK_NULL_STRING(parents);
	this->values[8] = CHECK_NULL_STRING(relation);
	this->values[9] = CHECK_NULL_STRING(homeAddress);
	this->values[10] = CHECK_NULL_STRING(primaryPhone);
	this->values[11] = CHECK_NULL_STRING(secondaryPhone);
	this->values[12] = CHECK_NULL_STRING(emailAddress);
	this->values[13] = this->GetPrevAttendedS();
	this->values[14] = CHECK_NULL_STRING(interests);
	this->values[15] = CHECK_NULL_STRING(medical);
	this->values[16] = CHECK_NULL_STRING(children);
}

Person::~Person()
{
}

qint16 Person::AssignAge() const
{
	QDate currentDate = QDate::currentDate();
	qint16 age = currentDate.year() - dateOfBirth->year();

	if ((currentDate.month() - dateOfBirth->month() < 0) &&
		 currentDate.day()   - dateOfBirth->day()   < 0)
	{
		age -= 1;
	}

	return age;
}

qint16 Person::AssignAge31() const 
{
	if (QDate::currentDate() < *this->dateOfBirth)
	{
		return *age + 1;
	}
	
	return *age;
}

sr::Group Person::AssignGroup() const
{
	sr::Group group;
	if		(*age > 17) group = sr::Group::ADULT;
	else if (*age > 14) group = sr::Group::GROUP_4;
	else if (*age > 11) group = sr::Group::GROUP_3;
	else if (*age > 8)	group = sr::Group::GROUP_2;
	else if (*age > 5)	group = sr::Group::GROUP_1;
	else				group = sr::Group::PRE;

	return group;
}

QString Person::GetGroupAsString() const
{
	QString s;
	if		(*group == sr::Group::PRE)		s = Group_Pre;
	else if (*group == sr::Group::GROUP_1)	s = Group_1;
	else if (*group == sr::Group::GROUP_2)	s = Group_2;
	else if (*group == sr::Group::GROUP_3)	s = Group_3;
	else if (*group == sr::Group::GROUP_4)	s = Group_4;
	else									s = Group_A;

	return s;
}

/* ******************** Parent ******************** */

Parent::Parent(PersonBuilder<Parent>* builder) : Person(builder)
{
	if (!homeAddress)		throw ErrorBuilderHomePhone;
	if (!emailAddress)		throw ErrorBuilderEmailAddress;
	if (!primaryPhone)		throw ErrorBuilderHomePhone;
	if (!secondaryPhone)	throw ErrorBuilderCellPhone;
}

/* ******************** Child ******************** */

Child::Child(PersonBuilder<Child>* builder) : Person(builder)
{
	if (!prevAttended)	throw ErrorBuilderPrevAttended;
}
