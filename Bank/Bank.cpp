#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "Header.h"
using namespace std;
  
void addCostumer(Bank&);
int createCostumerId();
char* createAccountNumber();
char* createCardNumber();

int main()
{
	Bank* bank = new Bank();

	while (true)
	{
		cout << "1.add costumer\n2.add clerk\n";

		int opt;
		cin >> opt;

		cin.clear();
		cin.ignore();

		switch (opt)
		{
			case 1:addCostumer(*bank); break;
		}
	}
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
			if (!isAccountNumberExist(bank, cardNumber))
				break;
		}

		cin.clear();
		cin.ignore();

		cout << "enter card cvv2:\t";
		string cvv2 = "asdas";
		//getline(cin, cvv2);

		cout << "enter card pass 1:\t";
		string pass1 = "asdas";
		//getline(cin, pass1);

		cout << "enter card pass 2:\t";
		string pass2 = "1245";
		//getline(cin, pass2);

		Card card(cardNumber, ac, cvv2, pass1, pass2);
		cs.addAccount(ac);
		cs.addCard(card);
	}
}

char* createAccountNumber()
{
	srand(time(0));
	static char accountNumber[12];
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
	static char cardNumber[16];
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