#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include "Header.h"

using namespace std;
void Date::printDate() { cout << this->year << "/" << this->month << "/" << this->day << endl; }
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}


Account::Account(char* accNumber,Date creationDate, double balance,char* ibanCode)
{
	for (int i = 0; i < 12; i++)
		accountNumber[i] = '\0';
	int length = strlen(accNumber);
	for (int i = 0; i < length; i++)
		accountNumber[i] = accNumber[i];

	for (int i = 0; i < 16; i++)
		IBAN[i] = '\0';
	length = strlen(ibanCode);
	for (int i = 0; i < length; i++)
		IBAN[i] = ibanCode[i];

	this->balance = balance;
	this->creationDate = creationDate;
}

char* Account::getAccountNUmber() { return accountNumber; }

void Account::setDouble(double sample) { this->balance = sample; }

double Account::getBalance() { return balance; }

Account Card::getAccount() { return this->linkAccount; }

char* Account::getIBAN()
{
	return IBAN;
}

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
string Person::getName()
{
	string fullname = "";
	for (int i = 0; i < strlen(name); i++)
		fullname += name[i];

	fullname += " ";

	for (int i = 0; i < strlen(lastName); i++)
		fullname += lastName[i];

	return fullname;

}

void Person::showInfo()
{
	cout << "\n---------------------------\n";
	cout << "name:\t" << name << endl;
	cout << "last name:\t" << lastName << endl;
	cout << "national code:\t" << nationalCode << endl;
	cout << "father name:\t" << fatherName << endl;
	cout << "work place address:\t" << workPlaceAddress << endl;
	cout << "phone number:\t" << phoneNumber << endl;
	cout << "home phone number:\t" << homePhoneNumber << endl;
	cout << "birthdate:\t";
	birthDate.printDate();
	cout << "\n---------------------------\n";
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

int isAccountNumberExist(Bank bank, char* code)
{
	for (int i = 0; i < bank.costomersCounter; i++)
	{
		for (int j = 0; j < bank.costumers[i].getAccountSize(); j++)
		{
			int counter = 0;
			for (int k = 0; k < 12; k++)
			{
				if (bank.costumers[i].getAccount(j).getAccountNUmber()[k] == code[k])
					counter++;
			}

			if (counter == 12)
				return j;
		}
	}
			
	return -1;
}

int isIbanCodeExist(Bank bank, char* code)
{
	for (int i = 0; i < bank.costomersCounter; i++)
	{
		for (int j = 0; j < bank.costumers[i].getAccountSize(); j++)
		{
			int counter = 0;
			for (int k = 0; k < 16; k++)
			{
				if (bank.costumers[i].getAccount(j).getIBAN()[k] == code[k])
					counter++;
			}

			if (counter == 16)
				return j;
		}
	}

	return -1;
}


int isCostumerIdExist(Bank bank, int code)
{
	for (int i = 0; i < bank.costomersCounter; i++)
		if (code == bank.costumers[i].getCustomerId())
			return i;

	return -1;
}

int isCardNumberExist(Bank bank, char* code)
{
	for (int i = 0; i < bank.costomersCounter; i++)
		for (int j = 0; j < bank.costumers[i].getCardSize(); j++)
		{
			int counter = 0;
			for (int k = 0; k < 16; k++)
			{
				if (bank.costumers[i].getCard(j).getCardNumber()[k] == code[k])
					counter++;
			}

			if (counter == 16)
				return j;
		}

	return -1;
}

void editCostumer(Bank* bank)
{
	cout << "enter your costumer id:\t";

	int id;
	cin >> id;

	int indexOfCostumer = isCostumerIdExist(*bank, id);
	if (indexOfCostumer == -1)
	{
		cout << "not found!\n";
		return;
	}
	else
	{
		cout << "enter what field want to edit:\n";
		cout << "1.work place address\n2.phone number\n3.home phone number\n";
		int opt;
		cin >> opt;

		cin.clear();
		cin.ignore();

		switch (opt)
		{
			case 1:
			{
				cout << "enter new workplace address:\n";
				
				string address;
				getline(cin, address);
				bank->costumers[indexOfCostumer].setWorkPlaceAddress(address);
				//update binary
				ofstream file("MyRecords.dat", ios::binary);
				file.write(reinterpret_cast<const char*>(&bank), sizeof(Bank));

				cout << "updated successfully!\n";

			}break;

			case 2:
			{
				cout << "enter new phone number:\t";
				string number;
				getline(cin, number);

				bank->costumers[indexOfCostumer].setPhoneNumber(number);
				//update binary
				ofstream file("MyRecords.dat", ios::binary);
				file.write(reinterpret_cast<const char*>(&bank), sizeof(Bank));

				cout << "updated successfully!\n";
			}break;

			case 3:
			{
				cout << "enter new home phone number:\t";
				string number;
				getline(cin, number);

				bank->costumers[indexOfCostumer].setHomePhoneNumber(number);
				//update binary
				ofstream file("MyRecords.dat", ios::binary);
				file.write(reinterpret_cast<const char*>(&bank), sizeof(Bank));

				cout << "updated successfully!\n";
			}break;

			default:
			{
				cout << "invalid command!\n";
				return;
			}
		}
	}
}

void getIbanCode(Bank bank)
{
	cout << "enter costumer id:\n";
	int costumerId;
	cin >> costumerId;

	int indexOfCostumer = isCostumerIdExist(bank, costumerId);

	if (indexOfCostumer == -1)
	{
		cout << "not found!\n";
		return;
	}
	else
	{
		cout << "enter account number:\t";

		cin.clear();
		cin.ignore();
		char accountNumber[13];
		cin.get(accountNumber, 13);

		int indexOfAccount = isAccountNumberExist(bank, accountNumber);
		if (indexOfAccount == -1)
		{
			cout << "not found!\n";
			return;
		}
		else
		{
			for (int i = 0; i < 16; i++)
				cout << bank.costumers[indexOfCostumer].getAccount(indexOfAccount).getIBAN()[i];
			cout << endl;
		}
	}
}

void editAccount(Bank)
{

}

void changeClerksDuty(Bank)
{

}

void editClerk(Bank* bank)
{
	cout << "enter clerk id:\t";
	int id;
	cin >> id;

	int index = isClerkIdExist(*bank, id);
	if (index == -1)
	{
		cout << "not found!\n";
		return;
	}

	cout << "enter what field want to edit:\n";
	cout << "1.work place address\n2.phone number\n3.home phone number\n4.duty\n";
	int opt;
	cin >> opt;

	cin.clear();
	cin.ignore();

	switch (opt)
	{
		case 1:
		{
			cout << "enter new workplace address:\n";

			string address;
			getline(cin, address);
			bank->clerks[index].setWorkPlaceAddress(address);
			//update binary
			ofstream file("MyRecords.dat", ios::binary);
			file.write(reinterpret_cast<const char*>(&bank), sizeof(Bank));

			cout << "updated successfully!\n";

		}break;

		case 2:
		{
			cout << "enter new phone number:\t";
			string number;
			getline(cin, number);

			bank->clerks[index].setPhoneNumber(number);
			//update binary
			ofstream file("MyRecords.dat", ios::binary);
			file.write(reinterpret_cast<const char*>(&bank), sizeof(Bank));

			cout << "updated successfully!\n";
		}break;

		case 3:
		{
			cout << "enter new home phone number:\t";
			string number;
			getline(cin, number);

			bank->clerks[index].setHomePhoneNumber(number);
			//update binary
			ofstream file("MyRecords.dat", ios::binary);
			file.write(reinterpret_cast<const char*>(&bank), sizeof(Bank));

			cout << "updated successfully!\n";
		}break;

		case 4:
		{
			cout << "enter new duty:\n";
			string duty;
			getline(cin, duty);

			int indexOfBoss = doesBossExist(*bank, "boss");
			if (indexOfBoss == -1)
			{
				bank->clerks[index].setDuty(duty);

				cout << "edited successfully!\n";

				//update binary
				ofstream file("MyRecords.dat", ios::binary);
				file.write(reinterpret_cast<const char*>(&bank), sizeof(Bank));
			}
			else
			{
				cout << "bank already have a boss!\n";
				return;
			}

		}break;

		default:
		{
			cout << "invalid command!\n";
			return;
		}
	}
}

void search(Bank)
{

}

void searchByName(Bank bank)
{
	cout << "enter the name:\t";
	string name;
	getline(cin, name);

	int index = isCostumerNameExist(bank, name);
	if (index == -1)
	{
		cout << "not found!\n";
		return;
	}
	
	bank.costumers[index].showInfo();
}

void searchByAccount(Bank)
{

}

void searchByCostumerId(Bank bank)
{
	cout << "enter costumer id:\t";
	int id;
	cin >> id;

	int index = isCostumerIdExist(bank, id);
	if (index == -1)
	{
		cout << "not exist!\n";
		return;
	}

	bank.costumers[index].showInfo();
}

void searchByCostumerAccounts(Bank bank)
{
	cout << "enter account number:\t";
	char accNumber[13];
	cin.get(accNumber, 13);

	int index = findCostumerByAccountNumber(bank, accNumber);

	if (index == -1)
	{
		cout << "not found!\n";
		return;
	}

	bank.costumers[index].showInfo();
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

char* createIbanCode()
{
	srand(time(0));
	static char ibanCode[16]{ '\0' };
	ibanCode[0] = 'I';
	ibanCode[1] = 'R';
	for (int i = 2; i < 16; i++)
	{
		switch (rand() % 10)
		{
		case 1:ibanCode[i] = '1'; break;
		case 2:ibanCode[i] = '2'; break;
		case 3:ibanCode[i] = '3'; break;
		case 4:ibanCode[i] = '4'; break;
		case 5:ibanCode[i] = '5'; break;
		case 6:ibanCode[i] = '6'; break;
		case 7:ibanCode[i] = '7'; break;
		case 8:ibanCode[i] = '8'; break;
		case 9:ibanCode[i] = '9'; break;
		case 0:ibanCode[i] = '0'; break;

		}
	}

	return ibanCode;
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
			if (isCostumerIdExist(bank, costumerId)==-1)
				break;
		}

		Costumer cs(name, lastName, nationalCode, workPlaceAddress, phoneNumber, homePhoneNumber, fatherName, birthDate, regDate, emailAddress, costumerId);

		char* accountNumber;
		while (true)
		{
			accountNumber = createAccountNumber();
			if (isAccountNumberExist(bank, accountNumber)==-1)
				break;
		}
		cout << "enter your account creation date(day month year -seperate with space-):\t";
		cin >> day >> month >> year;
		Date creationDate(day, month, month);

		cout << "enter your account balance:\t";
		int balance;
		cin >> balance;

		char* ibanCode;
		while (true)
		{
			ibanCode = createIbanCode();
			if (isIbanCodeExist(bank,ibanCode))
				break;
		}

		Account* ac=new Account(accountNumber, creationDate, balance,ibanCode);

		char* cardNumber;
		while (true)
		{
			cardNumber = createCardNumber();
			if (isCardNumberExist(bank, cardNumber)==-1)
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

		Card* card=new Card(cardNumber,*ac, cvv2, pass1, pass2);
		cs.addAccount(*ac);
		cs.addCard(*card);

		bank.addCostumer(cs);
		//update binary file --->sure???
		//edame chizaii k nvshti chi pas?
		ofstream file("MyRecords.dat", ios::binary);
		file.write(reinterpret_cast<const char*>(&bank), sizeof(Bank));
		
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
	srand(time(0));
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

int doesBossExist(Bank bank, string duty)
{
	for (int i = 0; i < bank.clerkCounter; i++)
		if (bank.clerks[i].getDuty() == duty)
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
		ofstream file("MyRecords.dat", ios::binary);
		file.write(reinterpret_cast<const char*>(&bank), sizeof(Bank));

		cout << "clerk with id " << cl.getClerkId() << " added successfully!\n";

	}
}

void addAccountToCostumer(Bank& bank)
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
			if (isAccountNumberExist(bank, newAccountNumber)==-1)
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

		char* ibanCode;
		while (true)
		{
			ibanCode = createIbanCode();
			if (isIbanCodeExist(bank, ibanCode))
				break;
		}

		bank.costumers[index].addAccount(Account(newAccountNumber, Date(day, month, year), balance, ibanCode));

		//update binary
		ofstream file("MyRecords.dat", ios::binary);
		file.write(reinterpret_cast<const char*>(&bank), sizeof(Bank));

		cout << "your account updated successfully!\n";
	}
}

