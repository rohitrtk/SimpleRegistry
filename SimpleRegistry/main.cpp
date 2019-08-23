#include "SimpleRegistry.h"
#include <QtWidgets/QApplication>
#include "SRCreateUser.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	SimpleRegistry* sr = new SimpleRegistry();
	sr->setAttribute(Qt::WA_DeleteOnClose);
	sr->show();

	return a.exec();
}
