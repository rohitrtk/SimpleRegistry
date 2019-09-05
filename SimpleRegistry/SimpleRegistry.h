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
	TableTitle(int index, QString&& name) : index(index), string(name) {}
	TableTitle(TableTitleIndex title, QString&& name) : index(static_cast<int>(title)), string(name) {}

	int index;
	QString string;
};

class TableManager
{
public:
	TableManager(QTableView* tv);
	~TableManager() {}

	void AddPersonToTable(const Person& person);
	/*
	static const TableTitle Id				(TableTitleIndex::ID,			"regsitered_id");
	static const TableTitle FirstName		(TableTitleIndex::FIRST_NAME,	"First_Name");
	static const TableTitle LastName		(TableTitleIndex::LAST_NAME,	"Last_Name");
	static const TableTitle Gender			(TableTitleIndex::GENDER,		"Gender");
	static const TableTitle Dob				(TableTitleIndex::DATE_OF_BIRTH,"Date_Of_Birth");
	static const TableTitle Age				(TableTitleIndex::AGE,			"Age");
	static const TableTitle Age31			(TableTitleIndex::AGE_31,		"Age_Dec_31");
	static const TableTitle Group			(TableTitleIndex::GROUP,		"Group");
	static const TableTitle ParentsName		(TableTitleIndex::PARENTS_NAME,	"Parent's_Name");
	static const TableTitle Relation		(TableTitleIndex::RELATIONSHIP,	"Relationship");
	static const TableTitle Address			(TableTitleIndex::HOME_ADDRESS,	"Address");
	static const TableTitle PrimaryPhone	(TableTitleIndex::PRIMARY_PHONE,"Primary_#");
	static const TableTitle SecondaryPhone	(TableTitleIndex::ALT_PHONE,	"Alternative_#");
	static const TableTitle EmailAddress	(TableTitleIndex::EMAIL,		"Email");
	static const TableTitle Registered		(TableTitleIndex::REGISTERED,	"Registered");
	static const TableTitle Interest		(TableTitleIndex::INTERESTS,	"Interest");
	static const TableTitle Medical			(TableTitleIndex::MEDICAL,		"regsitered_id");
	*/
private:
	QTableView* tableView;
};

class SimpleRegistry : public QMainWindow
{
	Q_OBJECT

public:
	SimpleRegistry();
	SimpleRegistry(std::unique_ptr<QSqlDatabase>&& db, QWidget* parent = Q_NULLPTR);
	~SimpleRegistry();

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

	void LoadTable();
};

#endif