void addCardToCostumerAccount(Bank& bank)
{
	cout << "enter costumer id:\t";
	int id;
	cin >> id;

	cin.clear();
	cin.ignore();

	int index = isCostumerIdExist(bank, id);
	if (index == -1)
	{
		cout << "not found!\n";
		return;
	}

	else
	{
		cout << "enter account number want to add card:\t";
		char accountNumber[13];
		cin.get(accountNumber, 13);

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

			cin.clear();
			cin.ignore();

			cout << "enter cvv2:\t";
			string cvv2;
			getline(cin, cvv2);

			cout << "enter pass1:\t";
			string pass1;
			getline(cin,pass1);

			cout << "enter pass2:\t";
			string pass2;
			getline(cin, pass2);


			cout << "card number:\n";
			for (int i = 0; i < 16; i++)
				cout << newCardNumber[i];
			
			cout << endl;

			Card card(newCardNumber, bank.costumers[index].getAccount(indexOfAccount), cvv2, pass1, pass2);
			bank.costumers[index].addCard(card);

			cout << "card added successfully!\n";

			//update binary
			ofstream file("MyRecords.dat", ios::binary);
			file.write(reinterpret_cast<const char*>(&bank), sizeof(Bank));
		}

	}
}

int isCostumerNameExist(Bank bank, string name)
{
	for (int i = 0; i < bank.costomersCounter; i++)
		if (bank.costumers[i].getName() == name)
			return i;
	return -1;
}

int findCostumerByAccountNumber(Bank bank, char* accNumber)
{
	for (int i = 0; i < bank.costomersCounter; i++)
	{
		for (int j = 0; j < bank.costumers[i].getAccountSize(); j++)
		{
			int counter = 0;
			for (int k = 0; k < 12; k++)
			{
				if (bank.costumers[i].getAccount(j).getAccountNUmber()[k] == accNumber[k])
					counter++;
			}

			if (counter == 12)
				return i;
		}
	}

	return -1;
	
}
void makeOrExistFile(string FileName,Bank &bank) {
	ifstream check(FileName,ios::binary);
	if (check)
	{
		check.read(reinterpret_cast<char*>(&bank), sizeof(Bank));
		check.close();
		return;
	}
	else
	{
		check.close();
		ofstream file(FileName, ios::binary);
		file.write(reinterpret_cast<const char*>(&bank), sizeof(Bank));
		return;
	}
}