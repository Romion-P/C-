#include <iostream>
#include <fstream>
#include <map>
#include <string>    
#include <vector>
using namespace std;
//class for tracking item frequnecies 
class itemTracker {
private:

	map <string, int> itemFrequency;
public:
	//constructor to read file data and populate map
	itemTracker(const string& filename) {
		ifstream inputFile(filename);
		string item;
		if (inputFile.is_open()) {
			while (getline(inputFile, item)) {
				++itemFrequency[item];
			}
			inputFile.close();
		}
		else {
			cerr << "Error opening file!" << endl;
		}
		backupData("frequency.dat");
	}
	//Function to get the frequency of a specific item
	int GetItemFrequency(const string& item) const {
		auto it = itemFrequency.find(item);
		if (it != itemFrequency.end()) {
			return it->second;
		}
		else {
			return 0; // Item not found
		}
	}
	//Function to display list of item frequencies
	int GetItemList() const {
		for (const auto& pair : itemFrequency) {
			cout << pair.first << " " << pair.second << endl;
		}
		
		return 0;
	}
	//Function to display the histogram of item frequencies
	void DisplayHistogram() const {
		for (const auto& pair : itemFrequency) {
			cout << pair.first << " ";
			for (int i = 0; i < pair.second; ++i) {
				cout << "*";
			}
			cout << endl;
		}
	}

	//Function to backup the frequency data to a file
	void backupData(const string& backupFilename) const {
		ofstream outputFile(backupFilename);
		if (outputFile.is_open()) {
			for (const auto& pair : itemFrequency) {
				outputFile << pair.first << " " << pair.second << endl;
			}
			outputFile.close();
		}
		else {
			cerr << "Error opening backup file!" << backupFilename << endl;
		}
	}
};

//display menu for user interaction
void displayMenu() {
	cout << "Menu:" << endl;
	cout << "1. Search for an item (ex. Peas)" << endl;
	cout << "2. Get Frequency of a Specific Item: "   << endl;
	cout << "3. Display Item Frequency Histogram: "  << endl;
	cout << "4. Exit" << endl;

	cout << endl;
}
int main() {
	// Create an instance of the itemTracker class and read data from the input file
	itemTracker tracker("CS210_Project_Three_Input_File.txt");
	int choice;
	string itemName;
	do {
		displayMenu();
		cout << "Enter your choice: ";
		//Validates if initial input is a number 
		while (!(cin >> choice)) {
			cout << "invalid input. Please enter a number (1-4): " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cin.ignore(); // Clear newline from input buffer

		//validates if choice is a number between 1 and 4
		if (choice < 1 || choice > 4) {
			cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
			continue;
		}
		// Lets user choose from the display menu 
		switch (choice) {
		case 1: // If input is 1 then enter item name and display frequency
			cout << "Enter item name to search: ";
			getline(cin, itemName);

			//Outputs the frequency on the item and validates it's in the list
			if (tracker.GetItemFrequency(itemName) > 0) {
			cout << "Frequency of " << itemName << ": " << tracker.GetItemFrequency(itemName) << endl;
			}
			else {
				cout <<"Error: " << itemName << " not found in the list." << endl;
			}
			
			cout << endl;
			break;
		case 2: // If input is 2 then Item list is outputted
			cout << endl;
			cout << "Item List: " << endl;
			tracker.GetItemList();
			cout << endl;
			break;
		case 3: // If input is 3 then histogram is outputted
			cout << endl;
			cout << "Histogram: " << endl;
			tracker.DisplayHistogram();
			cout << endl;
			break;
		
		case 4: // If input is 4 then program is exited
			cout << "Exiting program." << endl;
			break;
		default:
				cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 4);
	return 0;
}
