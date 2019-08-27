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
		void CreateFile(std::string);
		std::vector<std::unique_ptr<Person>> ReadRecords(std::string);
		std::unique_ptr<Person> WriteRecord(std::string);
};

#endif
