#include <iostream>
using namespace std;
class Date {

private:
	int day;
	int month;
	int year;
public:
	Date() {}
	Date(int day, int month, int year);
	void printDate();
};
///////////////////////////////////////////////////////////////////////////////////////////////
class Account {
private:
	char accountNumber[16];
	Date creationDate;
	double balance;
public:
	Account() {}
	Account(string accountNUmber, Date creationDate, double balance);
	double getBalance();
	void setAccountNumber(string sample);
	void setDouble(double sample);
	char* getAccountNUmber();

};
//////////////////////////////////////////////////////////////////////////////////////////////////
class Card {
private:
	Account linkAccount;
	char cvv2[4];
	char pass1[20];
	char pass2[20];
public:
	Card(Account linkAccount, string cvv2, string pass1, string pass2);
	Card() {}
	Account getAccount();
	void setCvv2(string sample);
	void setPass1(string sample);
	void setPass2(string sample);
};
///////////////////////////////////////////////////////////////////////////////////////////////////
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
	Person() {}
	Person(string name, string lastName, string nationalCode, string workPlaceAddress, string phoneNumber, string homePhoneNumber, string fatherName, Date birthDate);
	string getNationalCode();
	void setName(string sample);
	void setLastName(string sample);
	void setNationalCode(string sample);
	void setWorkPlaceAddress(string sample);
	void setPhoneNumber(string sample);
	void setHomePhoneNumber(string sample);
	void setFatherName(string sample);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
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
	Costumer() {}
	Costumer(string name, string lastName, string nationalCode, string workPlaceAddress, string phoneNumber, string homePhoneNumber, string fatherName, Date birthDate, Date registerDate, string emailAddress, int customerId);
	void addAccount(Account sample);
	void addCard(Card sample);
	int getCustomerId();
	void setEmail(string sample);
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Clerk :public Person {
private:
	int clerkId;
	Date registerDate;
	double salary;
	char duty[10];
public:
	Clerk() {}
	Clerk(string name, string lastName, string nationalCode, string workPlaceAddress, string phoneNumber, string homePhoneNumber, string fatherName, Date birthDate, int clerkId, Date registerDate, double salary, string duty);
	void setDuty(string sample);
	int getClerkId();
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Bank {
private:
	Costumer costumers[100];
	int costomersCounter = 0;
	Clerk clerks[50];
	int clerkCounter = 0;
	double balance;
public:
	Bank();
	void addCostumer(Costumer sample);
	void addClerk(Clerk sample);
	friend void editCostumer(Bank sample);
	friend void getIbanCode(Bank sample);
	friend void editAccount(Bank sample);
	friend void changeClerksDuty(Bank sample);
	friend void editClerk(Bank sample);
	friend void search(Bank sample);
	friend void searchByName(Bank sample);
	friend void searchByAccount(Bank sample);
	friend void searchByCostumerId(Bank sample);
	friend void searchByCostumerAccounts(Bank sample);
	friend void findAccountsCards(Bank sample);
	friend void findyCostumerCards(Bank sample);
	friend void showCostumersInfo(Bank sample);
	friend void findCostumerById(Bank sample);
	friend void findCostumerByBalance(Bank sample);
	friend void findCostumerBeforeDate(Bank sample);
	friend void findCostumerBeforeRegDate(Bank sample);
	friend void requestLoan(Bank sample);

};
//////////////////////////////////////////////////////////////////////////////////////////////////////
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
