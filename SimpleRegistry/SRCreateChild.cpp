#include "SRCreateChild.h"

#include <QMessageBox>
#include <QKeyEvent>
#include <QHideEvent>

#include "SRPerson.h"

SRCreateChild::SRCreateChild(SimpleRegistry* mainWindow, QWidget *parent)
	: QWidget(parent), mainWindow(mainWindow)
{
	ui.setupUi(this);

	this->ui.comboBox_gender		->addItem(ComboBoxGender_Male);
	this->ui.comboBox_gender		->addItem(ComboBoxGender_Female);

	this->ui.comboBox_relation		->addItem(ComboBoxRelation_Parents);
	this->ui.comboBox_relation		->addItem(ComboBoxRelation_Mother);
	this->ui.comboBox_relation		->addItem(ComboBoxRelation_Father);
	this->ui.comboBox_relation		->addItem(ComboBoxRelation_Guardian);

	this->ui.label_firstName		->setText(ui.label_firstName->text() + "*");
	this->ui.label_lastName			->setText(ui.label_lastName->text() + "*");
	this->ui.label_dateOfBirth		->setText(ui.label_dateOfBirth->text() + "*");
	this->ui.label_relation			->setText(ui.label_relation->text() + "*");
	this->ui.checkBox_prevAttended	->setText(ui.checkBox_prevAttended->text() + "*");
	this->ui.label_yearsAttended	->setText(ui.label_yearsAttended->text() + "*");

	this->setWindowTitle(WindowTitle_CreateChild);

	connect(ui.pushButton_clear,  SIGNAL(clicked()), this, SLOT(Clear()));
	connect(ui.pushButton_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
	connect(ui.pushButton_create, SIGNAL(clicked()), this, SLOT(Create()));

	this->ui.spinBox_yearsAttended->setEnabled(false);
}

SRCreateChild::~SRCreateChild()
{
}

void SRCreateChild::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Tab)
	{
		QWidget::focusNextChild();
	}
}

void SRCreateChild::hideEvent(QHideEvent*)
{
	this->Clear();
}

void SRCreateChild::MakeFirstName(PersonBuilder<Child>& builder)
{
	QString firstName = ui.lineEdit_firstName->text();
	if (!firstName.isEmpty())
	{
		builder.FirstName(std::move(firstName));
		return;
	}

	this->paramMissing = true;
}

void SRCreateChild::MakeLastName(PersonBuilder<Child>& builder)
{
	QString lastName = ui.lineEdit_lastName->text();
	if (!lastName.isEmpty())
	{
		builder.LastName(std::move(lastName));
		return;
	}

	this->paramMissing = true;
}

void SRCreateChild::MakeDateOfBirth(PersonBuilder<Child>& builder)
{
	builder.DateOfBirth(QDate(ui.dateEdit_dateOfBirth->date()));
}

void SRCreateChild::MakeGender(PersonBuilder<Child>& builder)
{
	QString gender = ui.comboBox_gender->currentText();
	builder.Gender(gender);
}

void SRCreateChild::MakeHomeAddress(PersonBuilder<Child>& builder)
{
	QString s = ui.lineEdit_homeAddress->text();

	builder.HomeAddress(std::move(s));
}

void SRCreateChild::MakePrimaryPhone(PersonBuilder<Child>& builder)
{
	QString s = ui.lineEdit_homePhone->text();

	builder.PrimaryPhone(std::move(s));
}

void SRCreateChild::MakeSecondaryPhone(PersonBuilder<Child>& builder)
{
	QString s = ui.lineEdit_cellPhone->text();

	builder.SecondaryPhone(std::move(s));
}

void SRCreateChild::MakeEmailAddress(PersonBuilder<Child>& builder)
{
	QString email = ui.lineEdit_emailAddress->text();

	builder.EmailAddress(std::move(email));
}

void SRCreateChild::MakePrevAttended(PersonBuilder<Child>& builder)
{
	Qt::CheckState check = ui.checkBox_prevAttended->checkState();

	if (check == Qt::Checked) builder.PrevAttended(true);
	else if (check == Qt::Unchecked) builder.PrevAttended(false);
}

void SRCreateChild::MakeMedical(PersonBuilder<Child>& builder)
{
	QString s = ui.lineEdit_allergies->text();

	builder.Medical(s);
}

void SRCreateChild::MakeInterests(PersonBuilder<Child>& builder)
{
	QString s = ui.lineEdit_interests->text();

	builder.Interests(s);
}

void SRCreateChild::MakeParents(PersonBuilder<Child>& builder)
{
	QString s = ui.lineEdit_parentGuardians->text();

	builder.Parents(s);
}

void SRCreateChild::MakeRelation(PersonBuilder<Child>& builder)
{
	QString s = ui.comboBox_relation->currentText();

	builder.Relation(s);
}

void SRCreateChild::Create()
{
	this->paramMissing = false;

	PersonBuilder<Child> builder;

	MakeFirstName		(builder);
	MakeLastName		(builder);
	MakeDateOfBirth		(builder);
	MakeGender			(builder);
	MakeHomeAddress		(builder);
	MakePrimaryPhone	(builder);
	MakeSecondaryPhone	(builder);
	MakeEmailAddress	(builder);
	MakePrevAttended	(builder);
	MakeMedical			(builder);
	MakeInterests		(builder);
	MakeParents			(builder);
	MakeRelation		(builder);

	if (this->paramMissing)
	{
		QString s("Missing one or more fields(*) to create child!");
		QMessageBox::information(this, "Error", s);

		return;
	}

	this->user = builder.Build();

	QApplication::postEvent(reinterpret_cast<QObject*>(mainWindow), new SRUserCreatedEvent(*this->user));
}

void SRCreateChild::Cancel()
{
	this->close();
}

void SRCreateChild::Clear()
{
	this->ui.lineEdit_firstName			->setText("");
	this->ui.lineEdit_lastName			->setText("");
	this->ui.comboBox_gender			->setCurrentIndex(0);
	this->ui.dateEdit_dateOfBirth		->setDate(QDate(2000, 1, 31));
	this->ui.lineEdit_homeAddress		->setText("");
	this->ui.lineEdit_homePhone			->setText("");
	this->ui.lineEdit_cellPhone			->setText("");
	this->ui.lineEdit_emailAddress		->setText("");
	this->ui.lineEdit_parentGuardians	->setText("");
	this->ui.checkBox_prevAttended		->setChecked(false);
	this->ui.spinBox_yearsAttended		->setValue(0);
	this->ui.lineEdit_allergies			->setText("");
	this->ui.lineEdit_interests			->setText("");
}