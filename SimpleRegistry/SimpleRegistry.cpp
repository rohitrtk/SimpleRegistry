#include "SimpleRegistry.h"
#include "Person.h"
#include <QDebug>

SimpleRegistry::SimpleRegistry(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	HomeAddress ha = { 4747, "Wee Woo Dr", "", "Goober Town", "Goob", "GOO BER" };
	Parent p1("Potato", "Lord", 20, QDate(1,1,1), ha, "PotatoLord1234@hotmail.com", "1234567890");
	qInfo() << p1.GetInfoAsString().c_str();
}
