#include "SRCSVHandler.h"


void CSVHandler::CreateFile(std::string file)
{
	std::ofstream f (file, std::ios::out);
}

std::vector<std::unique_ptr<Person>> CSVHandler::ReadRecords(std::string file)
{
	PersonBuilder pb;
	std::vector<std::unique_ptr<Person>> persons;

	std::ifstream f (file, std::ios::in);

	while (f.eof())
	{
		std::string line;
		getline(f, line, ',');
		pb.FirstName(line);

		getline(f, line, ',');
		pb.LastName(line);

		getline(f, line, ',');
		pb.HomeAddress(line);

		getline(f, line, ',');
		pb.EmailAddress(line);

		getline(f, line, ',');
		pb.HomePhone(line);

		getline(f, line, ',');
		pb.CellPhone(line);

		persons.push_back(pb.Build<Parent>());
	}

	return persons;
}