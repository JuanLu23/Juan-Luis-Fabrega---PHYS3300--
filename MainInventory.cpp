// Libraries that will be used for the program 
#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include <cstdlib>

// Namesoaced declared 
using namespace std;

//Functions that the program needs to work
//	Function that generates the inventory 
void InventoryGenerator(vector<string> & Inventory, vector<string> &Item, bool CristalRemoved);

//	Function that opens the invontory generated in other functions
void OpenInventory(vector<string>& Inventory, bool &CristalGone);

//	Function called in the Inventory Generator that will search fot a crystal in the inventory
bool CristalinInventory(vector<string> Inventory);

//	Function with the crafting UI and system 
void CraftSystem(vector<string> &Inventory);

//  Function that will check if the player has the correct crystal in his inventory 
bool OpaqueCrystal(string rawCrystal, vector<string> &inventory);

//  Function that repalces the the Crystal for the OpaqueCrystal in the inventory 
void ReplaceCrystal(string rawCrystal, string opaqueCrystal, vector<string>& inventory);

//  Function that will make a list with 5 items that the player can take 
void ItemColection(vector<string>& Inventory, vector<string>& ItemList, bool CristalRemoved);

//  Function that has a separate inventory when the player deletes a crystal from its inventory 
void CrystalLessInventory(vector<string>& Inventory, vector<string>& Item);

//  Fucntion that has a separate Item list when the player removes crystal from its inventory 
void CrystalLessItemCollection(vector<string>& Inventory, vector<string>& Item, vector<string> &Store);

// Inventory Function 
void InventoryGenerator(vector<string>& Inventory, vector<string> &Item, bool CristalRemoved) {
	// Variables that will be used in the function
	// while variable that controls the counter 
	int counter = 0;

	// Variables that will be used to se the random item in the inventory 
	int max = 4, min = 0; 

	// Variable that stores the random number
	int RandomItem;

	// Bool variables used in the function 
	bool containsCrystal = false;
	bool ContainsCrystalTrue, OtherItemsInventory;

	// If statement that control if the player has deleted a crystal from the inventory 
	if (!CristalRemoved) {

		// While loop that creates the inventory for 7 spaces 
		while (counter < 7) {

			// If statement that checks for if the inventory has more size than 20
			if (Inventory.size() < 20) {

				// Process that generates a random Item
				// Generating a random number for the inventory 
				RandomItem = rand() % (max - min + 1) - min;

				// Calling the function that will check if a cristal is in the inventory 
				containsCrystal = CristalinInventory(Inventory);

				// Variable that saves if there is a crystal in the inventory 
				ContainsCrystalTrue = ((Item[RandomItem] == "Crystallized Azure Dragon's Tears") || (Item[RandomItem] == "Crystallized Exiled Heretic's Bone") || (Item[RandomItem] == "Crystallized Great Feline's Ash")) && containsCrystal;

				// Variable that controls how many fisherman plates can be in the inventory
				OtherItemsInventory = (count(Inventory.begin(), Inventory.end(), "Fishermen's Plate") >= 3) && (Item[RandomItem] == "Fishermen's Plate");

				// If statement that stores the item in the inventory 
				if (!ContainsCrystalTrue && !OtherItemsInventory) {
					Inventory.push_back(Item[RandomItem]);
					counter++;
				}
			}
			//If the inventory is full the else will finish the counter that way the player can get out of the Inventory 
			else {
				counter++;
			}
		}
	}
	// Else that calls a fucntion if the player has deleted a crystal from its inventory 
	else {
		CrystalLessInventory(Inventory, Item);
	}


}

// Inventory fuction that behaves similar to the Inventory Generator, but is only called when the player deletes a crystal from its inventory 
void CrystalLessInventory(vector<string>& Inventory, vector<string>& Item) {
	
	int counter = 0;

	int max = 4, min = 0;

	int RandomItem;

	// The while loob will only add Iron Plate & Fishermen's Plate
	while (counter < 7) {
		if (Inventory.size() < 20) {
			RandomItem = rand() % (max - min + 1) - min;

			if (Item[RandomItem] == "Iron Plate" || (Item[RandomItem] == "Fishermen's Plate"))
			{
				Inventory.push_back(Item[RandomItem]);
				counter++;
			}
		}
	}

}

