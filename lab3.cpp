/* Keilani Li
   keilanili@gmail.com
   Lab #3
   7/11/22 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define TAX_RATE 0.0913 // santa clara county tax rate

int main() {
	
	// declare item's values
	const double tvPrice = 379.00;
	const double theatreSysPrice = 429.99;
	const double remoteConPrice = 35.20;
	const double dvrPrice = 149.98;
	const double bluRayPrice = 248.00;
	const double projectorPrice = 1300.00;
	
	// declare variables for each item's quantity + their own subtotals
	int tv, theatreSys, remoteCon, dvr, bluRay, projector; // type int variable is used bc you cant buy half of an item
	double tvTotal, theatreSysTotal, remoteConTotal, dvrTotal, bluRayTotal, projectorTotal;
	
	// declare variables when calculating overall totals
	double subtotal, taxTotal, total;
	
	// inputting quantity of each sold item
	cout << "How many TVs were sold? ";
	cin >> tv;
	
	cout << "How many Theatre system units were sold? ";
	cin >> theatreSys;
	
	cout << "How many Remote Controller units were sold? ";
	cin >> remoteCon;
	
	cout << "How many DVRs were sold? ";
	cin >> dvr;
	
	cout << "How many Blu-Ray Disc Players were sold? ";
	cin >> bluRay;
	
	cout << "How many Projectors were sold? ";
	cin >> projector; 
	
	cout << endl; 
	
	// calculating subtotals for each item
	tvTotal = tvPrice * tv;
	theatreSysTotal = theatreSysPrice * theatreSys;
	remoteConTotal = remoteConPrice * remoteCon;
	dvrTotal = dvrPrice * dvr;
	bluRayTotal = bluRayPrice * bluRay;
	projectorTotal = projectorPrice * projector;
	
	// calculating overall totals
	subtotal = tvTotal + theatreSysTotal + remoteConTotal + dvrTotal + bluRayTotal + projectorTotal;
	taxTotal = TAX_RATE * subtotal;
	total = subtotal + taxTotal;
	
	// outputting item quantity, description, unit price, item subtotals
	cout << setw(10) << "QTY\t" << "Description\t\t" << "  Unit Price\t\t" << "Total Price" << endl;
	
	cout << fixed << setprecision(2); // numbers stop at 2 decimal places
	
	cout << setw(10) << tv << "\tTV			" << setw(10) << tvPrice << " 		" << setw(10) << tvTotal << endl;
	cout << setw(10) << theatreSys << "\tTHEATRE SYSTEM		" << setw(10) << theatreSysPrice << " 		" << setw(10) << theatreSysTotal << endl;
	cout << setw(10) << remoteCon << "\tREMOTE CONTROLLER	" << setw(10) << remoteConPrice << " 		" << setw(10) << remoteConTotal << endl;
	cout << setw(10) << dvr << "\tDVR			" << setw(10) << dvrPrice << " 		" << setw(10) << dvrTotal << endl;
	cout << setw(10) << bluRay << "\tBlu-Ray Disc Player	" << setw(10) << bluRayPrice << " 		" << setw(10) << bluRayTotal << endl;
	cout << setw(10) << projector << "\tPROJECTOR		" << setw(10) << projectorPrice << " 		" << setw(10) << projectorTotal << endl << endl;
	
	// outputting overall totals
	cout << "				" << setw(10) << "SUBTOTAL" << setw(10) << subtotal << endl;
	cout << "				" << setw(10) << "TAX" << setw(10) << taxTotal << endl;
	cout << "				" << setw(10) << "TOTAL" << setw(10) << total << endl << endl;
	
	cout << "Programmed by: Keilani Li\n" << "7/11/22\n" << "Lab #3\n";
	
	return 0;
}
/*
How many TVs were sold? 100
How many Theatre system units were sold? 5
How many Remote Controller units were sold? 25
How many DVRs were sold? 0
How many Blu-Ray Disc Players were sold? 100
How many Projectors were sold? 80

      QTY       Description               Unit Price            Total Price
       100      TV                          379.00                37900.00
         5      THEATRE SYSTEM              429.99                 2149.95
        25      REMOTE CONTROLLER            35.20                  880.00
         0      DVR                         149.98                    0.00
       100      Blu-Ray Disc Player         248.00                24800.00
        80      PROJECTOR                  1300.00               104000.00

                                  SUBTOTAL 169729.95
                                       TAX  15496.34
                                     TOTAL 185226.29

Programmed by: Keilani Li
7/11/22
Lab #3

--------------------------------
Process exited after 8.349 seconds with return value 0
Press any key to continue . . .

*/
