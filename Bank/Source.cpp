#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
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

char* Clerk::getDuty()
{
	return duty;
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

void addCostumer(Bank& bank)
{
	cout << "enter costumer infos:\n";

	cout << "enter national code:\t";
	char nationalCode[11];
	cin.get(nationalCode, 11);

	cin.clear();
	cin.ignore();

	if (isCostumerExist(bank, nationalCode) != -1)
	{
		cout << "this person is already exist in bank costumers list!\n";
		return;
	}
	else
	{
		cout << "enter name:\t";
		string name;
		getline(cin, name);

		cout << "enter last name:\t";
		string lastName;
		getline(cin, lastName);

		cout << "enter father name:\t";
		string fatherName;
		getline(cin, fatherName);

		cout << "enter work place address:\n";
		string workPlaceAddress;
		getline(cin, workPlaceAddress);

		cout << "enter phone number:\t";
		string phoneNumber;
		getline(cin, phoneNumber);

		cout << "enter home phone number:\t";
		string homePhoneNumber;
		getline(cin, homePhoneNumber);

		cout << "enter email address:\t";
		string emailAddress;
		getline(cin, emailAddress);

		cout << "enter birthDate(day month year -seperate with space-):\t";
		int year, month, day;
		cin >> day >> month >> year;
		Date birthDate(day, month, month);

		cout << "enter registerDate(day month year -seperate with space-):\t";
		cin >> day >> month >> year;
		Date regDate(day, month, month);

		int costumerId;
		while (true)
		{
			costumerId = createCostumerId();
			if (!isCostumerIdExist(bank, costumerId))
				break;
		}

		Costumer cs(name, lastName, nationalCode, workPlaceAddress, phoneNumber, homePhoneNumber, fatherName, birthDate, regDate, emailAddress, costumerId);

		char* accountNumber;
		while (true)
		{
			accountNumber = createAccountNumber();
			if (!isAccountNumberExist(bank, accountNumber))
				break;
		}
		cout << "enter your account creation date(day month year -seperate with space-):\t";
		cin >> day >> month >> year;
		Date creationDate(day, month, month);

		cout << "enter your account balance:\t";
		int balance;
		cin >> balance;

		Account ac(accountNumber, creationDate, balance);

		char* cardNumber;
		while (true)
		{
			cardNumber = createCardNumber();
			if (!isCardNumberExist(bank, cardNumber))
				break;
		}
		cin.clear();
		cin.ignore();


		cout << "enter card cvv2:\t";
		string cvv2;
		getline(cin, cvv2);

		cout << "enter card pass 1:\t";
		string pass1;
		getline(cin, pass1);

		cout << "enter card pass 2:\t";
		string pass2;
		getline(cin, pass2);

		Card card(cardNumber, ac, cvv2, pass1, pass2);

		cs.addAccount(ac);
		cs.addCard(card);

		//update binary file
		cout << "costuemr added successfully!\n";

		cout << "your infos(write or save it someWhere):\n";
		cout << "costumer id:\t" << cs.getCustomerId() << endl;
		cout << "account number:\t";
		for (int i = 0; i < 12; i++)
			cout << cs.getAccount(0).getAccountNUmber()[i];
		cout << endl;
		cout << "card number:\t";
		for (int i = 0; i < 16; i++)
			cout << cs.getCard(0).getCardNumber()[i];

		cout << endl;
	}
}

char* createAccountNumber()
{
	srand(time(0));
	static char accountNumber[12]{ '\0' };
	for (int i = 0; i < 12; i++)
	{
		switch (rand() % 10)
		{
			case 1:accountNumber[i] = '1'; break;
			case 2:accountNumber[i] = '2'; break;
			case 3:accountNumber[i] = '3'; break;
			case 4:accountNumber[i] = '4'; break;
			case 5:accountNumber[i] = '5'; break;
			case 6:accountNumber[i] = '6'; break;
			case 7:accountNumber[i] = '7'; break;
			case 8:accountNumber[i] = '8'; break;
			case 9:accountNumber[i] = '9'; break;
			case 0:accountNumber[i] = '0'; break;

		}
	}

	return accountNumber;
}

int createCostumerId()
{
	return rand() % (9999 - 1000) + 1000;
}

char* createCardNumber()
{
	srand(time(0));
	static char cardNumber[16] = { '\0' };
	for (int i = 0; i < 16; i++)
	{
		switch (rand() % 10)
		{
			case 1:cardNumber[i] = '1'; break;
			case 2:cardNumber[i] = '2'; break;
			case 3:cardNumber[i] = '3'; break;
			case 4:cardNumber[i] = '4'; break;
			case 5:cardNumber[i] = '5'; break;
			case 6:cardNumber[i] = '6'; break;
			case 7:cardNumber[i] = '7'; break;
			case 8:cardNumber[i] = '8'; break;
			case 9:cardNumber[i] = '9'; break;
			case 0:cardNumber[i] = '0'; break;
		}
	}

	return cardNumber;
}

int createClerkId()
{
	return rand() % (99999 - 10000) + 10000;
}

int isClerkIdExist(Bank bank,int id)
{
	for (int i = 0; i < bank.clerkCounter; i++)
		if (id == bank.clerks[i].getClerkId())
			return i;

	return -1;
}

int doesBossExist(Bank bank, string id)
{
	for (int i = 0; i < bank.clerkCounter; i++)
		if (bank.clerks[i].getDuty() == id)
			return i;

	return -1;
}

void addClerk(Bank& bank)
{
	cout << "enter clerk infos:\n";

	cout << "enter national code:\t";
	char nationalCode[11];
	cin.get(nationalCode, 11);

	cin.clear();
	cin.ignore();

	if (isClerkExist(bank, nationalCode) != -1)
	{
		cout << "this person is already exist in bank clerks list!\n";
		return;
	}
	else
	{
		cout << "enter name:\t";
		string name;
		getline(cin, name);

		cout << "enter last name:\t";
		string lastName;
		getline(cin, lastName);

		cout << "enter father name:\t";
		string fatherName;
		getline(cin, fatherName);

		cout << "enter work place address:\n";
		string workPlaceAddress;
		getline(cin, workPlaceAddress);

		cout << "enter phone number:\t";
		string phoneNumber;
		getline(cin, phoneNumber);

		cout << "enter home phone number:\t";
		string homePhoneNumber;
		getline(cin, homePhoneNumber);


		cout << "enter birthDate(day month year -seperate with space-):\t";
		int year, month, day;
		cin >> day >> month >> year;
		Date birthDate(day, month, month);

		cout << "enter registerDate(day month year -seperate with space-):\t";
		cin >> day >> month >> year;
		Date regDate(day, month, month);

		int clerkId;
		while (true)
		{
			clerkId = createClerkId();
			if (isClerkIdExist(bank, clerkId)==-1)
				break;
		}

		cout << "enter clerk salary:\t";
		double salary;
		cin >> salary;

		cin.clear();
		cin.ignore();

		cout << "enter clerk duty:\t";
		string duty;
		while (true)
		{
			getline(cin, duty);
			if (doesBossExist(bank, duty)!=-1)
				cout << "already have boss,enter another duty!\n";
			else
				break;
		}


		Clerk cl(name, lastName, nationalCode, workPlaceAddress, phoneNumber, homePhoneNumber, fatherName, birthDate, clerkId, regDate, salary, duty);

		bank.addClerk(cl);

		//update binary file

		cout << "clerk with id " << cl.getClerkId() << " added successfully!\n";

	}
}

void addAccountToCostumer(Bank bank)
{
	cout << "enter costumer id:\t";
	int id;
	cin >> id;

	int index = isCostumerIdExist(bank, id);
	if (index == -1)
	{
		cout << "not found!\n";
		return;
	}

	else
	{
		cout << "you have " << bank.costumers[index].getAccountSize() << " accounts\n";
		char* newAccountNumber = createAccountNumber();
		while (true)
		{
			if (isAccountNumberExist(bank, newAccountNumber) == -1)
				break;
		}

		cout << "enter the balance of account:\t";
		double balance;
		cin >> balance;

		int day, month, year;
		cout << "enter creation date(day month year -seperate with space-):\t";
		cin >> day >> month >> year;

		cout << "new account number added:\n";
		for (int i = 0; i < 12; i++)
			cout << newAccountNumber[i];
		cout << endl;

		bank.costumers[index].addAccount(Account(newAccountNumber, Date(day, month, year), balance));

		//update binary

		cout << "your account updated successfully!\n";
	}
}

void addCardToCostumerAccount(Bank bank)
{
	cout << "enter costumer id:\t";
	int id;
	cin >> id;

	int index = isCostumerIdExist(bank, id);
	if (index == -1)
	{
		cout << "not found!\n";
		return;
	}

	else
	{
		cout << "enter account number want to add card:\t";
		char accountNumber[12];
		cin.get(accountNumber, 12);

		int indexOfAccount = isAccountNumberExist(bank, accountNumber);
		if (indexOfAccount == -1)
		{
			cout << "not found!\n";
			return;
		}

		else
		{
			char* newCardNumber = createCardNumber();
			while (true)
			{
				if (isCardNumberExist(bank, newCardNumber) == -1)
					break;
			}

			cout << "enter cvv2:\t";
			char cvv2[4];
			cin.get(cvv2, 4);

			cout << "enter pass1:\t";
			char pass1[4];
			cin.get(pass1, 4);

			cout << "enter pass2:\t";
			char pass2[8];
			cin.get(pass2, 8);

			cout << "card number:\n";
			for (int i = 0; i < 16; i++)
				cout << newCardNumber[i];
			
			cout << endl;

			Card card(newCardNumber, bank.costumers[index].getAccount(indexOfAccount), cvv2, pass1, pass2);
			bank.costumers[index].addCard(card);

			cout << "card added successfully!\n";

			//update binary
		}

	}
}