// Function that checks if ther is a crystal in the inventory
bool CristalinInventory(vector<string> Inventory) {

	int count = 0;

	bool CristalPresent = false; 

	bool ContainsCrystalTrue;
	// The while goes throuhg the inventory that has been created and check if there is a crystal in any of the spaces 
	while ((count < Inventory.size()) && (!CristalPresent)) 
	{
		ContainsCrystalTrue = (Inventory[count] == "Crystallized Azure Dragon's Tears" || Inventory[count] == "Crystallized Exiled Heretic's Bone" || Inventory[count] == "Crystallized Great Feline's Ash");
		// If statement that will be open if a crystal is found in the inventory
		if (ContainsCrystalTrue) 
		{
			// The bool that is sent to the inventory is changed to true this whay no crystaled will be add to the inventory 
			CristalPresent = true; 
		}
		count++;
	}

	return CristalPresent;
}

// Function that opens the inventory
void OpenInventory(vector<string>& Inventory, bool& CristalGone) {

	bool InventoryLoop = true; 

	int PlayerInput;

	string EraseItem = "NA";

	// while that shows the UI of the inventory 
	while (InventoryLoop) {
		system("CLS");
		cout << "+-------------------------------------------------------------+" << endl;
		cout << "                        + + MAIN MENU + +" << "\n" << endl;
		for (int count = 0; count < Inventory.size(); count++) {
			cout << count + 1 << "- " << Inventory[count] << endl;
		}
		cout << Inventory.size() + 1 << "- EXIT " << endl;
		cout << "+-------------------------------------------------------------+" << endl;
		// The player can delete Items from the inventory, and here is where that input is received 
		cout << " - Enter Input: " << endl; cin >> PlayerInput;

		// If that lets the player exit from the Inventory loop 
		if (PlayerInput == Inventory.size() + 1) {
			InventoryLoop = false;
		}

		// If the player wants to delete a crystal from its inventory, there is a diferent propt for that Item
		else if (PlayerInput <= Inventory.size() && Inventory[PlayerInput - 1] == "Crystallized Azure Dragon's Tears" || Inventory[PlayerInput - 1] == "Crystallized Exiled Heretic's Bone" || Inventory[PlayerInput - 1] == "Crystallized Great Feline's Ash" ||  Inventory[PlayerInput - 1] == "Opaque Azure Dragon's Sapphire" || Inventory[PlayerInput - 1] == "Opaque Humanity's Emerald" || Inventory[PlayerInput - 1] == "Opaque Feline's Ruby")
		{
			// Heres the text, we let the player be completly sure that he is deleting the Item, if he continues and deletes the item 
			//  a bool variable is set so that the crystal or any crystal cannot be optained any more
			cout << "   You choose..." << Inventory[PlayerInput - 1] << "\n" << endl;
			cout << "[CAUTION] If this item is deleted there is no other way to obtain it" << endl;
			cout << "   Would you like to delete this item y/n?" << endl; cin >> EraseItem;
			if (EraseItem == "y" || EraseItem == "Y")
			{
				// Bool variable and the deletion of the item 
				CristalGone = true;
				Inventory.erase(Inventory.begin() + PlayerInput - 1);
				cout << "                  + + ITEM DELETED + +" << endl;
			}
		}
		// Similar to the crystal the normal Items are deleted but do not prompt for the deletion of set Item they are just deleted 
		else if (PlayerInput <= Inventory.size()) 
		{
			cout << "   You choose..." << Inventory[PlayerInput - 1] << "\n" << endl;
			Inventory.erase(Inventory.begin() + PlayerInput - 1);
			cout << "                  + + ITEM DELETED + +" << endl;
		}

		cout << "\n" << endl;
		system("pause");
		system("CLS");
	}
}

