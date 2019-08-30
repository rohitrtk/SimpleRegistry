#include "SRCSVHandler.h"

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

		persons.push_back(pb.Build<Parent>());
	}
	

	return persons;
}


void CSVHandler::WriteRecord(const std::string& file, std::vector<std::unique_ptr<Person>> persons)
{
	std::ofstream f;
	qint16 temp;
	QDate date;
	f.open (file);
	QString qLine;
	std::string line; 

	for (const auto& p : persons)
	{
		temp = p->GetID();
		qLine = QString::number(temp);
		line = qLine.toStdString();
		f << line << ",";

		qLine = p->GetFirstName();
		line = p->GetFirstName().toStdString();
		f << line << ",";

		qLine = p->GetLastName();
		line = p->GetLastName().toStdString();
		f << line << ",";

		temp = p->GetAge();
		qLine = QString::number(temp);
		line = qLine.toStdString();
		f << line << ",";

		date = p->GetDateOfBirth();
		qLine = date.toString("dd/MM/yyyy");
		line = qLine.toStdString();
		f << line << ",";

		line = (p->GetPersonType() == sr::PersonType::PARENT) ? "Parent" : "Child";
		f << line << ",";

		qLine = p->GetGender();
		line = p->GetGender().toStdString();
		f << line << ",";

		qLine = p->GetEmailAddress();
		line = p->GetEmailAddress().toStdString();
		f << line << ",";

		qLine = p->GetHomePhone();
		line = p->GetHomePhone().toStdString();
		f << line << ",";

		qLine = p->GetCellPhone();
		line = p->GetCellPhone().toStdString();
		f << line << ",";
		
		qLine = p->GetHomeAddress();
		line = p->GetHomeAddress().toStdString();
		f << line << ",";

		qLine = p->GetPrevLocation();
		line = p->GetPrevLocation().toStdString();
		f << line << ",";

		bool prev = p->GetPrevAttended();
		if(prev)
		line = "true";
		else
		line = "false";
		f << line << ",";

		temp = p->GetYearsAttended();
		qLine = QString::number(temp); 
		line = qLine.toStdString();
		f << line << ",";

		sr::Group Group = p->GetGroup();
		if(Group == sr::Group::ADULT)
		line = "A";

		else if(Group == sr::Group::GROUP_1)
		line = "1";

		else if(Group == sr::Group::GROUP_2)
		line = "2";

		else if(Group == sr::Group::GROUP_3)
		line = "3";

		else if(Group == sr::Group::GROUP_4)
		line = "4";

		else if(Group == sr::Group::GROUP_4)
		line = "PRE";
		f << line << ",";


	}

		
}