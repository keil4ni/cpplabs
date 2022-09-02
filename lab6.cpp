/*  Keilani Li
	keilanili@gmail.com
	Lab #6
	7/28/22 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//declare function that computes percentage of wins
double percentageWins(double wins, double losses);

int main() {
	
	int wins, losses; //needed to compute win %
	string teamName;
	double percentWins;
	
	ofstream outFile; //creates a file containing outputs
	outFile.open("Li_lab6.txt");
	
	ifstream inFile; //declares reference to file
	inFile.open("NBA_Lab6.txt");
	if (inFile.fail() == 1) { //important, checks if file exists
		cout << "No such file" << endl;
		exit(100);
	}
	
	outFile << setw(15) << "TEAM" << setw(40) << "% WINS" << endl << endl;
	
	int teamCount = 0;
	while (!inFile.eof()) { //loops till end of file
		inFile >> wins >> losses;
		getline(inFile, teamName); //reads full string of team name
		
		percentWins = percentageWins(wins, losses);
		
		teamCount++; //increments # of total teams by 1 for each run
	
	outFile << fixed << setprecision(1);
	outFile << setw(25) << left << teamName << setw(25) << right << percentWins << endl;
	//team names are aligned to the left and win percentages are aligned to the right
	
	}
	
	inFile.close(); //closes NBA_Lab6.txt file
	
	outFile << endl;
	outFile << "Total Number of Teams: " << teamCount << endl << endl;
	
	//signature
	outFile << "Programmed by: Keilani Li | keilanili@gmail.com" << endl;
	outFile << "7/28/22, Lab #6" << endl;
	outFile.close(); //closes output file
	
	return 0;
}

double percentageWins(double wins, double losses) {
	
	/*  Pre: wins = # of wins a team got, which was inputted from the NBA_Lab6.txt file
			 losses = # of losses a team got, also inputted from the same .txt file
		Post: win percentage of a team
		Purpose: computes the win rate of a team */
	
	double percentage;
	
	//formula to calculate the win % of a team
	percentage = (wins / (wins + losses)) * 100; //# of wins and # of losses are substituted in equation
	
	return percentage;
}
