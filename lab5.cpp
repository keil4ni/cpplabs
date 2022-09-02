/*  Keilani Li
	keilanili@gmail.com
	Lab #5
	7/24/22 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define insuranceCost 2750.0
#define YEARLY_TAX_RATE 1.25

void input(double& sellingPrice, double& interestRate, double& numLoanYrs);
void calcMonthlyCosts(double sellingPrice, double interestRate, double numLoanYrs, double& monthlyPropertyTaxes, double& monthlyInsurance, double& totalMortgage, double& loanAmt, double& monthlyMortgage, const double& downPayment);
void calcDownLoanMortgage(double sellingPrice, double interestRate, double numLoanYrs, double& loanAmt, double& monthlyMortgage, const double& downPayment);
void output(double sellingPrice, double interestRate, double numLoanYrs, double monthlyPropertyTaxes, double monthlyInsurance, double totalMortgage, double loanAmt, double monthlyMortgage, const double downPayment);
void signature();


int main() {
	
	double sellingPrice, interestRate, numLoanYrs;
	double monthlyPropertyTaxes, monthlyInsurance, totalMortgage;
	double loanAmt, monthlyMortgage;
	
	input(sellingPrice, interestRate, numLoanYrs);
	
	const double downPayment = 0.2 * sellingPrice;
	
	calcMonthlyCosts(sellingPrice, interestRate, numLoanYrs, monthlyPropertyTaxes, monthlyInsurance, totalMortgage, loanAmt, monthlyMortgage, downPayment);
	
	output(sellingPrice, interestRate, numLoanYrs, monthlyPropertyTaxes, monthlyInsurance, totalMortgage, loanAmt, monthlyMortgage, downPayment);
	
	return 0;
}

void input(double& sellingPrice, double& interestRate, double& numLoanYrs) {
	
	/* Pre: sellingPrice = reference to user input of the house selling price
			interestRate = reference to user input of the interest rate
			numLoanYrs = reference to user input of number of yrs for loan
	Post: void doesn't return a value
	Purpose: these 3 inputs are needed to help calculate the monthly costs of the house
	*/ 
	
	// user inputs price, interest rate, & # of yrs for loan
	cout << "Enter selling price of house: ";
	cin >> sellingPrice;
	cout << "Enter the interest rate of the house (exclude the %): "; // output reads interest rate in percentage form
	cin >> interestRate;
	cout << "Enter the number of years for loan: ";
	cin >> numLoanYrs;
	
}

void calcMonthlyCosts(double sellingPrice, double interestRate, double numLoanYrs, double& monthlyPropertyTaxes, double& monthlyInsurance, double& totalMortgage, double& loanAmt, double& monthlyMortgage, const double& downPayment) {
	
	/* Pre: sellingPrice = user input's selling price of house
			interestRate = user input's annual interest rate for house
			numLoanYrs = user input's # of years for loan
			monthlyPropertyTaxes = reference to the amount of property taxes owed per month
			monthlyInsurance = reference to amount of insurance owed per month
			totalMortgage = reference to the total mortgage owed as a whole
			loanAmt = reference to amount of loan owed
			monthlyMortgage = reference to amount of mortgage owed per month
			downPayment = reference to amount of down payment owed
	Post: void doesnt return a value
	Purpose: all monthly house costs & all monthly payments are calculated in this function
	*/

	double numPayments = numLoanYrs * 12;
	
	// subfunction calculates down payment, loan amount, and monthly mortgage payment
	calcDownLoanMortgage(sellingPrice, interestRate, numLoanYrs, loanAmt, monthlyMortgage, downPayment);
	
	// calculating monthly property taxes and monthly insurance
	monthlyPropertyTaxes = ((YEARLY_TAX_RATE / 100) * sellingPrice) / 12;
	monthlyInsurance = insuranceCost / 12;
	
	// total cost to pay back mortgage = monthly mortgage payment * # of payments
	totalMortgage = monthlyMortgage * numPayments;
	
}

void calcDownLoanMortgage(double sellingPrice, double interestRate, double numLoanYrs, double& loanAmt, double& monthlyMortgage, const double& downPaymentCost) {
	
	/* Pre: sellingPrice = user input's selling price of house
			interestRate = user input's annual interest rate for house
			numLoanYrs = user input's # of years for loan
			loanAmt = reference to amount of loan owed
			monthlyMortgage = reference to amount of mortgage owed per month
			downPayment = reference to amount of down payment owed
	Post: void doesnt return a value
	Purpose: down payment amt, loan amt, and monthly mortgage payment are calculated in this function
	*/
	
	const double downPayment = 0.2 * sellingPrice;
	double interestRateCompoundPrd, numCompoundPrd;
	
	loanAmt = sellingPrice - downPayment;
	interestRateCompoundPrd = (interestRate / 100) / 12; // interest rate is converted to decimal form first
	numCompoundPrd = numLoanYrs * 12; // # of months
	monthlyMortgage = ((loanAmt * interestRateCompoundPrd) * pow(1 + interestRateCompoundPrd, numCompoundPrd)) / (pow(1 + interestRateCompoundPrd, numCompoundPrd) - 1);
	
}

void output(double sellingPrice, double interestRate, double numLoanYrs, double monthlyPropertyTaxes, double monthlyInsurance, double totalMortgage, double loanAmt, double monthlyMortgage, const double downPayment) {
	
	/* Pre: sellingPrice = user input's selling price of house
			interestRate = user input's annual interest rate for house
			numLoanYrs = user input's # of years for loan
			monthlyPropertyTaxes = amount of property taxes owed per month
			monthlyInsurance = amount of insurance owed per month
			totalMortgage = total mortgage owed as a whole
			loanAmt = amount of loan owed
			monthlyMortgage = amount of mortgage owed per month
			downPayment = amount of down payment owed
	Post: void doesnt return a value
	Purpose: output format is shown
	*/
	
	// output format
	cout << fixed << setprecision(2) << endl;
	
	cout << "MONTHLY COST OF HOUSE" << endl;

	cout << "SELLING PRICE\t\t" << setw(9) << "$" << sellingPrice << endl;
	cout << "DOWN PAYMENT\t\t\t" << setw(10) << downPayment << endl;
	cout << "AMOUNT OF LOAN\t\t\t" << setw(10) << loanAmt << endl;
	cout << "INTEREST RATE\t\t\t" << setw(10) << interestRate << "%" << endl;
	cout << "TAX RATE\t\t\t" << setw(10) << YEARLY_TAX_RATE << "%" << endl;
	cout << "DURATION OF LOAN (YEARS)\t" << setw(10) << numLoanYrs << endl << endl;
	
	cout << "MONTHLY PAYMENT\t\t\t" << endl;
	
	cout << "MORTGAGE\t\t\t" << setw(10) << monthlyMortgage << endl;
	cout << "PROPERTY TAXES\t\t\t" << setw(10) << monthlyPropertyTaxes << endl;
	cout << "INSURANCE\t\t\t" << setw(10) << monthlyInsurance << endl;
	cout << "\t\t\t\t__________" << endl;
	cout << "PAYMENT TOTAL ON LOAN\t\t" << setw(10) << totalMortgage << endl << endl;
	
	// signature function is called at the very end
	signature();
}

void signature() {
	
	cout << "Programmed by: Keilani Li | keilanili@gmail.com" << endl;
	cout << "Lab #5, 7/24/22";
	
}
