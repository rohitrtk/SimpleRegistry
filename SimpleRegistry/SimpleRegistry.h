#ifndef SIMPLE_REGISTRY_H_
#define SIMPLE_REGISTRY_H_

#include <QtWidgets/QMainWindow>
#include "ui_SimpleRegistry.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

class SimpleRegistry : public QMainWindow
{
	Q_OBJECT

public:
	SimpleRegistry(QWidget *parent = Q_NULLPTR);

public slots:
	void ButtonClicked();

private:
	Ui::SimpleRegistryClass ui;
};

#endif