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

std::vector<std::unique_ptr<Person>> CSVHandler::ReadRecords(const std::string& file)
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
		//pb.Allergies(allergies);
		
		getline(f, line, ','); //Group
		if(line == "A")
		pb.Group(sr::Group::ADULT);

		else if (line == "1")
		pb.Group(sr::Group::GROUP_1);

		else if (line == "2")
		pb.Group(sr::Group::GROUP_2);

		else if (line == "3")
		pb.Group(sr::Group::GROUP_3);
		
		else if (line == "4")
		pb.Group(sr::Group::GROUP_4);

		else if (line == "PRE")
		pb.Group(sr::Group::PRE);

		//persons.push_back(pb.Build<Parent>());
	}
	

	return persons;
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
