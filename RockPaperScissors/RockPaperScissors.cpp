#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>


using namespace std;

int wins; //Amount of player wins
int loses; //Amount of player losses
int ties; //Amount of player ties
void win() {  //On win, print message and increment win counter
	cout << "You won" << endl;
	wins++;
}
void loss() { //On loss, print message and increment loss counter
	cout << "You lost" << endl;
	loses++;
}
void game() {
	int playerChoice = -1; 
	int computerChoice = (rand() % 3) + 1; //Random number (1-3 inclusive) for computers choice
	while (playerChoice == -1) { //While player choice has not been validly made
		cout << "Enter 1 for Rock, 2 for Paper, or 3 for Scissors" << endl;
		cin >> playerChoice; //Get player input, store in int
		if (cin.fail() || playerChoice > 3 || playerChoice < 0) { //If isn't number, or between 1-3 inclusive
			cout << "Invalid character entered. Try again" << endl; //Print error
			playerChoice = -1; //Reset playerChoice, will loop thru again
			cin.clear();
			cin.ignore(256, '\n');
		}
		else { //If choice was valid
			cout << "You choose ";
			switch (playerChoice) { //if player chose 1, it's rock etc
			case 1:
				cout << "rock." << endl;
				break;
			case 2:
				cout << "paper." << endl;
				break;
			case 3:
				cout << "scissors." << endl;
				break;
			}
			cout << "The computer chooses ";
			switch (computerChoice) { //Print the computers random choice
				case 1:
					cout << "rock." << endl;
					break;
				case 2:
					cout << "paper." << endl;
					break;
				case 3:
					cout << "scissors." << endl;
					break;
			}
			if (playerChoice == computerChoice) { //If player and computer choose same thing, it's a tie, increment tie counter
				cout << "You tied" << endl;
				ties++;
			}
			else { //If player and computer had different 
				if (playerChoice == 1) { //If player chose rock
					if (computerChoice == 2) { //Computer chose paper
						loss(); //Paper beats rock
					}
					else { //Computer chose scissors
						win(); //Rock beats scissors
					}
				}
				else if (playerChoice == 2) { //If player chose paper
					if (computerChoice == 1) {//Computer chose rock
						win(); //Paper beats rock
					}
					else {//Computer chose scissors
						loss(); //Scissors beats Paper
					}
				}
				else { //Player chose scissors
					if (computerChoice == 1) { //Computer chose rock
						loss(); //Rock beats scissors
					}
					else {//Computer chose paper
						win();//Scissors beats paper
					}
				}
			}
			cout << "You have " << wins << " wins, " << loses << " loses, and " << ties << " ties." << endl;
			string restart = "";
			while (restart == "") {
				cout << "Play again? (y/n)" << endl;
				cin >> restart;
				transform(restart.begin(), restart.end(), restart.begin(), ::tolower); //Get user response, changes to lower case
				if (restart == "y") {
					if ((wins + loses + ties) % 3 == 0) {
						system("CLS");//Clear screen once every 3 games
					}
					game();
				}
				else if (restart == "n") {
					exit(-1);
				}
				else {
					cout << "Answer yes or no" << endl;
					restart = "";
				}
			}
		}
	}


}
int main() {
	srand(time(NULL));
	char x;
	cout << "Welcome to Rock, Paper, Scissors. Press enter to continue." << endl;
	cin.ignore();
	game();
}