// Crystal craft system 
void CraftSystem(vector<string>& Inventory) 
{
	bool craftMenuOpen = true;

	int craftMenuOption;

	// While loop to keep the craff system open 
	while (craftMenuOpen) {

		string rawCrystal = "NA";
		string opaqueCrystal = "NA";

		bool isCrafted = false;

		// UI for the crafting system 
		cout << "+-------------------------------------------------------------+" << endl;
		cout << "                 + + OPAQUE CRYSTAL CRAFTING + +" << "\n" << endl;
		cout << " 1- Opaque Azure Dragon's Sapphire (Crystallized Azure Dragon's Tears)" << endl;
		cout << " 2- Opaque Humanity's Emerald (Crystallized Exiled Heretic's Bone)" << endl;
		cout << " 3- Opaque Feline's Ruby (Crystallized Great Feline's Ash)" << endl;
		cout << " 4- Exit" << endl;
		cout << "+-------------------------------------------------------------+" << endl;

		// Taking the player input 
		cout << "  Create Crystal:  "; cin >> craftMenuOption;

		// the UI shows which cystal that you need to craft the respective Opaque crystal 
		//  according to the input the switch will craft the set item
		switch (craftMenuOption) {

		case 1:
			rawCrystal = "Crystallized Azure Dragon's Tears";
			opaqueCrystal = "Opaque Azure Dragon's Sapphire";
			// function that checks if you have the respective crystal needed 
			//  the variables sent are: the cristal in the inventory and the crystal that is needed 
			//  for the opaque crystal
			isCrafted = OpaqueCrystal(rawCrystal, Inventory);
			break;

		case 2:
			rawCrystal = "Crystallized Exiled Heretic's Bone";
			opaqueCrystal = "Opaque Humanity's Emerald";
			isCrafted = OpaqueCrystal(rawCrystal, Inventory);
			break;

		case 3:
			rawCrystal = "Crystallized Great Feline's Ash";
			opaqueCrystal = "Opaque Feline's Ruby";
			isCrafted = OpaqueCrystal(rawCrystal, Inventory);
			break;

		case 4:
			craftMenuOpen = false;
			break;

		default:
			// in case the player inputs the wrong number it deletes the UI for it to be created again 
			system("CLS");
			break;
		}

		// If you have the correct crystal, the isCrafted variable will be true the program will replace the crystal 
		//   in your inventory to a opaque crystal
		if (isCrafted) {

			// This fucntion will replace the crystals, it receives the inventory so the item can be changed (Inventory)
			//  the crystal needed for the Opaque Crystal (rawCrystal)
			//  and the Opaque crystal that will replace the raw cristal (opaqueCrystal)
			ReplaceCrystal(rawCrystal, opaqueCrystal, Inventory);
			cout << "Opaque crystal crafted!" << endl;
			system("pause");

		}

	}

}

// Opaque crystal check 
bool OpaqueCrystal(string rawCrystal, vector<string> &Inventory)
{
	// This function is called when an Opaque is goin to be created 
	bool isCrafted = false;

	// The (find) will try to find the "rawCrystal" if it is in your inventory
	//  the raw crystal is received from the CraftingSystem function. 
	if (find(Inventory.begin(), Inventory.end(), rawCrystal) != Inventory.end()) {

		// If the correct crystal is in the inventory we turn isCrafted true so the opaque crystal can be replaced with the normal crystal
		isCrafted = true;

	}

	return isCrafted;

}

// Opaque crytal replacement 
void ReplaceCrystal(string rawCrystal, string opaqueCrystal, vector<string> & Inventory)
{

	int counter = 0;
	bool replaced = false;

	// The fucntion goes throuhg the inventory until the item is replaced 
	while (counter < Inventory.size() && !replaced) {
		// when the while finds the correct item in the inventory it enters onto the If 
		if (Inventory[counter] == rawCrystal)
		{
			// Here the crystal is repalce with the opaque crystal and then the while will end 
			Inventory[counter] = opaqueCrystal;
			replaced = true;

		}

		counter++;
	}
}

// Store function 
void ItemColection(vector<string>& Inventory, vector<string> &ItemList, bool CristalRemoved) {

	// In the fucntion a new vector is created, because is not gonna affect other areas of the program 
	vector<string> StoreList{};

	// Variables used for the function
	int min = 0;

	int max = 4;

	int RandomItem, PlayerInput;

	bool containsCrystal = false;

	bool ContainsCrystalTrue, OtherItemsInventory;
	
	bool GathererLoop = true;

	// Apart from the UI, this function si similar to the Inventory generator, but instead of going straight to the inventory the 
		cout << "+-------------------------------------------------------------+" << endl;
		cout << "                    + + Item Gatherer + + " << endl;
		// Check if a crystal hasn't been removed
		if (!CristalRemoved) {
			// For loop that first creates the Item list 
			for (int counter = 0; counter < 5; counter++) {
				RandomItem = rand() % (max - min + 1) - min;

				containsCrystal = CristalinInventory(Inventory);

				ContainsCrystalTrue = ((ItemList[RandomItem] == "Crystallized Azure Dragon's Tears") || (ItemList[RandomItem] == "Crystallized Exiled Heretic's Bone") || (ItemList[RandomItem] == "Crystallized Great Feline's Ash")) && containsCrystal;

				OtherItemsInventory = (count(Inventory.begin(), Inventory.end(), "Fishermen's Plate") >= 3) && (ItemList[RandomItem] == "Fishermen's Plate");

				if (!ContainsCrystalTrue && !OtherItemsInventory) {
					StoreList.push_back(ItemList[RandomItem]);
				}
			}

			// While loop that shows controls the Item gathering loop 
			while (GathererLoop) {

				// For loop that creates the UI 
				for (int I = 0; I < StoreList.size(); I++) {
					cout << " " << I + 1 << "- " << ItemList[I] << endl;
				}
				cout << " " << StoreList.size() + 1 << "- EXIT " << endl;
				cout << "+-------------------------------------------------------------+" << endl;
				cout << "  Select Item: " << endl; cin >> PlayerInput;

				// The palyer can also leave the loop, this is the if that checks this 
				if (PlayerInput == StoreList.size() + 1) {
					GathererLoop = false;
				}

				// Here the program deletes the item from the "Store" and moves the item to a space in the inventory 
				else if (Inventory.size() < 20) {
					Inventory.push_back(StoreList[PlayerInput - 1]);
					StoreList.erase(StoreList.begin() + PlayerInput - 1);
				}
				system("pause");
			}
		}
		else {
			// Crystal less store
			CrystalLessItemCollection(Inventory, ItemList, StoreList);
		}
}

