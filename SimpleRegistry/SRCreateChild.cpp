#include "SRCreateChild.h"
#include "ui_SRCreateChild.h"
#include <QMessageBox>

SRCreateChild::SRCreateChild(SimpleRegistry* mainWindow, QWidget *parent)
	: QWidget(parent), mainWindow(mainWindow)
{
	ui = new Ui::SRCreateChild();
	ui->setupUi(this);

	this->ui->lineEdit_firstName	->installEventFilter(this);
	this->ui->lineEdit_lastName		->installEventFilter(this);
	this->ui->comboBox_gender		->installEventFilter(this);
	this->ui->dateEdit_dateOfBirth	->installEventFilter(this);
	this->ui->lineEdit_homeAddress	->installEventFilter(this);
	this->ui->lineEdit_homePhone	->installEventFilter(this);
	this->ui->lineEdit_cellPhone	->installEventFilter(this);
	this->ui->lineEdit_emailAddress	->installEventFilter(this);
	this->ui->checkBox_prevAttended	->installEventFilter(this);
	this->ui->lineEdit_prevLocation	->installEventFilter(this);
	this->ui->spinBox_yearsAttended	->installEventFilter(this);
	this->ui->lineEdit_allergies	->installEventFilter(this);
	this->ui->lineEdit_interests	->installEventFilter(this);

	this->ui->comboBox_gender		->addItem("Male");
	this->ui->comboBox_gender		->addItem("Female");

	this->ui->label_firstName		->setText(ui->label_firstName->text() + "*");
	this->ui->label_lastName		->setText(ui->label_lastName->text() + "*");
	this->ui->label_dateOfBirth		->setText(ui->label_dateOfBirth->text() + "*");
	this->ui->checkBox_prevAttended	->setText(ui->checkBox_prevAttended->text() + "*");
	this->ui->label_prevLocation	->setText(ui->label_prevLocation->text() + "*");
	this->ui->label_yearsAttended	->setText(ui->label_yearsAttended->text() + "*");

	this->setWindowTitle("Create Child");
}

SRCreateChild::~SRCreateChild()
{
	delete ui;
}

void SRCreateChild::MakeFirstName(PersonBuilder<Child>& builder)
{
	QString firstName = ui->lineEdit_firstName->text();
	if (!firstName.isEmpty())
	{
		builder.FirstName(std::move(firstName));
		return;
	}

	this->paramMissing = true;
}

void SRCreateChild::MakeLastName(PersonBuilder<Child>& builder)
{
	QString lastName = ui->lineEdit_lastName->text();
	if (!lastName.isEmpty())
	{
		builder.LastName(std::move(lastName));
		return;
	}

	this->paramMissing = true;
}

void SRCreateChild::MakeDateOfBirth(PersonBuilder<Child>& builder)
{
	builder.DateOfBirth(QDate(ui->dateEdit_dateOfBirth->date()));
}

void SRCreateChild::MakeGender(PersonBuilder<Child>& builder)
{
	QString gender = ui->comboBox_gender->currentText();
	builder.Gender(gender);
}

void SRCreateChild::MakeHomeAddress(PersonBuilder<Child>& builder)
{
	QString s = ui->lineEdit_homeAddress->text();

	builder.HomeAddress(std::move(s));
}

void SRCreateChild::MakeHomePhone(PersonBuilder<Child>& builder)
{
	QString s = ui->lineEdit_homePhone->text();

	builder.HomePhone(std::move(s));
}

void SRCreateChild::MakeCellPhone(PersonBuilder<Child>& builder)
{
	QString s = ui->lineEdit_cellPhone->text();

	builder.CellPhone(std::move(s));
}

void SRCreateChild::MakeEmailAddress(PersonBuilder<Child>& builder)
{
	QString email = ui->lineEdit_emailAddress->text();

	builder.EmailAddress(std::move(email));
}

void SRCreateChild::MakePrevAttended(PersonBuilder<Child>& builder)
{
	Qt::CheckState check = ui->checkBox_prevAttended->checkState();

	if (check == Qt::Checked) builder.PrevAttended(true);
	else if (check == Qt::Unchecked) builder.PrevAttended(false);
}

void SRCreateChild::MakePrevLocation(PersonBuilder<Child>& builder)
{
	QString prevLocation = ui->lineEdit_prevLocation->text();

	if (prevLocation.isEmpty())
	{
		this->paramMissing = true;
		return;
	}

	builder.PrevLocation(prevLocation);
}

void SRCreateChild::MakeYearsAttended(PersonBuilder<Child>& builder)
{
	builder.YearsAttended(ui->spinBox_yearsAttended->value());
}

void SRCreateChild::MakeAllergies(PersonBuilder<Child>& builder)
{
	QString s = ui->lineEdit_allergies->text();

	builder.Allergies(s);
}

void SRCreateChild::Create()
{
	this->paramMissing = false;

	PersonBuilder<Child> builder;

	MakeFirstName(builder);
	MakeLastName(builder);
	MakeDateOfBirth(builder);
	MakeGender(builder);
	MakeHomeAddress(builder);
	MakeHomePhone(builder);
	MakeCellPhone(builder);
	MakeEmailAddress(builder);
	MakePrevAttended(builder);
	MakePrevLocation(builder);
	MakeYearsAttended(builder);
	MakeAllergies(builder);

	if (this->paramMissing)
	{
		QString s("Missing one or more fields(*) to create parent!");
		QMessageBox::information(this, "Error", s);

		return;
	}

	this->user = builder.Build();

	QApplication::postEvent(mainWindow, new SRUserCreatedEvent(*this->user));
}

void SRCreateChild::Cancel()
{
	this->close();
}

void SRCreateChild::Clear()
{

}