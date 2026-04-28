#include <iostream>
#include <stdio.h>
#include "savings.h"

using namespace std;
//This function is to display the layout of the banking app for the user
void displayLayout() {
	cout << "************************************" << endl;
	cout << "*************Data Input*************" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;
	cout << "Press any key to continue . . ." << endl;
}
int main()
{
	bool exit = false;
	while (exit != true) {
		//Printing the automatic ouput for the banking layout for the app
		displayLayout();	
		cout << endl;
		double investment;
		double monthlyDeposit;
		double interestRate;
		int years;
		cout << "************************************" << endl;
		cout << "*************Data Input*************" << endl;
		
		
		// user input Entry with Validation for each input field making sure they are valid numbers and not negative
		cout << "Initial Investment Amount: $";
		while (!(cin >> investment) || investment < 0 ) {
			cout << "Invalid input. Please enter a number: $";
			cin.clear(); // Reset error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
		}
		cout << "Monthly Deposit: $";
		while (!(cin >> monthlyDeposit) || monthlyDeposit < 0) {
			cout << "Invalid input. Please enter a number: $";
			cin.clear(); // Reset error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
		}
		
		
		cout << "Annual Interest: %";
		while (!(cin >> interestRate) || interestRate < 0) {
			cout << "Invalid input. Please enter a percentage: %";
			cin.clear(); // Reset error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
		}
		
		cout << "Number of years: ";
		while (!(cin >> years) || years < 0) {
			cout << "Invalid input. Please enter a number: ";
			cin.clear(); // Reset error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
		}
		
		cout << "Press any key to continue . . ." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get(); //Verifying the user pressed any key
		cout << endl;

		savings potentialSavings = savings(investment, monthlyDeposit, interestRate, years); //Creating local way to call our functions in savings.cpp

		//This function call is to print out what the savings would look like without a monthly deposit
		potentialSavings.statementWithoutDeposits();
		cout << endl;

		//This if statement checks if the deposit is over 0 and calls the appropriate function
		if (monthlyDeposit > 0)
		{
			potentialSavings.statementWithDeposits();
			cout << endl;
		}
		
		char userChoice;
		// Loop until a valid choice ('y', 'Y', 'n', or 'N') is entered
		while (true) {
			cout << "Would you like to enter different amounts? (y/n): ";
			cin >> userChoice;

			// Convert to lowercase to simplify the check
			userChoice = tolower(userChoice);

			if (userChoice == 'y' || userChoice == 'n') {
				break; // Valid input, exit this validation loop
			}
			else {
				cout << "Invalid input. Please enter 'y' or 'n'." << endl;
			}
		}

		// Now handle the validated choice
		if (userChoice == 'n') {
			exit = true; // Or however you're signaling the main loop to stop
			cout << "Thank you for using Airgead Banking, Goodbye!" << endl;
			break;
		}


	}
	return 0;
}