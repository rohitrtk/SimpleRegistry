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
		void CreateFile(const std::string&);
		std::vector<std::unique_ptr<Person>> ReadRecords(const std::string&);
		void WriteRecord(const std::string&, std::vector<std::unique_ptr<Person>>);
};

#endif
