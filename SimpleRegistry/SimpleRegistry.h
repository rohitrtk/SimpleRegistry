#ifndef SIMPLE_REGISTRY_H_
#define SIMPLE_REGISTRY_H_

#include <QtWidgets/QMainWindow>
#include "ui_SimpleRegistry.h"
#include "SRCreateUser.h"
#include "SRConsants.h"
#include <memory>
#include <vector>
#include <array>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

class TableManager
{
public:
	TableManager() = delete;
	TableManager(QTableWidget* tw, std::vector<std::unique_ptr<Person>>* people);
	~TableManager() {}

	void AddPersonToTable(Person* person);

private:
	QTableWidget* tableWidget;
	std::vector<std::unique_ptr<Person>>* people;
};

class SimpleRegistry : public QMainWindow
{
	Q_OBJECT

public:
	SimpleRegistry(QWidget *parent = Q_NULLPTR);

	const std::vector<std::unique_ptr<Person>>& GetPeople();

	void UpdateTable(const sr::PersonType& personType);	

public slots:
	void CreateParent();
	void CreateChild();

protected:
	void customEvent(QEvent *event) override;
	void closeEvent(QCloseEvent* event) override;

private:
	Ui::SimpleRegistryClass ui;

	qint16 MinimumCols;

	std::vector<std::unique_ptr<Person>> people;

	std::unique_ptr<SRCreateUser> parentWindow;
	std::unique_ptr<SRCreateUser> childWindow;

	std::unique_ptr<TableManager> tableManager;

	void UserCreated(SRUserCreatedEvent* event);
};

#endif