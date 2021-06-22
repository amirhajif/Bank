#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "Header.h"
#include "Source.cpp"

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
		cout << "8.search by name\n9.search by costumer id\n10.search by account number\n";
		int opt;
		cin >> opt;

		cin.clear();
		cin.ignore();

		switch (opt)
		{
			case 1:addCostumer(*bank); break;//finish
			case 2:addClerk(*bank); break;//finish
			case 3:addAccountToCostumer(*bank); break;//finish
			case 4:addCardToCostumerAccount(*bank); break;//finish
			case 5:editCostumer(bank); break;//finish
			case 6:getIbanCode(*bank); break;//dont need file
			case 7:editClerk(bank); break;//finish
			case 8:searchByName(*bank); break;//dont need file
			case 9:searchByCostumerId(*bank); break;//dont need file
			case 10:searchByCostumerAccounts(*bank); break;//dont need file
		}
	}
}