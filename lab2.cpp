/* Keilani Li
   Lab #2
   7/7/22 */ 

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define STATE_TAX 0.0725

int main()
{
	// declare variables & constants
	double cupertino, losaltos, sunnyvale, storeTotals;
	double countytaxTotal, statetaxTotal, taxTotals, saleTotal;
	string monthYr; // double works similarly to int
	const double countyTax = 0.01875; // value won't change
	
	// user inputs month&year and all store totals
	cout << "Enter Month & Year: ";
	getline(cin, monthYr);
	cout << "Enter Total Collected - Cupertino Store: ";
	cin >> cupertino;
	cout << "Enter Total Collected - Los Altos: ";
	cin >> losaltos;
	cout << "Enter Total Collected - Sunnyvale: ";
	cin >> sunnyvale;
	
	// totalling collected
	storeTotals = cupertino + losaltos + sunnyvale;
	cout << "Total amount of sales: " << storeTotals << endl << endl;

	// total sales
	// saleTotal = storeTotals - taxTotals;
	saleTotal = storeTotals/(1 + STATE_TAX + countyTax);
	
	// totalling sales tax
	countytaxTotal = saleTotal * countyTax;
	statetaxTotal = saleTotal * STATE_TAX;
	taxTotals = countytaxTotal + statetaxTotal;
		
	
	// all outputs
	cout << setprecision(2) << fixed;
	cout << "Month & Year: " << monthYr << endl;
	cout << "Total Collected:	" << setw(10) << storeTotals << endl;
	cout << "Sales:			" << setw(10) << saleTotal << endl;
	cout << "County Sales Tax: 	" << setw(10) << countytaxTotal << endl;
	cout << "State Sales Tax:	" << setw(10) << statetaxTotal << endl;
	cout << "Total Sales Tax:	" << setw(10) << taxTotals << endl << endl;
	
	
	cout << "Programmed by: Keilani Li" << endl;
	cout << "Lab #2" << endl;
	
	return 0;
}
/*
Enter Month & Year: July 2022
Enter Total Collected - Cupertino Store: 24300
Enter Total Collected - Los Altos: 34876
Enter Total Collected - Sunnyvale: 21999
Total amount of sales: 81175

Month & Year: July 2022
Total Collected:          81175.00
Sales:                    74387.17
County Sales Tax:          1394.76
State Sales Tax:           5393.07
Total Sales Tax:           6787.83

Programmed by: Keilani Li
Lab #2

--------------------------------
Process exited after 12.3 seconds with return value 0
Press any key to continue . . .
*/
