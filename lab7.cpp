/*  Keilani Li
	keilanili@gmail.com
	Lab #7
	8/1/22 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#define MAX 100

using namespace std;

int getData(ifstream& inFile, double winPercentArray[], double fieldGoalsArray[], double avgFreeThrowsArray[], string teamNameArray[]); //pass file to input function
void output(ofstream& outFile, double winPercentArray[], double fieldGoalsArray[], double avgFreeThrowsArray[], string teamNameArray[], int teamCount); //output file

void userPercent(ofstream& outFile, double winPercentArray[], double fieldGoalsArray[], double avgFreeThrowsArray[], string teamNameArray[], int teamCount, double percentInput);
double highestFreeThrows(double avgFreeThrowsArray[], int teamCount);
void teamWinRate(double winPercentArray[], string teamNameArray[], int teamCount);
void fieldGoalsSort(double winPercentArray[], double fieldGoalsArray[], double avgFreeThrowsArray[], string teamNameArray[], int teamCount);

int main() {
	
	//declare variables
	ifstream inFile;
	double winPercentArray[MAX]; //need 3 arrays (3 double and one string)
	double fieldGoalsArray[MAX];
	double avgFreeThrowsArray[MAX];
	string teamNameArray[MAX];	
	
	int teamCount;
	double highestThrows;
	double percentInput;
	
	ofstream outFile; //creates a file containing outputs
	outFile.open("Li_lab7.txt");	
	
	inFile.open("NBA_Lab7.txt"); //opens txt file
	if (inFile.fail() == 1) { //checks if file exists
		cout << "Error opening file" << endl;
		exit(100);
	}	

	teamCount = getData(inFile, winPercentArray, fieldGoalsArray, avgFreeThrowsArray, teamNameArray); //fills arrays
	
	output(outFile, winPercentArray, fieldGoalsArray, avgFreeThrowsArray, teamNameArray, teamCount); //output directed to a file

	userPercent(outFile, winPercentArray, fieldGoalsArray, avgFreeThrowsArray, teamNameArray, teamCount, percentInput); 
	
	highestThrows = highestFreeThrows(avgFreeThrowsArray, teamCount); 
	cout << "The highest number of free throws made is: " << highestThrows << endl;

	teamWinRate(winPercentArray, teamNameArray, teamCount); 
	
	fieldGoalsSort(winPercentArray, fieldGoalsArray, avgFreeThrowsArray, teamNameArray, teamCount); 

	output(outFile, winPercentArray, fieldGoalsArray, avgFreeThrowsArray, teamNameArray, teamCount); //writes sorted array to output file

	inFile.close(); //closes NBA_Lab7.txt file
	outFile.close(); //closes output file
	
	return 0;
}

int getData(ifstream& inFile, double winPercentArray[], double fieldGoalsArray[], double avgFreeThrowsArray[], string teamNameArray[]) { 
	
	/* Pre: inFile - reference to the NBA_Lab7.txt file
			winPercentArray - stores the computed win rate of each team into an array of doubles
			fieldGoalsArray - stores values of the % of field goals made for each team into an array of doubles
			avgFreeThrowsArray - stores of the # of avg free throws made for each team into an array of doubles
			teamNameArray - stores team names into an array of strings
	Post: returns the total number of teams
	Purpose: while loop is used to fill the four arrays
	*/
	
	int wins, losses; //variables that help calculate % of wins
	double fieldGoals, avgFreeThrows;
	string teamName;
	
	double winPercent;
	
	int teamCount = 0;
	while (teamCount < MAX && !inFile.eof()) { //loops till end of file
		
		inFile >> wins >> losses >> fieldGoals >> avgFreeThrows;
		inFile.ignore();
		getline(inFile, teamName);
		
		winPercent = (static_cast<double>(wins) / (wins + losses)) * 100; //calculates win % for each team
		
		//fills array with file input
		winPercentArray[teamCount] = winPercent;
		fieldGoalsArray[teamCount] = fieldGoals;
		avgFreeThrowsArray[teamCount] = avgFreeThrows;
		teamNameArray[teamCount] = teamName;
		
		teamCount++;
	}
	return teamCount;
}

void output(ofstream& outFile, double winPercentArray[], double fieldGoalsArray[], double avgFreeThrowsArray[], string teamNameArray[], int teamCount) {
	
	/* Pre: outFile - reference to output file named Li_lab7.txt which was created in main()
			winPercentArray - stores the computed win rate of each team into an array of doubles
			fieldGoalsArray - stores values of the % of field goals made for each team into an array of doubles
			avgFreeThrowsArray - stores of the # of avg free throws made for each team into an array of doubles
			teamNameArray - stores team names into an array of strings
			teamCount - returned value from getData function which represents the total number of teams
	Post: void doesn't return a value
	Purpose: output directly to file nd not to comp screen
	*/
	
	outFile << "TEAM" << setw(45) << "% 3-pt field goals" << setw(30) << "avg free throws/game" << setw(17) << "% wins" << endl;
	
	for (int i = 0; i < teamCount; i++) { //prints values from all the arrays
		outFile << fixed << setprecision(1);
		outFile << setw(35) << left << teamNameArray[i] << setw(30) << fieldGoalsArray[i] << setw(25) << avgFreeThrowsArray[i] << setw(20) << winPercentArray[i] << endl;
	}
	
	outFile << endl;
	
	//signature
	outFile << "Programmed by: Keilani Li | keilanili@gmail.com" << endl;
	outFile << "Lab #7, 8/2/22" << endl << endl;
	
}

