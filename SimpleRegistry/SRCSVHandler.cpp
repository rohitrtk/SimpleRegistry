#include "SRCSVHandler.h"

CSVHandler::CSVHandler(const std::string& path) :
	filePath(path)
{
}

CSVHandler::~CSVHandler() 
{
}

void CSVHandler::CreateFile(const std::string& file)
{
	std::ofstream f (file, std::ios::out);
}

void CSVHandler::WriteRecord(std::ofstream& stream, const Person& p)
{
	stream << p << std::endl;
}

void CSVHandler::WriteRecord(std::vector<Person*>& people)
{
	std::ofstream f;
	f.open(this->filePath);

	for (const auto& person : people)
	{
		f << *person << std::endl;
	}

	f.close();
}
