#include <QtWidgets/QApplication>
#include "SimpleRegistry.h"
#include "SRCreateUser.h"
#include "SRLogin.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//SimpleRegistry* sr = new SimpleRegistry();
	//sr->setAttribute(Qt::WA_DeleteOnClose);
	//sr->show();

	SRLogin* login = new SRLogin();
	login->setAttribute(Qt::WA_DeleteOnClose);
	login->show();

	return a.exec();
}
