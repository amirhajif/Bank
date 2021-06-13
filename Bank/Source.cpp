#include <iostream>
#include <string>
#include "Header.h"
using namespace std;
void Date::printDate() { cout << this->year << "/" << this->month << "/" << this->day << endl; }
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}



Account::Account(string accountNUmber, Date creationDate, double balance)
{
	this->balance = balance;
	this->creationDate = creationDate;
	setAccountNumber(accountNUmber);
}
char* Account::getAccountNUmber() { return accountNumber; }
void Account::setDouble(double sample) { this->balance = sample; }
double Account::getBalance() { return balance; }
void Account::setAccountNumber(string sample)
{
	const char* data = sample.data();
	int length = sample.size();
	strncpy_s(accountNumber, data, length);
	accountNumber[length] = '\0';
}



Account Card::getAccount() { return this->linkAccount; }
Card::Card(Account linkAccount, string cvv2, string pass1, string pass2)
{
	this->linkAccount = linkAccount;
	setCvv2(cvv2);
	setPass1(pass1);
	setPass2(pass2);
}
void Card::setCvv2(string sample)
{
	const char* data = sample.data();
	int length = sample.size();
	strncpy_s(cvv2, data, length);
	cvv2[length] = '\0';
}
void Card::setPass1(string sample)
{
	const char* data = sample.data();
	int length = sample.size();
	strncpy_s(pass1, data, length);
	pass1[length] = '\0';
}
void Card::setPass2(string sample)
{
	const char* data = sample.data();
	int length = sample.size();
	strncpy_s(pass2, data, length);
	pass2[length] = '\0';
}

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


void Person::setName(string sample)
{
	const char* data = sample.data();
	int length = sample.size();
	strncpy_s(name, data, length);
	name[length] = '\0';
}
void Person::setLastName(string sample)
{
	const char* data = sample.data();
	int length = sample.size();
	strncpy_s(lastName, data, length);
	lastName[length] = '\0';
}
void Person::setNationalCode(string sample)
{
	const char* data = sample.data();
	int length = sample.size();
	strncpy_s(nationalCode, data, length);
	nationalCode[length] = '\0';
}
void Person::setWorkPlaceAddress(string sample)
{
	const char* data = sample.data();
	int length = sample.size();
	strncpy_s(workPlaceAddress, data, length);
	workPlaceAddress[length] = '\0';
}
void Person::setPhoneNumber(string sample)
{
	const char* data = sample.data();
	int length = sample.size();
	strncpy_s(phoneNumber, data, length);
	phoneNumber[length] = '\0';
}
void Person::setHomePhoneNumber(string sample)
{
	const char* data = sample.data();
	int length = sample.size();
	strncpy_s(homePhoneNumber, data, length);
	homePhoneNumber[length] = '\0';
}
void Person::setFatherName(string sample)
{
	const char* data = sample.data();
	int length = sample.size();
	strncpy_s(fatherName, data, length);
	fatherName[length] = '\0';
}




Costumer::Costumer(string name, string lastName, string nationalCode, string workPlaceAddress, string phoneNumber, string homePhoneNumber, string fatherName, Date birthDate, Date registerDate, string emailAddress, int customerId) :Person(name, lastName, nationalCode, workPlaceAddress, phoneNumber, homePhoneNumber, fatherName, birthDate)
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
void Costumer::setEmail(string sample)
{
	const char* data = sample.data();
	int length = sample.size();
	strncpy_s(emailAddress, data, length);
	emailAddress[length] = '\0';

}
int Costumer::getCustomerId() { return this->customerId; }
//////////////////////////////////////////////////////////////////////////////////////////////
Cheque::Cheque(Person payor, Person getter, int id, double amount)
{
	this->amount = amount;
	this->getter = getter;
	this->id = id;
	this->payor = payor;
}
//////////////////////////////////////////////////////////////////////////////////////////////
Clerk::Clerk(string name, string lastName, string nationalCode, string workPlaceAddress, string phoneNumber, string homePhoneNumber, string fatherName, Date birthDate, int clerkId, Date registerDate, double salary, string duty) :Person(name, lastName, nationalCode, workPlaceAddress, phoneNumber, homePhoneNumber, fatherName, birthDate)
{
	setDuty(duty);
	this->salary = salary;
	this->registerDate = registerDate;
	this->clerkId = clerkId;
}
int Clerk::getClerkId() { return this->clerkId; }
void Clerk::setDuty(string sample)
{
	const char* data = sample.data();
	int length = sample.size();
	strncpy_s(duty, data, length);
	duty[length] = '\0';

}
////////////////////////////////////////////////////////////////////////////////////////////////
void Bank::addClerk(Clerk sample)
{
	if (clerkCounter < 50)
		clerks[clerkCounter++] = sample;
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