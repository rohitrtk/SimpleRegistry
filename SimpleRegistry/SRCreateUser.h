#ifndef SRCreateUser_H_
#define SRCreateUser_H_

#include <QWidget>
#include "ui_SRCreateUser.h"
#include "SRConsants.h"
#include "SRPerson.h"
#include <sstream>
#include <string>
#include <memory>

class PersonBuilder;
class SimpleRegistry;
class SRUserCreatedEventFilter;
class QString;
class QEvent;
class QCheckBox;

class SRCreateUser : public QWidget
{
	Q_OBJECT
public:
	SRCreateUser(QWidget *parent = Q_NULLPTR);
	~SRCreateUser();

	void SetupWindow(SimpleRegistry* mainWindow, sr::PersonType type = sr::PersonType::PARENT);

	inline void SetPersonList(std::vector<std::unique_ptr<Person>>& list) { this->personList = &list; }

public slots:
	void Create();
	void Cancel();
	void Clear();
	void HandlePrevAttended(int state);

protected:
	bool eventFilter(QObject *watched, QEvent *event) override;

private:
	Ui::SRCreateUser ui;

	SimpleRegistry* mainWindow;

	sr::PersonType personType;

	static qint16 idAssign;

	const unsigned short int WindowWidth	= 500;
	const unsigned short int WindowHeight	= 500;

	const QString WindowTitleParent = "Create New Parent";
	const QString WindowTitleChild  = "Create New Child";
	
	std::vector<std::unique_ptr<Person>>* personList;
	bool paramMissing;

	void MakeFirstName		(PersonBuilder& builder);
	void MakeLastName		(PersonBuilder& builder);
	void MakeDateOfBirth	(PersonBuilder& builder);
	void MakeGender			(PersonBuilder& builder);

	void MakeHomeAddress	(PersonBuilder& builder);
	void MakeHomePhone		(PersonBuilder& builder);
	void MakeCellPhone		(PersonBuilder& builder);
	void MakeEmailAddress	(PersonBuilder& builder);
	
	void MakePrevAttended	(PersonBuilder& builder);
	void MakePrevLocation	(PersonBuilder& builder);
	void MakeYearsAttended	(PersonBuilder& builder);

	void MakeAllergies		(PersonBuilder& builder);

	void MakeParents		(PersonBuilder& builder);
	void MakeChildren		(PersonBuilder& builder);

	void ParamMissing(const sr::PersonType&& type);
};

const QEvent::Type USER_CREATED_EVENT = static_cast<QEvent::Type>(4747);

class SRUserCreatedEvent : public QEvent
{
public:
	SRUserCreatedEvent(const sr::PersonType& personType) :
		QEvent(USER_CREATED_EVENT),
		personType(personType) {}

	inline const sr::PersonType& GetPersonType() const { return this->personType; }

private:
	sr::PersonType personType;
};

#endif