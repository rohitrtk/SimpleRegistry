#include "SRPerson.h"
#include <sstream>
#include <QString>
#include <QDate>
#include <QDebug>

Person::Person(PersonBuilder<Parent>* builder) :
	firstName		(std::move(builder->firstName)),
	lastName		(std::move(builder->lastName)),
	dateOfBirth		(std::move(builder->dateOfBirth)),
	gender			(std::move(builder->gender)),
	homeAddress		(std::move(builder->homeAddress)),
	homePhone		(std::move(builder->homePhone)),
	cellPhone		(std::move(builder->cellPhone)),
	emailAddress	(std::move(builder->emailAddress)),
	allergies		(std::move(builder->allergies))
{
	if (!firstName)		throw ErrorBuilderFirstName;
	if (!lastName)		throw ErrorBuilderLastName;
	if (!dateOfBirth)	throw ErrorBuilderDOB;
	if (!gender)		throw ErrorBuilderGender;

	this->age	= std::make_unique<qint16>(AssignAge());
	this->group	= std::make_unique<sr::Group>(AssignGroup());
}

Person::Person(PersonBuilder<Child>* builder) :
	firstName(std::move(builder->firstName)),
	lastName(std::move(builder->lastName)),
	dateOfBirth(std::move(builder->dateOfBirth)),
	gender(std::move(builder->gender)),
	homeAddress(std::move(builder->homeAddress)),
	homePhone(std::move(builder->homePhone)),
	cellPhone(std::move(builder->cellPhone)),
	emailAddress(std::move(builder->emailAddress)),
	allergies(std::move(builder->allergies))
{
	if (!firstName)		throw ErrorBuilderFirstName;
	if (!lastName)		throw ErrorBuilderLastName;
	if (!dateOfBirth)	throw ErrorBuilderDOB;
	if (!gender)		throw ErrorBuilderGender;

	this->age = std::make_unique<qint16>(AssignAge());
	this->group = std::make_unique<sr::Group>(AssignGroup());
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

	return std::move(age);
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
	if		(*group == sr::Group::PRE)		s = "PRE";
	else if (*group == sr::Group::GROUP_1)	s = "1";
	else if (*group == sr::Group::GROUP_2)	s = "2";
	else if (*group == sr::Group::GROUP_3)	s = "3";
	else if (*group == sr::Group::GROUP_4)	s = "4";
	else									s = "A";

	return s;
}

Parent::Parent(PersonBuilder<Parent>* builder) : Person(builder)
{
	if (!homeAddress)	throw ErrorBuilderHomePhone;
	if (!emailAddress)	throw ErrorBuilderEmailAddress;
	if (!homePhone)		throw ErrorBuilderHomePhone;
	if (!cellPhone)		throw ErrorBuilderCellPhone;

	this->personType = std::make_unique<sr::PersonType>(sr::PersonType::PARENT);
}

Child::Child(PersonBuilder<Child>* builder) : Person(builder)
{
	if (!prevAttended)	throw ErrorBuilderPrevAttended;
	if (!yearsAttended) throw ErrorBuilderYearsAttended;

	this->personType = std::make_unique<sr::PersonType>(sr::PersonType::CHILD);
}

/*
template <class T>
T* PersonBuilder<T>::PrevAttended(bool prevAttended)
{
	this->prevAttended = std::make_unique<bool>(prevAttended);
	return this;
}

template <class T>
T* PersonBuilder<T>::YearsAttended(const qint16& yearsAttended)
{
	this->yearsAttended = std::make_unique<qint16>(yearsAttended);
	return this;
}*/

/*
PersonBuilder* PersonBuilder::PrevLocation(const QString& prevLocation)
{
	this->prevLocation = std::make_unique<QString>(prevLocation);
	return this;
}

PersonBuilder* PersonBuilder::Group(const sr::Group&& group)
{
	this->group = std::make_unique<sr::Group>(group);
	return this;
}

PersonBuilder* PersonBuilder::Parents(const QString& parents)
{
	this->parents = std::make_unique<QString>(parents);
	return this;
}

PersonBuilder* PersonBuilder::Children(const QString& children)
{
	this->children = std::make_unique<QString>(children);
	return this;
}
*/

std::ostream& operator << (std::ostream& stream, const Person& person)
{
	stream
		<< *person.id << ", " << person.firstName->toStdString()				<< ", "
		<< person.lastName->toStdString() << ", " << *person.age << ", "
		<< person.dateOfBirth->toString().toStdString()	<< ", "
		<< person.lastName->toStdString() << ", " 
		<< ((*person.personType == sr::PersonType::CHILD) ? "Child" : "Parent") << ", "
		<< person.gender->toStdString() << ", ";
	
	if (person.homeAddress)
	{
		stream << person.homeAddress->toStdString();
	}
	stream << ", ";

	if (person.homePhone)
	{
		stream << person.homePhone->toStdString();
	}
	stream << ", ";
	
	if (person.cellPhone)
	{
		stream << person.cellPhone->toStdString();
	}
	stream << ", ";

	if (person.emailAddress)
	{
		stream << person.emailAddress->toStdString();
	}
	stream << ", ";

	if (person.prevLocation)
	{
		stream << person.prevLocation->toStdString();
	}
	stream << ", ";

	if (person.prevAttended)
	{
		stream << person.GetPrevAttendedS().toStdString();
	}
	stream << ", ";

	if (person.yearsAttended)
	{
		stream << *person.yearsAttended;
	}
	stream << ", ";

	if (person.allergies)
	{
		stream << person.allergies->toStdString();
	}
	stream << ", ";

	stream << person.GetGroupAsString().toStdString() << ", ";

	if (person.parents)
	{
		stream << person.parents->toStdString();
	}
	stream << ", ";
		
	if (person.children)
	{
		stream << person.children->toStdString();
	}

	return stream;
}
