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

	std::shared_ptr<sr::_ppl> GetPeople();

	void UpdateTable(const PersonType& personType);	

public slots:
	void CreateParent();
	void CreateChild();

protected:
	void customEvent(QEvent *event) override;

private:
	Ui::SimpleRegistryClass ui;

	std::shared_ptr<sr::_ppl> people;
	std::unique_ptr<SRCreateUser> createParentForm;
	std::unique_ptr<SRCreateUser> createChildForm;

	void UserCreated(SRUserCreatedEvent *event);
};

#endif