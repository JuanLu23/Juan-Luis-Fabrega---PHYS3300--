// Program that will generate a random password each time the program starts 
// Libraries that will be used on the program 
#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include <cstdlib>

using namespace std;

// All the functions needed for the program 
// Function in charge of calling other fucntions that contain the characters for the password 
void PasswordGenerator(vector<string>& Pasword, vector<string> Letters, vector<string> Characters, vector<string> Numbers);

// Function that contains and chooses the letters characters for the pasword 
void RandomPasswordLetters(vector<string>& Pasword, vector<string> Letters);

// Function that contains and chooses the Characters for the password 
void RandomPasswordCharacters(vector<string>& Pasword, vector<string> Characters);

// Function that contains and chooses numbers for the password 
void RandomPasswordNumbers(vector<string>& Pasword, vector<string> Numbers);

// Function that will check if the vector has the character choosen already stored 
bool CharacterinInventory(vector<string>& Pasword, vector<string> Character, int CharacterIndex);

// Password generation function 
void PasswordGenerator(vector<string> &Pasword,vector<string> Letters,vector<string> Characters,vector<string> Numbers) {

	//variables used for the generation 
	int RandNum;

	int min = 0;

	int max = 5;

	bool LoopEnd = true;

	// While function that fills the vector with characters until LoopEnd is set false 
	while (LoopEnd) {

		// if statement that checks if the password is passed the amount needed 
		if (Pasword.size() < 8) {

			// Rand number generated so the function chooses different characters to generate the password 
			RandNum = rand() % (max - min + 1) - min;
			switch (RandNum) {
			case 0:
				// function for the Letters, the vector password are sent by reference and the letters are just sent as a copy 
				RandomPasswordLetters(Pasword, Letters);
				break;
			case 1:
				// Function that set the Espacial Characters for the pasword, pasword vector is sent as a reference 
				//		character is sent as a copy 
				RandomPasswordCharacters(Pasword, Characters);
				break;
			case 2:
				// Function that set Numbers for the password, similar as before password vector is sent as a reference 
				//		and number vector is sent as a copy 
				RandomPasswordNumbers(Pasword, Numbers);
				break;
			default:
				break;
			}
		}
		// If the Password.size() is greater than 8 goes into the else 
		else {
			LoopEnd = false;
		}

	}

}

// Letter fucntion. This function receives the pasword as reference because it needs to receive the characters, 
//		and the letter vector is sent as a copy becase there is nothing to change in that vector
void RandomPasswordLetters(vector<string>& Pasword, vector<string> Letters) {
	
	// Variables used for the function 
	int RandNum;

	int min = 0;

	int max = 25;

	bool LetterSelected = true;

	bool CointanChecked = false;

	// While loop that will generate in a random letter each time it begins 
	while (LetterSelected) {

		RandNum = rand() % (max - min + 1) - min;
		// Variable that has the inventory check, if the RandNum choosen is already stored on the Password this varibale
		//   will not change and another letter will be choosen 
		CointanChecked = CharacterinInventory(Pasword, Letters, RandNum);

		// If check that adds the letter to the password if it isn't on the password already 
		if (!CointanChecked) {
			Pasword.push_back(Letters[RandNum]);
			LetterSelected = false; 
		}
	}

}

// Letter fucntion. This function receives the pasword as reference because it needs to receive the characters, 
//		and the Especial Characters vector is sent as a copy becase there is nothing to change in that vector
void RandomPasswordCharacters(vector<string>& Pasword, vector<string> Characters) {

	int RandNum;

	int min = 0;

	int max = 6;

	bool LetterSelected = true;

	bool CointanChecked = false;

	while (LetterSelected) {

		RandNum = rand() % (max - min + 1) - min;
		// Variable that has the inventory check, if the RandNum choosen is already stored on the Password this varibale
		//   will not change and another Especial Characters will be choosen 
		CointanChecked = CharacterinInventory(Pasword, Characters, RandNum);

		if (!CointanChecked) {
			Pasword.push_back(Characters[RandNum]);
			LetterSelected = false;
		}
	}

}

// Number fucntion. This function receives the pasword as reference because it needs to receive the characters, 
//		and the Number vector is sent as a copy because there is nothing to change in that vector
void RandomPasswordNumbers(vector<string>& Pasword, vector<string> Numbers) {

	int RandNum;

	int min = 0;

	int max = 8;

	bool LetterSelected = true;

	bool CointanChecked = false;

	while (LetterSelected) {

		RandNum = rand() % (max - min + 1) - min;

		// Variable that has the inventory check, if the RandNum choosen is already stored on the Password this varibale
		//   will not change and another Numbers will be choosen
		CointanChecked = CharacterinInventory(Pasword, Numbers, RandNum);

		if (!CointanChecked) {
			Pasword.push_back(Numbers[RandNum]);
			LetterSelected = false;
		}
	}

}

// Fucntion that checks the incentory for the received vector<string> Character into the Pasword vector 
bool CharacterinInventory(vector<string>& Pasword, vector<string> Character, int CharacterIndex) {

	// variables used on the function 
	int count = 0; 

	bool CharacterPresent = false; 

	bool CharacterinInvenroty; 

	// The while will check one by one in the spaces on the inventory untill its finds or not a character on the inventory 
	while ((count < Pasword.size()) && (!CharacterPresent)) {

		// Variable that stores if a character is equal to the selected selected character by the program  
		CharacterinInvenroty = (Pasword[count] == Character[CharacterIndex]);

		if (CharacterinInvenroty) {

			// Variable that is retured so the program can choose another character in their respective function 
			CharacterPresent = true;
		}
		count++;

	}
	return CharacterPresent;

}

int main() {

	srand(time(0));

	int count = 0;

	// Vectors used on the inventory 
	// Vector storing the Letters characters 
	vector<string> Letters{ "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
	// Vector storing the Special characters
	vector<string> Characters{ "&", "/", "-", "_", "%", "#", "@" };
	//Vector storing the Number characters
	vector<string> Numbers{ "1","2","3","4","5","6","7","8","9","0" }; 
	// Vector Password 
	vector<string> Password{};

	// There is only the need to call one function because PasswordGenerator is incharge of doing the res 
	//  I send Password as a reference becuase it needs to have the characters stored, but the others vecotrs it does not 
	//	matter if is sent as a copy 
	PasswordGenerator(Password, Letters, Characters, Numbers);

	// Printing the password and added a small interface
	cout << "Generating pasword..." << endl; 
	while (count < Password.size()) {
		cout << Password[count] << "\t" << endl;
		count++;
	}

	return 0; 
}