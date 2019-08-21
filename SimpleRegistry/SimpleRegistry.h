#ifndef SIMPLE_REGISTRY_H_
#define SIMPLE_REGISTRY_H_

#include <QtWidgets/QMainWindow>
#include "ui_SimpleRegistry.h"
#include "SRConsants.h"
#include <memory>
#include <vector>
#include "SRCreateUser.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

class SimpleRegistry : public QMainWindow
{
	Q_OBJECT

public:
	SimpleRegistry(QWidget *parent = Q_NULLPTR);

	std::shared_ptr<sr::_ppl> GetPeople();

public slots:
	void ButtonClicked();
	void CreateParent();
	void CreateChild();

private:
	Ui::SimpleRegistryClass ui;

	std::shared_ptr<sr::_ppl> people;
	std::unique_ptr<SRCreateUser> createParentForm;
	std::unique_ptr<SRCreateUser> createChildForm;
};

#endif