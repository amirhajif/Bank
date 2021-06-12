#include <iostream>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date(){}
	Date(int day, int month, int year);
	void printDate();
};
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month =month;
	this->year = year;
}
void Date::printDate() { cout << this->year << "/" << this->month << "/" << this->day<<endl; }
//-------------------------------------------------------end of class date------------------------------------------------
class Account {
private:
	char accountNumber[16];
	Date creationDate;
	double balance;
public:
	Account(){}
	Account(string accountNUmber, Date creationDate, double balance);
	void setAccountNumber(string sample)
	{
		const char* data = sample.data();
		int length = sample.size();
		strncpy_s(accountNumber, data, length);
		accountNumber[length] = '\0';
	}
	double getBalamce() { return balance; }
	void setDouble(double sample) { this->balance = sample; }
	char* getAccountNUmber() { return accountNumber; }
};
Account::Account(string accountNUmber, Date creationDate, double balance)
{
	this->balance = balance;
	this->creationDate = creationDate;
	setAccountNumber(accountNUmber);
}
//-------------------------------------------------------end of class Account---------------------------------------------
class Card {
private:
	Account linkAccount;
	char cvv2[4];
	char pass1[20];
	char pass2[20];
public:
	Card(Account linkAccount, string cvv2, string pass1, string pass2);
	Card(){}
	Account getAccount();
	void setCvv2(string sample)
	{
		const char* data = sample.data();
		int length = sample.size();
		strncpy_s(cvv2, data, length);
		cvv2[length] = '\0';
	}
	void setPass1(string sample)
	{
		const char* data = sample.data();
		int length = sample.size();
		strncpy_s(pass1, data, length);
		pass1[length] = '\0';
	}
	void setPass2(string sample)
	{
		const char* data = sample.data();
		int length = sample.size();
		strncpy_s(pass2, data, length);
		pass2[length] = '\0';
	}

};
Account Card::getAccount() { return this->linkAccount; }
Card::Card(Account linkAccount, string cvv2, string pass1, string pass2)
{
	this->linkAccount = linkAccount;
	setCvv2(cvv2);
	setPass1(pass1);
	setPass2(pass2);
}
//-------------------------------------------------------end of class Card------------------------------------------------
class Person {
protected:
	char name[20];
	char lastName[20];
	char nationalCode[11];
	char workPlaceAddress[100];
	char phoneNumber[11];
	char homePhoneNumber[11];
	char fatherName[20];
	Date birthDate;
public:
	Person(){}
	Person(string name, string lastName, string nationalCode, string workPlaceAddress, string phoneNumber, string homePhoneNumber, string fatherName, Date birthDate);
	string getNationalCode();
	void setName(string sample)
	{
		const char* data = sample.data();
		int length = sample.size();
		strncpy_s(name, data, length);
		name[length] = '\0';
	}
	void setLastName(string sample)
	{
		const char* data = sample.data();
		int length = sample.size();
		strncpy_s(lastName, data, length);
		lastName[length] = '\0';
	}
	void setNationalCode(string sample)
	{
		const char* data = sample.data();
		int length = sample.size();
		strncpy_s(nationalCode, data, length);
		nationalCode[length] = '\0';
	}
	void setWorkPlaceAddress(string sample)
	{
		const char* data = sample.data();
		int length = sample.size();
		strncpy_s(workPlaceAddress, data, length);
		workPlaceAddress[length] = '\0';
	}
	void setPhoneNumber(string sample)
	{
		const char* data = sample.data();
		int length = sample.size();
		strncpy_s(phoneNumber, data, length);
		phoneNumber[length] = '\0';
	}
	void setHomePhoneNumber(string sample)
	{
		const char* data = sample.data();
		int length = sample.size();
		strncpy_s(homePhoneNumber, data, length);
		homePhoneNumber[length] = '\0';
	}
	void setFatherName(string sample)
	{
		const char* data = sample.data();
		int length = sample.size();
		strncpy_s(fatherName, data, length);
		fatherName[length] = '\0';
	}
};
Person::Person(string name, string lastName, string nationalCode, string workPlaceAddress, string phoneNumber, string homePhoneNumber, string fatherName, Date birthDate) {
	setName(name);
	setLastName(lastName);
	setNationalCode(nationalCode);
	setWorkPlaceAddress(workPlaceAddress);
	setPhoneNumber(phoneNumber);
	setHomePhoneNumber(homePhoneNumber);
	setFatherName(fatherName);
	this->birthDate = birthDate;
}
string Person::getNationalCode() { return this->nationalCode; }
//-----------------------------------------------------end of class person------------------------------------------------
class Cheque {
private:
	Person payor;
	Person getter;
	int id;
	double amount;
public:
	Cheque(Person payor, Person getter, int id, double amount);
	Cheque() {}
};
Cheque::Cheque(Person payor, Person getter, int id, double amount)
{
	this->amount = amount;
	this->getter = getter;
	this->id = id;
	this->payor = payor;
}
//-------------------------------------------------------end of class Cheque----------------------------------------------
class Costumer :public Person {
private:
	Date registerDate;
	char emailAddress[30];
	Account accounts[20];
	int accountCounter = 0;
	Card cards[20];
	int cardCounter = 0;
	int customerId;
public:
	Costumer(){}
	Costumer(string name, string lastName, string nationalCode, string workPlaceAddress, string phoneNumber, string homePhoneNumber, string fatherName, Date birthDate, Date registerDate, string emailAddress, int customerId);
	void addAccount(Account sample);
	void addCard(Card sample);
	int getCustomerId();
	void setEmail(string sample)
	{
		const char* data = sample.data();
		int length = sample.size();
		strncpy_s(emailAddress, data, length);
		emailAddress[length] = '\0';

	}
};
Costumer::Costumer(string name, string lastName, string nationalCode, string workPlaceAddress, string phoneNumber, string homePhoneNumber, string fatherName, Date birthDate, Date registerDate, string emailAddress, int customerId):Person(name, lastName, nationalCode, workPlaceAddress, phoneNumber, homePhoneNumber, fatherName, birthDate)
{
	this->registerDate = registerDate;
	this->customerId = customerId;
	setEmail(emailAddress);
}
void Costumer::addAccount(Account sample)
{
	if (accountCounter < 20)
		accounts[accountCounter++] = sample;
	else
		cout << "your account is full!!\n";
}
void Costumer::addCard(Card sample)
{
	if (cardCounter < 20)
		cards[cardCounter++] = sample;
	else
		cout << "your account is full!!\n";
}
int Costumer::getCustomerId() { return this->customerId; }
//------------------------------------------------------end of costumer---------------------------------------------------
class Clerk:public Person {
private:
	int clerkId;
	Date registerDate;
	double salary;
	char duty[10];
public:
	Clerk(){}
	Clerk(string name, string lastName, string nationalCode, string workPlaceAddress, string phoneNumber, string homePhoneNumber, string fatherName, Date birthDate, int clerkId, Date registerDate, double salary, string duty);
	void setDuty(string sample)
	{
		const char* data = sample.data();
		int length = sample.size();
		strncpy_s(duty, data, length);
		duty[length] = '\0';
		
	}
	int getClerkId();
};
Clerk::Clerk(string name, string lastName, string nationalCode, string workPlaceAddress, string phoneNumber, string homePhoneNumber, string fatherName, Date birthDate, int clerkId, Date registerDate, double salary, string duty):Person(name,lastName,nationalCode,workPlaceAddress,phoneNumber,homePhoneNumber,fatherName,birthDate)
{
	setDuty(duty);
	this->salary = salary;
	this->registerDate = registerDate;
	this->clerkId = clerkId;
}
int Clerk::getClerkId() { return this->clerkId; }
//------------------------------------------------------end of clerk------------------------------------------------------
class Bank {
private:
	Costumer costumers[100];
	int costomersCounter=0;
	Clerk clerks[50];
	int clerkCounter = 0;
	double balance;
public:
	Bank();
	void addCostumer(Costumer sample);
	void addClerk(Clerk sample);
};
void Bank::addClerk(Clerk sample)
{
	if (clerkCounter < 50)
		clerks[clerkCounter++]=sample;
	else
		cout << "Clerk is full!!!\n";
}
void Bank::addCostumer(Costumer sample)
{
	if (costomersCounter < 100)
		costumers[costomersCounter++] = sample;
	else
		cout << "costumer is full\n";
}
Bank::Bank() { balance = 100000000; }
//------------------------------------------------------end of Back-------------------------------------------------------
int main()
{
 
}
