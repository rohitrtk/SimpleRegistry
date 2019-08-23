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

constexpr qint16 MinimumCols = 12;

class SimpleRegistry : public QMainWindow
{
	Q_OBJECT

public:
	SimpleRegistry(QWidget *parent = Q_NULLPTR);

	const std::vector<std::unique_ptr<Person>>& GetPeople();

	void UpdateTable(const PersonType& personType);	

public slots:
	void CreateParent();
	void CreateChild();

protected:
	void customEvent(QEvent *event) override;
	void closeEvent(QCloseEvent* event) override;

private:
	Ui::SimpleRegistryClass ui;

	std::vector<std::unique_ptr<Person>> people;

	std::unique_ptr<SRCreateUser> parentWindow;
	std::unique_ptr<SRCreateUser> childWindow;

	void UserCreated(SRUserCreatedEvent* event);
};

#endif