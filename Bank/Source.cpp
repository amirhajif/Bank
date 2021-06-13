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


Account::Account(char* accNumber,Date creationDate, double balance)
{
	int length = strlen(accNumber);
	for (int i = 0; i < length; i++)
		accountNumber[i] = accNumber[i];

	this->balance = balance;
	this->creationDate = creationDate;
}

char* Account::getAccountNUmber() { return accountNumber; }

void Account::setDouble(double sample) { this->balance = sample; }

double Account::getBalance() { return balance; }

Account Card::getAccount() { return this->linkAccount; }

Card::Card(string cardNumber,Account linkAccount, string cvv2, string pass1, string pass2)
{
	setCardNumber(cardNumber);
	this->linkAccount = linkAccount;
	setCvv2(cvv2);
	setPass1(pass1);
	setPass2(pass2);

}

void Card::setCardNumber(string sample)
{
	for (int i = 0; i < 16; i++)
		cardNumber[i] = sample[i];
}

void Card::setCvv2(string sample)
{
	for (int i = 0; i < 4; i++)
		cvv2[i] = sample[i];
}
void Card::setPass1(string sample)
{
	for (int i = 0; i < 4; i++)
		pass1[i] = sample[i];
}
void Card::setPass2(string sample)
{
	for (int i = 0; i < 8; i++)
		pass2[i] = sample[i];
}
char* Card::getCardNumber()
{
	char* sample = new char[16]{'\0'};
	for (int i = 0; i < 16; i++)
		sample[i] = cardNumber[i];
	return sample;
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




Costumer::Costumer(string name, string lastName, string nationalCode, string workPlaceAddress, string phoneNumber, string homePhoneNumber, string fatherName, Date birthDate, Date registerDate, string emailAddress,int costumerId) :Person(name, lastName, nationalCode, workPlaceAddress, phoneNumber, homePhoneNumber, fatherName, birthDate)
{
	this->customerId = costumerId;
	this->registerDate = registerDate;
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

Account Costumer::getAccount(int i)
{
	return accounts[i];
}

int Costumer::getAccountSize()
{
	return accountCounter;
}

Card Costumer::getCard(int i)
{
	return cards[i];
}

int Costumer::getCardSize()
{
	return cardCounter;
}
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

Bank::Bank() 
{	balance = 100000000;	
	clerkCounter=0;
	costomersCounter=0;
}

bool isAccountNumberExist(Bank bank, char* code)
{
	for (int i = 0; i < bank.costomersCounter; i++)
		for (int j = 0; j < bank.costumers[i].getAccountSize(); j++)
			if (bank.costumers[i].getAccount(j).getAccountNUmber() == code)
				return true;

	return false;
}

bool isCostumerIdExist(Bank bank, int code)
{
	for (int i = 0; i < bank.costomersCounter; i++)
		if (code == bank.costumers[i].getCustomerId())
			return true;

	return false;
}

bool isCardNumberExist(Bank bank, char* code)
{
	for (int i = 0; i < bank.costomersCounter; i++)
		for (int j = 0; j < bank.costumers[i].getCardSize(); j++)
			if (bank.costumers[i].getCard(j).getCardNumber() == code)
				return true;

	return false;
}

void editCostumer(Bank)
{

}

void getIbanCode(Bank)
{

}

void editAccount(Bank)
{

}

void changeClerksDuty(Bank)
{

}

void editClerk(Bank)
{

}

void search(Bank)
{

}

void searchByName(Bank)
{

}

void searchByAccount(Bank)
{

}

void searchByCostumerId(Bank)
{

}

void searchByCostumerAccounts(Bank)
{

}

void findAccountsCards(Bank)
{

}

void findyCostumerCards(Bank)
{

}

void showCostumersInfo(Bank)
{

}

void findCostumerById(Bank)
{

}

void findCostumerByBalance(Bank)
{

}

void findCostumerBeforeDate(Bank)
{
	
}

void findCostumerBeforeRegDate(Bank)
{

}

void requestLoan(Bank)
{

}

int isCostumerExist(Bank bank, char* code)
{
	for (int i = 0; i < bank.costomersCounter; i++)
		if (bank.costumers[i].getNationalCode() == code)
			return i;
	return -1;
}

int isClerkExist(Bank bank, char* code)
{
	for (int i = 0; i < bank.clerkCounter; i++)
		if (bank.clerks[i].getNationalCode() == code)
			return i;
	return -1;
}


