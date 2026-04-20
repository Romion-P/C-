#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//delcare function for clocks' borders
void printClockBorder() {
	for (int i = 0; i < 16; ++i) { // for loop for space padding
		cout << " ";
	}
	for (int i = 0; i < 27; ++i) { // for loop for *'s
		cout << "*";
	}
	for (int i = 0; i < 5; ++i) { // for looop for space padding
		cout << " ";
	}
	for (int i = 0; i < 27; ++i) { // for loop for *'s
		cout << "*";
	}
	cout << endl;
}
//function that outputs both clocks and converst 24 hour clock to 12 hour am/pm clock
void printClocks(int hours, int minutes, int seconds) {
	int hourCon; // hour conversion
	int minCon; // min conversion
	int secCon; // seconds conversion
	string amPm = "AM"; // am or pm

	// convert 24 hour clock to 12 hour am/pm clock
	if (hours == 0) {
		hourCon = 12;
	}
	else if (hours == 12) {
		hourCon = hours;
		amPm = "PM";
	}
	else if (hours > 12) {
		hourCon = hours - 12;
		amPm = "PM";
	}
	else {
		hourCon = hours;
	}
	//Clock titles
	cout << "\t\t*\t" << "12 hour clock";
	cout << "\t  *";
	cout << "\t*" << "\t24 hour clock";
	cout << "\t  *" << endl;

	//12 hour clock
	cout << "\t\t* \t ";
	cout << setw(2) << setfill('0') << hourCon << ":"; // formatted 12 hour clock

	cout << setw(2) << minutes << ":";
	cout << setw(2) << seconds;
	cout << " " << amPm;
	cout << "\t  *";

	//24 hour clock
	cout << "\t*" << "\t   ";
	cout << setw(2) << setfill('0') << hours << ":"; // formatted 24 hour clock

	cout << setw(2) << minutes << ":";
	cout << setw(2) << seconds;

	cout << "\t  *" << endl;
	



}
void setInitialTime(int& setHour, int& setMinute, int& setSecond) {
	string inputString;    //holds inital user input
	string tempString;     // used for user time input validation
	bool validTime = false;  // valid time used for while statement
	int firstColonPosition;  //used to find the 1st colon in inputString
	int secondColonPosition; // used to find the 2nd colon in inputString

	while (!validTime) {
		cout << "Enter time as HH:MM:SS in 24 hour format: "; //ask for user input for time
		getline(cin, inputString); // assigns user input

		firstColonPosition = inputString.find(':'); // finds first colon
		secondColonPosition = inputString.find(':', firstColonPosition + 1); //finds second colon

		// attempt to assign anc convert clock section if used integers, otherwise ignore
		try {
			setHour = stoi(inputString.substr(0, firstColonPosition)); // takes fist section and converts to an int
			setMinute = stoi(inputString.substr(firstColonPosition + 1, secondColonPosition)); // same as setHour
			setSecond = stoi(inputString.substr(secondColonPosition + 1)); // same as setHour
		}
		catch (const std::exception&) {
			validTime = false;
		}
		if (inputString.size() != 8) { // checks user entered proper character length
			cout << "Time is invalid" << endl;
			validTime = false;
		}
		else if (setHour < 0 || setHour > 23) { // check if hour is between 0 and 23
			cout << "Time is invalid" << endl;
			validTime = false;
		}
		else if (setMinute < 0 || setMinute > 59) { // check if minute is between 0 and 59
			cout << "Time is invalid" << endl;
			validTime = false;
		}
		else if (setSecond < 0 || setSecond > 59) { // check if second is between 0 and 59
			cout << "Time is invalid" << endl;
			validTime = false;
		}
		else {
			validTime = true;
		}
	}

}
// main menu function
void printMainMenu() {
	cout << endl;
	cout << "*********************************" << endl;
	cout << "* 1-Add One Hour\t\t*" << endl;
	cout << "* 2-Add One Minute\t\t*" << endl;
	cout << "* 3-Add One Second\t\t*" << endl;
	cout << "* 4-Exit\t\t\t*" << endl;
	cout << "*********************************" << endl;
	cout << endl;
}
// function for user input and validates user input
void usersInput(int& userChoice, int& setHour, int& setMinute, int& setSecond) {
	cout << "Select option (1-4): "; // ask user for option number

	// verify user input is integer
	if (!(cin >> userChoice)) {
		cin.ignore(1000,'\n'); // clears the buffer


	}
	//Utilize switch statements based on users selection
	switch (userChoice) {
	case 1:
		cout << "1 hour added" << endl;
		if (setHour < 23) { // increments hour unitl it reaches 24
			++setHour;
		}
		else {
			setHour = 00; // reset to 00 once it reaches 24
		}
		break;
	case 2:
		cout << "1 minute added" << endl;
		if (setMinute < 59) { // increments minute unitl it reaches 59
			++setMinute;
		}
		else {
			setMinute = 00; // reset to 00 once it reaches 59
		}
		break;
	case 3:
		if (setSecond < 59) { // increaments second unitl it reaches 59
			++setSecond;
		}
		else {
			setSecond = 00; //reset to 00 once it reaches 59
		}
		break;
	case 4:
		cout << " Program exited, Goodbye!" << endl;
		break;
	default:
		cout << "Invalid choice. Enter a number between 1-4" << endl;
		cin.clear();
		break;

	}
}
int main() {
	// declare properties
	int userChoice = 0; // initial user choice
	int setHour = 0; // following attributes initialize clocks to midnight
	int setMinute = 0;
	int setSecond = 0;

	// user input for initial time
	setInitialTime(setHour, setMinute, setSecond);

	//programs while loop
	while (userChoice != 4) {

		//call clock functions
		printClockBorder(); // clocks borders

		printClocks(setHour, setMinute, setSecond); // prints both clocks

		printMainMenu(); // print main menu

		usersInput(userChoice, setHour, setMinute, setSecond); // takes integer and modifies clock bases on command

	}
	return 0;
}