// Crystal less Store 
void CrystalLessItemCollection(vector<string>& Inventory, vector<string>& Item, vector<string> &Store) {
	int counter = 0;

	int max = 4, min = 0;

	int RandomItem, PlayerInput;

	bool GathererLoop = true;

	// Similar behaviour to the other Item Colection fucntion, but there will be no crystal printed on the store 
	while (counter < 5) {
		RandomItem = rand() % (max - min + 1) - min;

		if ((Item[RandomItem] == "Iron Plate") || (Item[RandomItem] == "Fishermen's Plate")) {
			Store.push_back(Item[RandomItem]);
			counter++;
		}
	}
	while (GathererLoop) {
		for (int I = 0; I < Store.size(); I++) {
			cout << " " << I + 1 << "- " << Store[I] << endl;
		}
		cout << " " << Store.size() + 1 << "- EXIT " << endl;
		cout << "+-------------------------------------------------------------+" << endl;
		cout << "  Select Item: " << endl; cin >> PlayerInput;
		if (PlayerInput == Store.size() + 1) {
			GathererLoop = false;
		}
		else if (Inventory.size() < 20) {
			Inventory.push_back(Store[PlayerInput - 1]);
			Store.erase(Store.begin() + PlayerInput - 1);
		}
		system("pause");
	}
}

int main() {

	// Vectors that will be used ont he program, that will be sent as reference for all the functions that requiere them
	// The items for the stroe and the inventory generator 
	vector<string> ItemList{ "Crystallized Azure Dragon's Tears", "Crystallized Exiled Heretic's Bone", "Crystallized Great Feline's Ash", "Fishermen's Plate", "Iron Plate" };
	// Ivnetory vector 
	vector<string> ItemInventory{};

	// Bool variable that is sent as a reference, and is used to control wether the player deleted a crystal from the inventory 
	bool CristalRemoved = false;

	// Game loop controler 
	bool GameLoop = true;

	int PlayerInput;

	// Game loop, this loop will only end when the player lets it end
	while (GameLoop)
	{
		// Main menu UI 
		cout << "+-------------------------------------------------------------+" << endl;
		cout << "                        + + MAIN MENU + +" << "\n" << endl;
		cout << "  1- Inventory Generator " << endl;
		cout << "  2- Open Inventory" << endl;
		cout << "  3- Create Opaque Cristal" << endl;
		cout << "  4- Item Recolection " << endl;
		cout << "  5- EXIT" << endl;
		cout << "+-------------------------------------------------------------+" << endl;
		cin >> PlayerInput;

		switch (PlayerInput) {
		case 1:
			// Inventory Generator;
			if (ItemInventory.size() < 19) {
				InventoryGenerator(ItemInventory, ItemList, CristalRemoved);
			}
			else {
				cout << "INVENTORY FULL" << endl;
			}
			system("pause");
			system("CLS");
			break;
		case 2:
			// Open Inventory 
			OpenInventory(ItemInventory, CristalRemoved);
			break;
		case 3:
			// Create Opaque Cristal 
			CraftSystem(ItemInventory);
			system("pause");
			system("CLS");
			break;
		case 4:
			// Item Recolection 
			ItemColection(ItemInventory, ItemList, CristalRemoved);
			system("pause");
			system("CLS");
			break;
		case 5:
			//Exit 
			GameLoop = false;
			cout << "    + + THANKS FOR PLAYING + +" << endl;
			break;

		}

	}
	
}