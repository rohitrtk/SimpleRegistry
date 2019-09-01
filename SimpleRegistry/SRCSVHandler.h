#ifndef CSV_HANDLER_H
#define CSV_HANDLER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <QDate>
#include "SRPerson.h"


class CSVHandler
{
public:
	CSVHandler(const std::string& path);
	~CSVHandler();

	void CreateFile(const std::string&);
	std::vector<std::unique_ptr<Person>> ReadRecords(const std::string&);

	void WriteRecord(std::vector<Person*>& people);
	void WriteRecord(std::ofstream& stream, const Person& p);

private:
	std::string filePath;
};

#endif
