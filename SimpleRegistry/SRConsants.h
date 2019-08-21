#ifndef SRCONSTANTS_H_
#define SRCONSTANTS_H_

#include <vector>
#include <string>
#include <memory>
#include <QEvent>

#define ERROR_BUILDER_NO_ID				"NULL ID"

#define ERROR_BUILDER_FIRST_NAME		"NULL FIRST NAME"
#define ERROR_BUILDER_LAST_NAME			"NULL LAST NAME"
#define ERROR_BUILDER_DOB				"NULL DOB"
#define ERROR_BUILDER_AGE				"NULL AGE"

#define ERROR_BUILDER_HOME_ADDRESS		"NULL HOME ADDRESS"
#define ERROR_BUILDER_EMAIL_ADDRESS		"NULL EMAIL ADDRESS"
#define ERROR_BUILDER_HOME_PHONE		"NULL HOME PHONE"
#define ERROR_BUILDER_CELL_PHONE		"NULL CELL PHONE"

#define ERROR_BUILDER_PREV_ATTENDED		"NULL PREVIOUSLY ATTENDED"
#define ERROR_BUILDER_YEARS_ATTENDED	"NULL YEARS ATTENDED"
#define ERROR_BUILDER_PREV_LOCATION		"NULL PREVIOUS LOCATION"
#define ERROR_BUILDER_ALLERGIES			"NULL ALLERGIES"
#define ERROR_BUILDER_GROUP				"NULL GROUP NUMBER"

#define ERROR_CREATE_PARENT_NULL		"NULL PERSON LIST"

class Person;

namespace sr
{
	using _int		= unsigned short int;
	using _list		= std::vector<QString>;
	using _ppl		= std::vector<std::unique_ptr<Person>>;

	const QEvent::Type UserCreatedEvent = static_cast<QEvent::Type>(4747);

	enum class Group
	{
		GROUP_1 = 1, GROUP_2 = 2, GROUP_3 = 3
	};
}

#endif 