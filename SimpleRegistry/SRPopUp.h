#pragma once

#include <QWidget>
#include "ui_SRPopUp.h"

#define FIELD_MISSING_MSG "Missing one or more fields\nto create"

class SRPopUp : public QWidget
{
	Q_OBJECT

public:
	SRPopUp(QWidget *parent = Q_NULLPTR);
	~SRPopUp();

	inline void SetMessage(QString message)
	{
		this->ui.label->setText(message);
	}

public slots:
	inline void OkPressed() { this->close(); }

private:
	Ui::SRPopUp ui;
};
