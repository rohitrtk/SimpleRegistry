#ifndef SRCONSTANTS_H_
#define SRCONSTANTS_H_

#include <vector>
#include <QString>

constexpr const char* ErrorBuilderID			= "MISSING ID";
constexpr const char* ErrorBuilderFirstName		= "MISSING FIRST NAME";
constexpr const char* ErrorBuilderLastName		= "MISSING LAST NAME";
constexpr const char* ErrorBuilderDOB			= "MISSING DOB";
constexpr const char* ErrorBuilderAge			= "MISSING AGE";
constexpr const char* ErrorBuilderGender		= "MISSING GENDER";
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
		UNDEFINED = 1, PARENT, CHILD
	};

	/* Ages - Pre's: 4-5, Group 1: 6-8, Group 2: 9-11, Group 3: 12-14, Group 4: 15-17 */
	enum class Group
	{
		PRE, GROUP_1, GROUP_2, GROUP_3, GROUP_4, ADULT
	};

	enum class TableTitle
	{
		ID, TYPE, FIRST_NAME, LAST_NAME, AGE, DOB,
		HOME_ADDRESS, HOME_PHONE, CELL_PHONE, EMAIL_ADDRESS,
		PREV_ATTENDED, PREV_LOCATION, YEARS_ATTENDED
	};

	enum class Gender
	{
		MALE, FEMALE
	};
}

#endif 