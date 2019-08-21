#include "SRPopUp.h"

SRPopUp::SRPopUp(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(this->ui.pushButton, SIGNAL(clicked()), this, SLOT(OkPressed()));
}

SRPopUp::~SRPopUp()
{
}
