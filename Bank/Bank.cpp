#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "Header.h"

#define binaryFileName "MyRecords.dat"
using namespace std;
 

int main()
{
	Bank* bank = new Bank();
	makeOrExistFile(*bank);
 
	while (true)
	{
		cout << "1.add costumer\n2.add clerk\n";
		cout << "costumer services:\n";
		cout << "3.add account to costumer\n4.add card to costumer account\n5.edit costumer\n";
		cout << "account services:\n";
		cout << "6.get iban code\n";
		cout << "clerks services:\n";
		cout << "7.edit clerk\n";
		cout << "bank services:\n";
		cout << "8.search by name\n9.search by costumer id\n10.search by account number\n11.show all account of a costumer\n" <<
			"12.find costumer cards\n13.find card\n14.find costumer by account number\n15.find costumer by card number\n" <<
			"16.find costumer by date\n17.find costumer by balance\n18.find costumers before a specific date\n19.find costumer before reg date\n" <<
			"20.request loan\n";
		int opt;
		cin >> opt;

		cin.clear();
		cin.ignore();

		switch (opt)
		{
			case 1:addCostumer(*bank); break;
			case 2:addClerk(*bank); break;
			case 3:addAccountToCostumer(*bank); break;
			case 4:addCardToCostumerAccount(*bank); break;
			case 5:editCostumer(bank); break;
			case 6:getIbanCode(*bank); break;
			case 7:editClerk(bank); break;
			case 8:searchByName(*bank); break;
			case 9:searchByCostumerId(*bank); break;
			case 10:searchByCostumerAccounts(*bank); break;
			case 11:findCostumerAccount(*bank); break;
			case 12:findCostumerCards(*bank); break;
			case 13:findAccountsCards(*bank); break;
			case 14:findCostumerByAcNumber(*bank); break;
			case 15:findCsotumerBycardnumber(*bank); break;
			case 16:findCostumerByDate(*bank); break;
			case 17:findCostumerByBalance(*bank); break;
			case 18:findCostumerBeforeDate(*bank); break;
			case 19:findCostumerBeforeRegDate(*bank); break;
			case 20:requestLoan(bank); break;
		}
	}
}