#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <QDate>
#include <vector>
#include <sstream>
#include <ostream>

class Person;
class Parent;
class Child;
class EmergencyContact;
struct HomeAddress;

using Age = int;

struct HomeAddress
{
	int streetNumber = 0;
	std::string streetName = "";
	std::string streetName2 = "";
	std::string cityName = "";
	std::string province = "";
	std::string postalCode = "";
};

std::ostream& operator << (std::ostream& os, const HomeAddress& ha)
{
	os << ha.streetNumber << " " << ha.streetName << " " << ha.streetName2 << " " << ha.cityName << " " << ha.province << " " << ha.postalCode << std::endl;
	return os;
}

class Person
{
public:
	Person() {}
	Person(std::string firstName, std::string lastName, Age age, QDate* dateOfBirth) :
		firstName(firstName), lastName(lastName), age(age), dateOfBirth(*dateOfBirth) {}
	
	virtual std::string GetInfoAsString() = 0;

	inline void SetFirstName(std::string firstName) { this->firstName = firstName; }
	inline std::string GetFirstName() { return this->firstName; }

	inline void SetLastName(std::string lastName) { this->lastName = lastName; }
	inline std::string GetLastName() { return this->lastName; }

	inline void SetAge(Age age) { this->age = age; }
	inline Age GetAge() { return this->age; }

	inline void SetDateOfBirth(QDate dateOfBirth) { this->dateOfBirth = dateOfBirth; }
	inline const QDate& GetDateOfBirth() { return this->dateOfBirth; }

protected:
	std::string firstName;
	std::string lastName;
	Age age;
	QDate dateOfBirth;
};

class EmergencyContact : public Person
{
public:
	EmergencyContact() {}
	EmergencyContact(std::string firstName, std::string lastName, std::string phoneNumber, std::string relation) :
		Person(firstName, lastName, 0, nullptr), relation(relation), phoneNumber(phoneNumber) {}

	inline std::string GetInfoAsString() override 
	{
		std::stringstream ss;
		ss << "Name: " << firstName << " " << lastName << " Relation: " << relation << " Phone: " << phoneNumber << std::endl;
		return ss.str();
	}

	inline std::string SetRelation(std::string relation) { this->relation = relation; }
	inline std::string GetRelation() { return this->relation; }

private:
	std::string relation;
	std::string phoneNumber;
};

class Parent : public Person
{
public:
	Parent() {}
	Parent(std::string firstName, std::string lastName, Age age, QDate dateOfBirth, HomeAddress homeAddress,
		std::string emailAddress, std::string homePhone, std::string cellPhone = "") :
		Person(firstName, lastName, age, &dateOfBirth) , homeAddress(homeAddress), 
		emailAddress(emailAddress), homePhone(homePhone), cellPhone(cellPhone) {}

	inline std::string GetInfoAsString() override 
	{
		std::stringstream ss;
		ss << "Name: " << firstName << " " << lastName << " Age: " << age << " Home Address: " << homeAddress << "Email Address: " << emailAddress
			<< " Home Phone: " << homePhone << " Cell Phone: " << cellPhone << std::endl;
		return ss.str();
	}

	inline void SetHomeAddress(HomeAddress* homeAddress) { this->homeAddress = *homeAddress; }
	inline const HomeAddress& GetHomeAddress() { return this->homeAddress; }

	inline void SetEmailAddress(std::string emailAddress) { this->emailAddress = emailAddress; }
	inline std::string GetEmailAddress() { return this->emailAddress; }

	inline void SetHomePhone(std::string homePhone) { this->homePhone = homePhone; }
	inline std::string GetHomePhone() { return this->homePhone; }

	inline void SetCellPhone() { this->cellPhone = cellPhone; }
	inline std::string GetCellPhone() { return this->cellPhone; }
	
	inline void SetEmergencyContact(EmergencyContact* emergencyContact) { this->emergencyContact = *emergencyContact; }
	inline const EmergencyContact& GetEmergencyContact() { return this->emergencyContact; }

private:
	HomeAddress homeAddress;
	std::string emailAddress;
	std::string homePhone;
	std::string cellPhone;
	EmergencyContact emergencyContact;
	std::vector<std::string> interests;

	std::vector<Child> children;
};

class Child : public Person 
{
public:
	Child() {}
	Child(std::string firstName, std::string lastName, Age age, QDate dateOfBirth) :
		Person(firstName, lastName, age, &dateOfBirth) {}

	inline std::string GetInfoAsString() override 
	{
		std::stringstream ss;
		ss << "Name: " << firstName << " " << lastName << " Age: " << age << std::endl;
		return ss.str();
	}

private:
	std::vector<Parent> parents;

	bool previouslyAttended;
	Age numYearsAttended;
	std::string previousLocation;
	std::vector<std::string> allergies;
	std::vector<std::string> interests;
};

#endif