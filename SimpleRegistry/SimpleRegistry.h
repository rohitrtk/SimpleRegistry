#ifndef SIMPLE_REGISTRY_H_
#define SIMPLE_REGISTRY_H_

#include <QtWidgets/QMainWindow>
#include "ui_SimpleRegistry.h"
#include "SRConsants.h"
#include "SRConsants.h"
#include <memory>
#include <vector>
#include <array>
#include <QSqlDatabase>
#include "SRCreateParent.h"
#include "SRCreateChild.h"

class SRCreateParent;
class SRCreateChild;
class QTableWidget;

enum class TableTitleIndex
{
	ID,				FIRST_NAME,		LAST_NAME,		GENDER,
	DATE_OF_BIRTH,	AGE,			AGE_31,			GROUP,
	PARENTS_NAME,	RELATIONSHIP,	HOME_ADDRESS,	PRIMARY_PHONE,
	ALT_PHONE,		EMAIL,			REGISTERED,		INTERESTS,
	MEDICAL
};

struct TableTitle
{
	TableTitle(int index, QString name) :
		index(index), string(name) {}

	int index;
	QString string;
};

class TableManager
{
public:
	TableManager(SimpleRegistry* sr, QTableView* tv);
	~TableManager() {}

	void AddPersonToTable(const Person& person);

	const std::array<TableTitle, 17> tableTitles = 
	{{
		{ static_cast<int>(TableTitleIndex::ID),			"Id" },
		{ static_cast<int>(TableTitleIndex::FIRST_NAME),	"First_Name" },
		{ static_cast<int>(TableTitleIndex::LAST_NAME),		"Last_Name" },
		{ static_cast<int>(TableTitleIndex::GENDER),		"Gender" },
		{ static_cast<int>(TableTitleIndex::DATE_OF_BIRTH),	"Date_of_Birth" },
		{ static_cast<int>(TableTitleIndex::AGE),			"Age" },
		{ static_cast<int>(TableTitleIndex::AGE_31),		"Age_Dec_31" },
		{ static_cast<int>(TableTitleIndex::GROUP),			"Group" },
		{ static_cast<int>(TableTitleIndex::PARENTS_NAME),	"Parents_Name" },
		{ static_cast<int>(TableTitleIndex::RELATIONSHIP),	"Relationship" },
		{ static_cast<int>(TableTitleIndex::HOME_ADDRESS),	"Address" },
		{ static_cast<int>(TableTitleIndex::PRIMARY_PHONE),	"Primary_#" },
		{ static_cast<int>(TableTitleIndex::ALT_PHONE),		"Alternate_#" },
		{ static_cast<int>(TableTitleIndex::EMAIL),			"Email" },
		{ static_cast<int>(TableTitleIndex::REGISTERED),	"Registered" },
		{ static_cast<int>(TableTitleIndex::INTERESTS),		"Interest" },
		{ static_cast<int>(TableTitleIndex::MEDICAL),		"Medical" }
	}};

private:
	SimpleRegistry* registry;
	QTableView* tableView;
};

class SimpleRegistry : public QMainWindow
{
	Q_OBJECT

public:
	SimpleRegistry();
	SimpleRegistry(std::unique_ptr<QSqlDatabase>&& db, QWidget* parent = Q_NULLPTR);
	~SimpleRegistry();

	void LoadTable();

	static int GetNextAvailableID();

public slots:
	void CreateParent() const;
	void CreateChild()  const;
	void Save();

protected:
	void customEvent(QEvent* event) override;
	void closeEvent (QCloseEvent* event) override;
	void resizeEvent(QResizeEvent* event) override;

private:
	Ui::SimpleRegistryClass ui;

	std::unique_ptr<QSqlDatabase> dataBase;

	std::unique_ptr<SRCreateParent> parentWindow;
	std::unique_ptr<SRCreateChild> childWindow;

	std::unique_ptr<TableManager> tableManager;
};

#endif