#include "SRCreateParent.h"
#include <QMessageBox>

SRCreateParent::SRCreateParent(SimpleRegistry* mainWindow, QWidget *parent)
	: QWidget(parent), mainWindow(mainWindow)
{
	ui.setupUi(this);

	this->ui.lineEdit_firstName		->installEventFilter(this);
	this->ui.lineEdit_lastName		->installEventFilter(this);
	this->ui.comboBox_gender		->installEventFilter(this);
	this->ui.dateEdit_dateOfBirth	->installEventFilter(this);
	this->ui.lineEdit_homeAddress	->installEventFilter(this);
	this->ui.lineEdit_homePhone		->installEventFilter(this);
	this->ui.lineEdit_cellPhone		->installEventFilter(this);
	this->ui.lineEdit_emailAddress	->installEventFilter(this);
	this->ui.lineEdit_allergies		->installEventFilter(this);
	this->ui.lineEdit_interests		->installEventFilter(this);

	this->ui.comboBox_gender		->addItem("Male");
	this->ui.comboBox_gender		->addItem("Female");

	this->ui.label_firstName		->setText(ui.label_firstName->text() + "*");
	this->ui.label_lastName			->setText(ui.label_lastName->text() + "*");
	this->ui.label_dateOfBirth		->setText(ui.label_dateOfBirth->text() + "*");
	this->ui.label_homeAddress		->setText(ui.label_homeAddress->text() + "*");
	this->ui.label_homePhone		->setText(ui.label_homePhone->text() + "*");
	this->ui.label_cellPhone		->setText(ui.label_cellPhone->text() + "*");
	this->ui.label_emailAddress		->setText(ui.label_emailAddress->text() + "*");

	this->setWindowTitle("Create Parent");

	connect(ui.pushButton_clear,  SIGNAL(clicked()), this, SLOT(Clear()));
	connect(ui.pushButton_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
	connect(ui.pushButton_create, SIGNAL(clicked()), this, SLOT(Create()));
}

SRCreateParent::~SRCreateParent()
{
}

void SRCreateParent::MakeFirstName(PersonBuilder<Parent>& builder)
{
	QString firstName = ui.lineEdit_firstName->text();
	if (!firstName.isEmpty())
	{
		builder.FirstName(std::move(firstName));
		return;
	}

	this->paramMissing = true;
}

void SRCreateParent::MakeLastName(PersonBuilder<Parent>& builder)
{
	QString lastName = ui.lineEdit_lastName->text();
	if (!lastName.isEmpty())
	{
		builder.LastName(std::move(lastName));
		return;
	}

	this->paramMissing = true;
}

void SRCreateParent::MakeDateOfBirth(PersonBuilder<Parent>& builder)
{
	builder.DateOfBirth(QDate(ui.dateEdit_dateOfBirth->date()));
}

void SRCreateParent::MakeGender(PersonBuilder<Parent>& builder)
{
	QString gender = ui.comboBox_gender->currentText();
	builder.Gender(gender);
}

void SRCreateParent::MakeHomeAddress(PersonBuilder<Parent>& builder)
{
	QString s = ui.lineEdit_homeAddress->text();

	if (s.isEmpty())
	{
		this->paramMissing = true;
		return;
	}

	builder.HomeAddress(std::move(s));
}

void SRCreateParent::MakePrimaryPhone(PersonBuilder<Parent>& builder)
{
	QString s = ui.lineEdit_homePhone->text();

	if (s.isEmpty())
	{
		this->paramMissing = true;
		return;
	}

	builder.PrimaryPhone(std::move(s));
}

void SRCreateParent::MakeSecondaryPhone(PersonBuilder<Parent>& builder)
{
	QString s = ui.lineEdit_cellPhone->text();

	if (s.isEmpty())
	{
		this->paramMissing = true;
		return;
	}

	builder.SecondaryPhone(std::move(s));
}

void SRCreateParent::MakeEmailAddress(PersonBuilder<Parent>& builder)
{
	QString email = ui.lineEdit_emailAddress->text();

	if (email.isEmpty())
	{
		this->paramMissing = true;
		return;
	}

	builder.EmailAddress(std::move(email));
}

void SRCreateParent::MakeMedical(PersonBuilder<Parent>& builder)
{
	QString s = ui.lineEdit_allergies->text();

	builder.Medical(s);
}

void SRCreateParent::Create()
{
	this->paramMissing = false;

	PersonBuilder<Parent> builder;

	MakeFirstName(builder);
	MakeLastName(builder);
	MakeDateOfBirth(builder);
	MakeGender(builder);
	MakeHomeAddress(builder);
	MakePrimaryPhone(builder);
	MakeSecondaryPhone(builder);
	MakeEmailAddress(builder);
	MakeMedical(builder);

	if (this->paramMissing)
	{
		QString s("Missing one or more fields(*) to create parent!");
		QMessageBox::information(this, "Error", s);

		return;
	}

	this->user = builder.Build();

	QApplication::postEvent(mainWindow, new SRUserCreatedEvent(*this->user));
}

void SRCreateParent::Cancel()
{
	this->close();
}

void SRCreateParent::Clear()
{
	this->ui.lineEdit_firstName		->setText("");
	this->ui.lineEdit_lastName		->setText("");
	this->ui.comboBox_gender		->setCurrentIndex(0);
	this->ui.dateEdit_dateOfBirth	->setDate(QDate(2000, 1, 31));
	this->ui.lineEdit_homeAddress	->setText("");
	this->ui.lineEdit_homePhone		->setText("");
	this->ui.lineEdit_cellPhone		->setText("");
	this->ui.lineEdit_emailAddress	->setText("");
	this->ui.lineEdit_children		->setText("");
	this->ui.lineEdit_allergies		->setText("");
	this->ui.lineEdit_interests		->setText("");
}
