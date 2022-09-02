/* Keilani Li
	keilanili@gmail.com
	Lab #4
	7/18/22 */
	
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>

using namespace std;

double calcFare(double baseFare, double minutes, double distance, double perMinute, double perMile, double minimumFare);
void output(double total, string fullName);

int main() {
	//declaring variables for basic info (duration of ride, distance travelled)
	string fullName;
	double minutes;
	double distance;
	
	//fee schedule
	char vehicleType;
	double baseFare, perMinute, perMile, minimumFare;
	
	//variables for surge calculations
	char surge;
	double surgeMult;
	double total;
	
	cout << "Enter name: ";
	getline(cin, fullName);
	
	cout << "Enter time in minutes: ";
	cin >> minutes;
	
	cout << "Enter distance: ";
	cin >> distance;
	
	cout << "Enter 'X' for UberX, 'S' for SUV, or 'L' for Luxury: ";
	cin >> vehicleType;
	vehicleType = toupper(vehicleType); //turns lowercase chars into uppercase
	if (vehicleType == 'X') { //fee schedule changes based on the vehicle type
		baseFare = 2.0;
		perMinute = 0.22;
		perMile = 1.15;
		minimumFare = 6.55;
}
	else if (vehicleType == 'S') {
		baseFare = 15.0;
		perMinute = 0.9;
		perMile = 3.75;
		minimumFare = 25.0;
}
	else if (vehicleType == 'L') {
		baseFare = 5.0;
		perMinute = 0.5;
		perMile = 2.75;
		minimumFare = 10.55;
}
	else { //exits the program since user did not input X, S, or L
		cout << "Invalid entry. Please run the program again." << endl;
		exit(1);
}


	cout << "Enter 'Y' if surge or 'N' if not: ";
	cin >> surge;
	surge = toupper(surge);
	if (surge == 'Y') { 
		cout << "Enter surge multiplier: ";
		cin >> surgeMult;
		baseFare *= surgeMult;
	}
	
	cout << endl;
	
	total = calcFare(baseFare, minutes, distance, perMinute, perMile, minimumFare);
	output(total, fullName);
	
	cout << "Programmed by: Keilani Li | Lab #4" << endl;
	cout << "Email: keilanili@gmail.com" << endl;
	
	return 0;
}

double calcFare(double baseFare, double minutes, double distance, double perMinute, double perMile, double minimumFare) {

	/* Pre: baseFare = base fare amount owed based on car type
		minutes = # of minutes travelled
		distance = distance of ride in miles
		perMinute = amount owed based on # of minutes
		perMile = amount owed based on # of miles travelled
		minimumFare = minimum fare amount owed to uber driver
	Post: total fare
	Purpose: calculates total fare and outputs that value
	*/

	double total;
	total = baseFare + (perMinute * minutes) + (perMile * distance);
	
	if (total < minimumFare) {
		total = minimumFare;
	}
	
	return total;
}

void output(double total, string fullName) {
	
	/* Pre: total = uber fare total
		fullName = full name of rider
	Post: nothing
	Purpose: outputs rider's name and total owed to uber driver
	*/
	
	cout << "Rider's name: " << fullName << endl;
	cout << fixed << setprecision(2);
	cout << "Total: $" << total << endl << endl;
}

/* 
Enter name: Mary Pape
Enter time in minutes: 70
Enter distance: 55
Enter 'X' for UberX, 'S' for SUV, or 'L' for Luxury: X
Enter 'Y' if surge or 'N' if not: Y
Enter surge multiplier: 1.9

Rider's name: Mary Pape
Total: $82.45

Programmed by: Keilani Li | Lab #4
Email: keilanili@gmail.com

--------------------------------
Process exited after 13.79 seconds with return value 0
Press any key to continue . . .
*/

/*
Enter name: Taylor Swift
Enter time in minutes: 15
Enter distance: 16.8
Enter 'X' for UberX, 'S' for SUV, or 'L' for Luxury: L
Enter 'Y' if surge or 'N' if not: N

Rider's name: Taylor Swift
Total: $58.70

Programmed by: Keilani Li | Lab #4
Email: keilanili@gmail.com

--------------------------------
Process exited after 14.91 seconds with return value 0
Press any key to continue . . .
*/

/*
Enter name: Jason Rider
Enter time in minutes: 45
Enter distance: 13.8
Enter 'X' for UberX, 'S' for SUV, or 'L' for Luxury: C
Invalid entry. Please run the program again.

--------------------------------
Process exited after 11.61 seconds with return value 1
Press any key to continue . . .
*/
