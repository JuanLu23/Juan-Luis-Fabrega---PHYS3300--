
// Included libraries for the program
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

// Namespace declaration for the programs 
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

// The begining of the main code
int main() {
	
	// Declaration of the vectors, that will be filled with the items mined and collected
	vector<string> MineralInventory;
	vector<string> HerbsInventory;

	// Declaration that contain the items that will be optained during the mining and colecting process
	vector<string> HerbsTypes{ "Verila Pluma", "Secta Dorelis", "Krystalia Fulminis" };
	vector<string> MineralTypes{ "Blue Krystal" , "Green Krystal" };

	// Variables that control the size of the inventories 
	int UnAvailableMineralSpaces = 0;
	int UnAvailableHerbSpaces = 0;
	const int MineralInventorySize = 2;
	const int HerbInventorySize = 4;

	// Other variables used on the program
	string PlayerInput;
	int	RandumNum;

	// While loop that will repeat the program untill the player inputs the proper 
	do {
		// Display for the user 
		cout << "\n-----------[Welcome Player]------------" << endl;
		cout << "Press I or i to Check inventory" << endl;
		cout << "Press M or m to Mine minerals " << endl;
		cout << "Press H or h to Collect herbs " << endl;
		cout << "Press exit or 0 to exit the program" << endl;
		cin >> PlayerInput;

		/* If statemnt that will move the player the acces to see its inventory.
			The inventory has two separate functions:
			 1- Say when the inventory is empty
			 2- Display what Items does the player has optained
		*/
		if (PlayerInput == "I" || PlayerInput == "i")
		{
			cout << "\n--------------[Inventory]--------------" << endl;
			if (UnAvailableMineralSpaces == 0 && UnAvailableHerbSpaces == 0) {
			cout << "---------[Inventory is Empty]----------\n" << endl;
			}
			else {
				// for loops created to print the items that are contained into the inventory for each inventory 
				cout << "\n---------[Minerals Inventory]----------" << endl;
				for (int i = 0; i < MineralInventory.size(); i++) {
					cout << i+1 << "- " << MineralInventory[i] << endl;
				}
				cout << "\n-----------[Herbs Inventory]-----------" << endl;
				for (int i = 0; i < HerbsInventory.size(); i++) {
					cout << i+1 << "- " << HerbsInventory[i] << endl;
				}
			}
		}
		/* If statement that will let the player mine if the correct input is given
			Mining has two aspects:
			 1- If the players inventory is empty this will filled one of its spaces with a mineral
			 2- If not the program will let the player know that the spaces of its inventory is filled

		*/
		else if (PlayerInput == "M" || PlayerInput == "m")
		{
			cout << "Mining . ";
			sleep_for(milliseconds(500));
			cout << ". ";
			sleep_for(milliseconds(500));
			cout << ".\n\n";
			RandumNum = rand() % 2;
			// Here the program checks if the mining inventory has passed its capacity
			if (UnAvailableMineralSpaces <= MineralInventorySize)
			{
				// The comand "push_back" is used to add the item form the mineral list onto the mineral inventory
				MineralInventory.push_back(MineralTypes[RandumNum]);
				UnAvailableMineralSpaces++;

				// Here the program shows what item was selected and also shows how many spaces are left 
				cout << " You obtained " << MineralTypes[RandumNum] << "!" << endl;
				cout << " There is " << UnAvailableMineralSpaces << " of "<< MineralInventorySize+1 << " spaces filled" << endl;
			}
			else {
		cout << "------[Minerals Inventory Full]--------" << endl;
			}
		}
		/* Simillar to the mining aspect of the program the gathering system has also 
			two features that are similar to the mining system:
			 1- I will gather items if the players inventory isn't full
			 2- it will let the player know when it's inventory has reach it capacity 
		*/
		else if (PlayerInput == "H" || PlayerInput == "h")
		{
			cout << "Collecting . ";
			sleep_for(milliseconds(500));
			cout << ". ";
			sleep_for(milliseconds(500));
			cout << ".\n\n";
			RandumNum = rand() % 3;
			// Here the program checks if the herb inventory has passed its capacity
			if (UnAvailableHerbSpaces <= HerbInventorySize)
			{
				// The comand "push_back" is used to add the item form the herb list onto the herb inventory
				HerbsInventory.push_back(HerbsTypes[RandumNum]);
				UnAvailableHerbSpaces++;

				// Here the program shows what item was selected and also shows how many spaces are left 
				cout << " You obtained " << HerbsTypes[RandumNum] << "!" << endl; 
				cout << " There is " << UnAvailableHerbSpaces << " of " << HerbInventorySize + 1 << " spaces filled" << endl;
			}
			else {
				cout << "--------[Herbs Inventory Full]---------" << endl;
			}
		}
		// If the player, does not imput any of the correct props shown before the program props the player for the correct input.
		else {
			cout << " Your input does not correlate with what was listed" << endl;
		}
		
	} while (PlayerInput != "exit" && PlayerInput != "0");
}