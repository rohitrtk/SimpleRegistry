#ifndef SIMPLE_REGISTRY_H_
#define SIMPLE_REGISTRY_H_

#include <QtWidgets/QMainWindow>
#include "ui_SimpleRegistry.h"
#include <memory>
#include <vector>
#include "SRConsants.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

class Person;

class SimpleRegistry : public QMainWindow
{
	Q_OBJECT

public:
	SimpleRegistry(QWidget *parent = Q_NULLPTR);

public slots:
	void ButtonClicked();

	inline sr_ppl& GetPeople() { return this->people; }

private:
	Ui::SimpleRegistryClass ui;

	sr_ppl people;
};

#endif