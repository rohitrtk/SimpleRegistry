#ifndef SIMPLE_REGISTRY_H_
#define SIMPLE_REGISTRY_H_

#include <QtWidgets/QMainWindow>
#include "ui_SimpleRegistry.h"
#include "SRCreateUser.h"
#include "SRConsants.h"
#include <memory>
#include <vector>
#include <array>

enum class TableTitleIndex
{
	ID,				TYPE,			FIRST_NAME,
	LAST_NAME,		GENDER,			AGE,
	DOB,			GROUP,			ADDRESS,
	HOME_PHONE,		CELL_PHONE,		EMAIL_ADDRESS,
	PREV_ATTENDED,	PREV_LOCATION,	YEARS_ATTENDED,
	PARENTS,		CHILDREN,		ALLERGIES
};

class TableManager
{
public:
	TableManager(QTableWidget* tw);
	~TableManager() {}

	void AddPersonToTable(const Person& person);

	inline const QTableWidget&	GetTableWidget() const { return *this->tableWidget; }
	inline const QStringList&	GetTableTitles() const { return this->tableTitles; }

private:
	QTableWidget* tableWidget;
	QStringList tableTitles;
};

class SimpleRegistry : public QMainWindow
{
	Q_OBJECT

public:
	SimpleRegistry(QWidget* parent = Q_NULLPTR);
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

	std::unique_ptr<SRCreateUser> parentWindow;
	std::unique_ptr<SRCreateUser> childWindow;

	std::unique_ptr<TableManager> tableManager;

	void MakeWindow(const sr::PersonType&& person) const;
};

#endif