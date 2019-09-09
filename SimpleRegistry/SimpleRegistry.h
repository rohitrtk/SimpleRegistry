#ifndef SIMPLE_REGISTRY_H_
#define SIMPLE_REGISTRY_H_

#include <QtWidgets/QMainWindow>
#include "ui_SimpleRegistry.h"

#include <memory>
#include <unordered_map>

#ifdef QT_DEBUG
	#define LOG(x) qInfo() << x
#else
	#define LOG(x) x
#endif

class SimpleRegistry;

class Person;
class SRCreateParent;
class SRCreateChild;

class QTableView;
class QSqlDatabase;
class QModelIndex;
class QString;

/* Enum containing name to int mappings of the MySQL table headers */
enum class TableTitleIndex
{
	ID,				FIRST_NAME,		LAST_NAME,		GENDER,
	DATE_OF_BIRTH,	AGE,			AGE_31,			GROUP,
	PARENTS_NAME,	RELATIONSHIP,	HOME_ADDRESS,	PRIMARY_PHONE,
	ALT_PHONE,		EMAIL,			REGISTERED,		INTERESTS,
	MEDICAL
}; // TableTitleIndex

/* Handler for the main windows QTableView object */
class TableManager
{
public:
	TableManager(SimpleRegistry& sr);
	~TableManager() {}

	void AddPersonToTable(const Person& person);
	void DeleteSelectedRow();
	void LoadTable();

	std::unordered_map<TableTitleIndex, QString> Titles;

private:
	SimpleRegistry& registry;
	QTableView&		tableView;
	QSqlDatabase&	database;
}; // TableManager

/* Main window class */
class SimpleRegistry : public QMainWindow
{
	Q_OBJECT
private:
	Ui::SimpleRegistryClass ui;

	std::unique_ptr<QSqlDatabase>	dataBase;
	std::unique_ptr<SRCreateParent> parentWindow;
	std::unique_ptr<SRCreateChild>	childWindow;
	std::unique_ptr<TableManager>	tableManager;

public:
	SimpleRegistry() = delete;
	SimpleRegistry(std::unique_ptr<QSqlDatabase>&& db, QWidget* parent = Q_NULLPTR);
	~SimpleRegistry();

	static int GetNextAvailableID();

	QTableView&		GetTableView()	const;
	QSqlDatabase&	GetDatabase()	const;

public slots:
	void CreateParent()							const;
	void CreateChild()							const;
	void DoubleClick(const QModelIndex& index)	const;

protected:
	void customEvent(QEvent* event)				override;
	void closeEvent (QCloseEvent* event)		override;
	void resizeEvent(QResizeEvent* event)		override;
	void keyPressEvent(QKeyEvent* event)		override;

}; // SimpleRegistry

#endif