void userPercent(ofstream& outFile, double winPercentArray[], double fieldGoalsArray[], double avgFreeThrowsArray[], string teamNameArray[], int teamCount, double percentInput) {
	
	/* Pre: outFile - reference to output file named Li_lab7.txt which was created in main()
			winPercentArray - stores the computed win rate of each team into an array of doubles
			fieldGoalsArray - stores values of the % of field goals made for each team into an array of doubles
			avgFreeThrowsArray - stores of the # of avg free throws made for each team into an array of doubles
			teamNameArray - stores team names into an array of strings
			teamCount - returned value from getData function which represents the total number of teams
	Post: void doesn't return a value
	Purpose: prompts user for % between 1 and 100, then outputs to file from this function all info for each team where
	% of wins for the team is above this number
	*/ 
	
	cout << "Enter a percentage between 1-100: ";
	cin >> percentInput;
	if (percentInput < 0.0 || percentInput > 100.0) {
		outFile << "Invalid number. Please input a different number.";
		exit(100);
	}
		outFile << "The following teams have a win percentage higher than " << percentInput << ":" << endl;
	
	for (int i = 0; i < teamCount; i++) { //prints all info for each team that has a higher win % than the percentage that was inputted
		if (percentInput < winPercentArray[i]) {
			outFile << setw(35) << left << teamNameArray[i] << setw(30) << fieldGoalsArray[i] << setw(25) << avgFreeThrowsArray[i] << setw(20) << winPercentArray[i] << endl;
		}
		else if (percentInput > winPercentArray[i]) { //nothing will output
			continue;
		}
		else { //executes if there's no group w % of wins above percentInput
			outFile << "No group with percentage of wins above " << percentInput << endl;
		}
	}
	outFile << endl;
	
}

double highestFreeThrows(double avgFreeThrowsArray[], int teamCount) { 
	
	/* Pre: avgFreeThrowsArray - stores of the # of avg free throws made for each team into an array of doubles
			teamCount - returned value from getData function which represents the total number of teams
	Post: returns the highest avg # of free throws
	Purpose: returns subscript of team with the highest # of free throws per game
	*/ 
	
	int highIndex = 0;
	
	for(int i = 0; i < teamCount; i++) { //finds the highest avg # of free throws
		if (avgFreeThrowsArray[highIndex] < avgFreeThrowsArray[i])
		avgFreeThrowsArray[highIndex] = avgFreeThrowsArray[i];
	}
	
	return avgFreeThrowsArray[highIndex]; //returns highest avg # of free throws
}

void teamWinRate(double winPercentArray[], string teamNameArray[], int teamCount) { 

	/* Pre: winPercentArray - stores the computed win rate of each team into an array of doubles
			teamNameArray - stores team names into an array of strings
	Post: void doesn't return a value
	Purpose: prompts user for name of a team, then outputs to the screen from this function the % of wins only for this team
	*/
	
	string teamNameInput;
	
	cout << "Enter name of team (be sure to use proper capitalization): ";
	cin.ignore();
	getline(cin, teamNameInput); //asks user to input team name
	
	for (int i = 0; i < teamCount; i++) { //finds % of wins only for the team inputted by user
		if (teamNameInput == teamNameArray[i]) {
			cout << teamNameArray[i] << "\t\t" << fixed << setprecision(1) << winPercentArray[i] << endl;
		}
		else if (teamNameInput != teamNameArray[i]) { //nothing will output
			continue;
		}
		else { //if no team is found, this statement executes
			cout << "No statistics for " << teamNameInput << " team." << endl;
		}
	}
}

void fieldGoalsSort(double winPercentArray[], double fieldGoalsArray[], double avgFreeThrowsArray[], string teamNameArray[], int teamCount) { 
	
	/* Pre: fieldGoalsArray - stores values of the % of field goals made for each team into an array of doubles
			teamCount - returned value from getData function which represents the total number of teams
	Post: void doesn't return a value
	Purpose: sorts all data by team’s % of 3-point free throws in descending order
	*/
	
	int i, j;
	double temp;
	string tempString;
	
	//sorting in descending order
    for (i = 0; i < teamCount; i++) {
    	for (j = i + 1; j < teamCount; j++) {
			if (fieldGoalsArray[i] < fieldGoalsArray[j]) {
				temp = fieldGoalsArray[i];
				fieldGoalsArray[i] = fieldGoalsArray[j];
				fieldGoalsArray[j] = temp; //switches values
				
				//switches values for the other arrays :)
				temp = winPercentArray[i];
    			winPercentArray[i] = winPercentArray[j];
    			winPercentArray[j] = temp;
				
				temp = avgFreeThrowsArray[i];
    			avgFreeThrowsArray[i] = avgFreeThrowsArray[j];
    			avgFreeThrowsArray[j] = temp;
    			
    			tempString = teamNameArray[i];
    			teamNameArray[i] = teamNameArray[j];
    			teamNameArray[j] = tempString;
			}
		}
	}
}
