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
		int n;
		bool altf = true;
		bool tf = true;
		std::string line;
		std::vector<QString> allergies;
		QString temp;
		QDate Date;

		getline(f, line, ',');
		temp = QString::fromStdString(line); //First
		pb.FirstName(temp);

		getline(f, line, ',');
		temp = QString::fromStdString(line); //Last
		pb.LastName(temp);

		getline(f, line, ',');
		temp = QString::fromStdString(line);
		Date = QDate::fromString(temp, "dd/MM/yyyy"); //DOB
		pb.DateOfBirth(Date);

		getline(f, line, ',');
		temp = QString::fromStdString(line); //Home Address
		pb.HomeAddress(temp);

		getline(f, line, ',');
		temp = QString::fromStdString(line); //Email
		pb.EmailAddress(temp);

		getline(f, line, ',');
		temp = QString::fromStdString(line); //Homephone
		pb.HomePhone(temp);

		getline(f, line, ',');
		temp = QString::fromStdString(line); //Cellular
		pb.CellPhone(temp);

		getline(f, line, ','); //bool
		if (line == "true")
			tf = true;
		else if (line == "false")
			tf = false;
		pb.PrevAttended(tf);

		getline(f, line, ','); //Years attended / qint
		n = stoi(line);
		pb.YearsAttended(n);
		
		getline(f, line, ',');
		temp = QString::fromStdString(line); //Prev location 
		pb.PrevLocation(temp);

		do //Allergies / list?
		{ 
			getline(f, line, ','); 
			std::size_t found = line.find ("al-");
			if(found != std::string::npos)
			{ 
				temp = QString::fromStdString(line);
				allergies.push_back(temp);
			}
			else
			altf = false;

			
		}while(altf == true);
		pb.Allergies(allergies);
		
		//getline(f, line, ','); //Group
		//pb.Group(line);
		

		persons.push_back(pb.Build<Parent>());
	}
	

	return persons;
}


std::unique_ptr<Person> CSVHandler::WriteRecord(std::string file)
{
	std::ofstream f;
	f.open (file);
	std::string line;
	

	f << 
	
	
	
}