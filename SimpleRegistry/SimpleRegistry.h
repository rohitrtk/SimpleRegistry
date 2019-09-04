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
	ALLERGIES
};

class TableManager
{
public:
	TableManager(QTableView* tv);
	~TableManager() {}

	void AddPersonToTable(const Person& person);

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