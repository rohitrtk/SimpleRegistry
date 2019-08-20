#include "SimpleRegistry.h"
#include <QtWidgets/QApplication>
#include "SRCreateParent.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	SimpleRegistry sr;
	sr.show();

	SRCreateParent s;
	s.SetPersonList(&sr.GetPeople());
	s.show();

	return a.exec();
}
