#ifndef SIMPLE_REGISTRY_H_
#define SIMPLE_REGISTRY_H_

#include <QtWidgets/QMainWindow>
#include "ui_SimpleRegistry.h"
#include "SRCreateUser.h"
#include "SRConsants.h"
#include <memory>
#include <vector>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

class SimpleRegistry : public QMainWindow
{
	Q_OBJECT

public:
	SimpleRegistry(QWidget *parent = Q_NULLPTR);

	std::shared_ptr<sr::_ppl> GetPeople();

	void UpdateTable();

	

public slots:
	void CreateParent();
	void CreateChild();
	void customEvent(QEvent *event) override;

private:
	Ui::SimpleRegistryClass ui;

	std::shared_ptr<sr::_ppl> people;
	std::unique_ptr<SRCreateUser> createParentForm;
	std::unique_ptr<SRCreateUser> createChildForm;

	const sr::_int MinimumCols = 11;
	sr::_int currentRows;

	// List Titles
	const QString t_ID				= "ID";
	const QString t_FirstName		= "First Name";
	const QString t_LastName		= "Last Name";
	const QString t_Age				= "Age";
	const QString t_DOB				= "Date of Birth";
	const QString t_HomeAddress		= "Address";
	const QString t_HomePhone		= "Home Phone";
	const QString t_CellPhone		= "Cell Phone";
	const QString t_PrevLocation	= "Previous Location";
	const QString t_PrevAttended	= "Previously Attended";
	const QString t_YearsAttended	= "Years Attended";

	std::unique_ptr<QTableWidgetItem> w_ID;
	std::unique_ptr<QTableWidgetItem> w_FirstName;
	std::unique_ptr<QTableWidgetItem> w_LastName;
	std::unique_ptr<QTableWidgetItem> w_Age;
	std::unique_ptr<QTableWidgetItem> w_DOB;
	std::unique_ptr<QTableWidgetItem> w_HomeAddress;
	std::unique_ptr<QTableWidgetItem> w_HomePhone;
	std::unique_ptr<QTableWidgetItem> w_CellPhone;
	std::unique_ptr<QTableWidgetItem> w_PrevLocation;
	std::unique_ptr<QTableWidgetItem> w_PrevAttended;
	std::unique_ptr<QTableWidgetItem> w_YearsAttended;
};

#endif