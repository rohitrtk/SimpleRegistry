#ifndef SRCONSTANTS_H_
#define SRCONSTANTS_H_

#include <vector>
#include <QString>

constexpr const char* ErrorBuilderID			= "MISSING ID";
constexpr const char* ErrorBuilderFirstName		= "MISSING FIRST NAME";
constexpr const char* ErrorBuilderLastName		= "MISSING LAST NAME";
constexpr const char* ErrorBuilderDOB			= "MISSING DOB";
constexpr const char* ErrorBuilderAge			= "MISSING AGE";
constexpr const char* ErrorBuilderHomeAddress	= "MISSING HOME ADDRESS";
constexpr const char* ErrorBuilderEmailAddress	= "MISSING EMAIL ADDRESS";
constexpr const char* ErrorBuilderHomePhone		= "MISSING HOME PHONE";
constexpr const char* ErrorBuilderCellPhone		= "MISSING CELL PHONE";
constexpr const char* ErrorBuilderPrevAttended	= "MISSING PREVIOUSLY ATTENDED";
constexpr const char* ErrorBuilderPrevLocation	= "MISSING PREVIOUS LOCATION";
constexpr const char* ErrorBuilderYearsAttended = "MISSING YEARS ATTENDED";
constexpr const char* ErrorBuilderAllergies		= "MISSING ALLERGIES";
constexpr const char* ErrorBuilderGroup			= "MISSING GROUP";

constexpr const char* ErrorCreateParent			= "PERSON LIST IS NULL";

namespace sr
{
	using list = std::vector<QString>;

	enum class PersonType
	{
		PARENT, CHILD, UNDEFINED
	};

	enum class Group
	{
		GROUP_1 = 1, GROUP_2 = 2, GROUP_3 = 3
	};

	enum class TableTitle
	{
		ID, TYPE, FIRST_NAME, LAST_NAME, AGE, DOB,
		HOME_ADDRESS, HOME_PHONE, CELL_PHONE, EMAIL_ADDRESS,
		PREV_ATTENDED, PREV_LOCATION, YEARS_ATTENDED
	};
}

#endif 