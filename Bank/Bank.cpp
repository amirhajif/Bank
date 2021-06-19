#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "Header.h"
using namespace std;
 

int main()
{
	Bank* bank = new Bank();

	while (true)
	{
		cout << "1.add costumer\n2.add clerk\n";
		cout << "costumer services:\n";
		cout << "3.add account to costumer\n4.add card to costumer account\n5.edit costumer\n";
		cout << "bank services:\n";
		cout << "6.get iban code\n";

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
		}
	}
}