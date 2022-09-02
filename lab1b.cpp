/* Keilani Li
   Lab #1B
   6/30/22 */
   
#include <iostream>

using namespace std;

int main()
{
	// create variables that store the # of each coin type someone has
	int quarters;
	int dimes;
	int nickels;
	int pennies;
	
	// user inputs # of quarters, dimes, nickels & pennies
	cout << "How many quarters do you have? ";
	cin >> quarters;
	cout << endl;
	
	cout << "How many dimes do you have? ";
	cin >> dimes;
	cout << endl;
	
	cout << "How many nickels do you have? ";
	cin >> nickels;
	cout << endl;
	
	cout << "How many pennies do you have? ";
	cin >> pennies;
	cout << endl;
	
	// calculates total
	cout << "You have: $";
	cout << quarters * 0.25 + dimes * 0.10 + nickels * 0.05 + pennies * 0.01; // each variable is multiplied by the appropriate money value
	// variables are then added together to get the total
	cout << " in your wallet.\n";
	cout << endl;
	
	/*
	for some reason, \n or endl alone doesn't create the whitespace i want even though using endl by itself worked in earlier lines,
	so i used both of them in lines 38-39 and it worked after compiling and running
	*/
	
	cout << "Programmed by: Keilani Li" << endl;
	cout << "Lab #1B" << endl;
	
	return 0;
}
/*
How many quarters do you have? 3

How many dimes do you have? 0

How many nickels do you have? 5

How many pennies do you have? 23

You have: $1.23 in your wallet.

Programmed by: Keilani Li
Lab #1B

--------------------------------
Process exited after 5.458 seconds with return value 0
Press any key to continue . . .
*/
