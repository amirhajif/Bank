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
	int getDay();
	int getMonth();
	int getYear();
};
///////////////////////////////////////////////////////////////////////////////////////////////
class Account 
{
private:
	char accountNumber[12];
	Date creationDate;
	double balance;
	char IBAN[16];
public:
	Account() {}
	Account(char* accountNumber,Date creationDate, double balance,char* ibanCode);
	double getBalance();
	void setDouble(double sample);
	void setAccountNumber(string sample);
	void setIBN(string sample);
	char* getAccountNUmber();
	char* getIBAN();

};
//////////////////////////////////////////////////////////////////////////////////////////////////
class Card {
private:
	Account linkAccount;
	char cardNumber[16];
	char cvv2[4];
	char pass1[4];
	char pass2[8];
public:
	Card(string cardNumber,Account linkAccount, string cvv2, string pass1, string pass2);
	Card() {}
	Account getAccount();
	void setCvv2(string sample);
	void setPass1(string sample);
	void setPass2(string sample);
	void setCardNumber(string sample);
	char* getCardNumber();
};
///////////////////////////////////////////////////////////////////////////////////////////////////
class Person {
protected:
	char name[20];
	char lastName[20];
	char nationalCode[11];
	char workPlaceAddress[50];
	char phoneNumber[11];
	char homePhoneNumber[11];
	char fatherName[15];
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
	string getName();
	void showInfo();
	Date getBirthDate();
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
class Costumer :public Person {
private:
	Date registerDate;
	char emailAddress[20];
	//random account
	Account accounts[10];
	int accountCounter = 0;
	//random
	Card cards[20];
	int cardCounter = 0;
	//random
	int customerId;
public:
	Costumer() {}
	Costumer(string name, string lastName, string nationalCode, string workPlaceAddress, string phoneNumber, string homePhoneNumber, string fatherName, Date birthDate, Date registerDate, string emailAddress,int costumerId);
	void addAccount(Account sample);
	void addCard(Card sample);
	int getCustomerId();
	void setEmail(string sample);

	Account getAccount(int);
	int getAccountSize();

	Card getCard(int);
	int getCardSize();

	Date getRegDate();
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
	char* getDuty();
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Bank {
private:
	Costumer costumers[10];
	int costomersCounter;
	Clerk clerks[10];
	int clerkCounter;
	double balance;
public:
	Bank();
	void addCostumer(Costumer);
	void addClerk(Clerk);

	//shomare hesab mojode ya n
	friend int isAccountNumberExist(Bank, char*);
	
	//costuemr ba in id vojod dare?
	friend int isCostumerIdExist(Bank, int);
	
	//in shomare cart vojod dare?
	friend int isCardNumberExist(Bank, char*);
	

	friend void editCostumer(Bank*);
	
	//shomare shaba mide
	friend void getIbanCode(Bank);
	
	friend void editAccount(Bank*);
	
	friend void changeClerksDuty(Bank*);
	
	friend void editClerk(Bank*);
	
	friend void searchByName(Bank);
	
	friend void searchByAccount(Bank);
	
	friend void searchByCostumerId(Bank);
	
	friend void searchByCostumerAccounts(Bank);
	
	friend void findAccountsCards(Bank);
	
	friend void findCostumerCards(Bank);
	
	friend void showCostumersInfo(Bank);
	
	//peydakardane costuemr bar asase id
	friend void findCostumerById(Bank);
	
	//peyda kardane moshtari bar asase mojodi
	friend void findCostumerByBalance(Bank);

	//peyda kardane moshtari ghabl az ye tarikh khas
	friend void findCostumerBeforeDate(Bank);
	
	//peyda kardane moshtari ghabl az ye tarikh sabte name
	friend void findCostumerBeforeRegDate(Bank);
	
	friend void requestLoan(Bank);

	//costumer ba in code melli hast ya n
	friend int isCostumerExist(Bank, char*);
	
	//clerk ba in code melli hast ya n
	friend int isClerkExist(Bank, char*);
	
	//clerk ba in id vojod dare?
	friend int isClerkIdExist(Bank, int);
	
	//raees darim ya n
	friend int doesBossExist(Bank, string);
	
	//hesab be moshtari ezaf mikne
	friend void addAccountToCostumer(Bank&);
	
	//cart be hesab ezafe mkne
	friend void addCardToCostumerAccount(Bank&);
	
	//shomare shba mojode ya n
	friend int isIbanCodeExist(Bank, char*);
	
	//esm in costumer hast ya n
	friend int isCostumerNameExist(Bank, string);
	
	//peyda kardane costumer bar asase shomare hesab
	friend int findCostumerByAccountNumber(Bank, char*);


	Costumer getCostumers(int);
	int getCostumerCounter();

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

void addCostumer(Bank&);
int createCostumerId();
char* createAccountNumber();
char* createCardNumber();
void addClerk(Bank&);
int createClerkId();
void makeOrExistFile(Bank&);

