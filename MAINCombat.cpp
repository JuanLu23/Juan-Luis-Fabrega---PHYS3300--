// Libraries that will be used on the program 
#include <iostream>
#include <vector>
#include <ctime>

// Namespace used on the program
using namespace std;

//All the functions that are necesary for the program.

// Function that prints the Menu with the updated player HP and enemy HP 
void Menu(int& playerHP, int& enemyHP);

// Fucntion that lets the player do a simple attack, it prints the amount of damage that the player dealt 
void SimpleAttack(int& playerHP, int& playerDEF, int& enemyDEF, int& enemyHP);

// Function that works as a simple inventory. The plaer has the amout of 3 potions, each time the player uses one the 
//  program decreases the amount that the player has. If the player runs out of potions the program lets the player know
void PotionInventory(int& playerHP, int& potions);

// Function that lets the player use it's special attacks. The Goring attack has a limit of 3 attacks over the course of the fight.
//	when the player burns throuhg all of its attacks the program locks that attack.
void SpecialAttacksList(int& playerHP, int& playerDEF, int& enemyDEF, int& enemyHP, int& goringblade);

// Function that simplifies the attack of the enemy
void EnemyAttack(int& playerHP, int& playerDEF, int& enemyDEF, int& enemyHP);

// Class created for the entities stats
class EntityStats {
public:
	int HP;
	int DEF;
	// The constructor of the class 
	EntityStats(int HealthPoint, int Defensa) {
		DEF = Defensa;
		HP = HealthPoint;
	}
};

// Function Menu, the function is mostly for astetic purposes
void Menu(int& playerHP, int& enemyHP) {
	cout << "========================================" << endl;
	cout << " - Player - " << playerHP << " HP" << endl;
	cout << " - Legendary Hero - " << enemyHP << " HP" << endl;
	cout << "========================================" << endl;
	cout << "What would you do!..." << endl;
	cout << "1 - Attack! " << endl;
	cout << "2 - Use Potion " << endl;
	cout << "3 - Especial Attack " << endl;
	cout << "4 - RUN!!" << endl;
	cout << "========================================" << endl;
}

// Fucntion Simple Attack, here the player attacks the enemy just with simple damage 
void SimpleAttack(int& playerHP, int& playerDEF, int& enemyDEF, int& enemyHP) {
	// Variable used to store the damage done to the enemy 
	int Damage;
	
	// I set the attack when the function is called, that way the attack is different each time
	int playerATK = rand() % (200 - 180 + 1) + 200;

	// This is the visual area of the function
	cout << "========================================" << endl;
	cout << "YOU ATTACK!.." << endl;
	
	// The ecuation for the damage 
	Damage = ((playerATK + 1) / enemyDEF);
	cout << "your attack dealth: " << Damage << endl;

	// We first calculated damage with the other ecuation, that way not only we can show the damage on the screen
	//  but we also need to obviusly reduce the HP of the entity being attacked
	enemyHP = enemyHP - Damage;

	// Since the enemy attacks every time after the player we call the function that makes the enemy attack
	//  after the player attacks
	EnemyAttack(playerHP, playerDEF, enemyDEF, enemyHP);
	
	// If statement that verifies when either the player or the enemy's HP reaches 0.
	//  each if statements has their respective menu message 
	if (playerHP <= 0) {
		playerHP = 0;
		cout << "THE LEGENDARY HERO HAS DEFETED YOU..." << endl;
		cout << "although you died, you fell a sence of victory. " << endl;
		cout << "Because there is no other way to see a mosnter that kills a deer just for fun.";
	}
	else if (enemyHP <= 0) {
		enemyHP = 0;
		cout << "YOU WON!!!" << endl;
		cout << "THE LEGENDARY HERO, as he calls himself is defeated" << endl;
		cout << "you defended the forest from that mosnter hope he doesnt' comes back..." << endl;
	}
}

// Function for the inventory, the function receives the player HP and potions counter 
void PotionInventory(int& playerHP, int& potions) {
	// The menu interface 
	cout << "========================================" << endl;
	cout << "=              INVENTORY               =" << endl;
	cout << "=Don't know how a deer has an inventory=" << endl;
	cout << "========================================" << endl;

	// Interface shows how many potions you have on your inventory 
	cout << " - Healing Potions (" << potions << ")" << endl;
	
	// If statement that lets the player take a potion if the player has an ammount greater than 0 
	if (potions > 0) {
		potions = potions -  1; 
		cout << " You healed 10 points of HP..." << endl;
		playerHP = playerHP + 10; 
	}
	system("pause");
	system("CLS");
}

// Function for the special attacks, similarly to the attacks this function receives the same elements 
void SpecialAttacksList(int& playerHP, int& playerDEF, int& enemyDEF, int& enemyHP, int& goringblade) {
	
	// Variables that are used in this function 
	int SpecialAttakcInput;
	int damage;
	
	// Player attack randomized on the functio so it can be generated again everytime the function is called
	int playerATK = rand() % (200 - 180 + 1) + 200;

	// Special attacks overlay 
	cout << "========================================" << endl;
	cout << "=          SPECIAL ATTAKCS             =" << endl;
	cout << "========================================" << endl;
	cout << " 1 - Goring Blade (" << goringblade << ")" << endl;
	cout << " 2 - Celestial Deer Ray" << endl;
	cout << "========================================" << endl;
	cout << " Choose your attack: " << endl;
	cin >> SpecialAttakcInput;
	switch (SpecialAttakcInput) {
	case 1:
		// Since goringblade can only be performe 3 times we enclose the damage on a if statment that way if the player chooses to attack no damage will occur 
		if (goringblade > 0) {
			cout << " You used the Goring Blade..." << endl;
			damage = ((playerATK + 5) / enemyDEF);
			cout << " It dealt: " << damage << " poits of damage" << endl;
			enemyHP = enemyHP - damage;
			goringblade = goringblade - 1;
		}
		else {
			cout << "You can't do this attack anymore..." << endl;
		}
		break;
	case 2:
		// Celestias Deer Ray has no condicions so the player can use it any time 
		cout << "CELESTIAL DEER RAY!!!" << endl;

		// I increased the modifier for the damage because the name of the attack seems more powerfull than what it was 
		damage = ((playerATK + 10) / enemyDEF);
		cout << "The forest heed your call, your attack dealt " << damage << " points of damage" << endl;
		enemyHP = enemyHP - damage;
		break;
	}
	// We end the function with an enemy attack because after each attack the player does the enemy attacks 
	EnemyAttack(playerHP, playerDEF, enemyDEF, enemyHP);
}


// Function for the Enemy attack, this fucntions 
void EnemyAttack(int& playerHP, int& playerDEF, int& enemyDEF, int& enemyHP) {

	// Similarlly to the simple Attack function the enemyAttack fucntion has the same elements 
	int Damage;
	int enemyATK = rand() % (210 - 190 + 1) + 200;
	cout << "THE LEGENDARY HERO ATTACKS!.." << endl;
	Damage = ((enemyATK + 1) / playerDEF);
	cout << "his attack deals: " << Damage << endl;
	playerHP = playerHP - Damage;
	cout << "========================================" << endl;
	// Since the function EnemyAttack is the last function executed we add the following, 
	//  insteado of adding system("") 
	system("pause");
	system("CLS");
}

// Main code of the program 
int main() {

	// Creating objects from for the class EntityStats 
	//  Player Object 
	EntityStats Player(100, 20);

	//  LegendaryHero Object
	EntityStats LegendaryHero(100, 10);
	
	// Other variables that will be used on the program. That will be sent to their respective functions as reference  
	int PotionAmount = 3;
	int GoringBlade = 3;

	// Variables that control what the player inputs and the game loop 
	bool CombatLoop = true;
	int PLayerInput = 0;

	// The game loop, this loop will stop when the player wins or looses or the player runs 
	while (CombatLoop) {
		// We fisrt call the Menu function so the player has a visual reference.
		//  The HP of each entity is sent so the player knows the information that it's need 
		Menu(Player.HP, LegendaryHero.HP);

		// The option that this variable receives will be in the function Menu 
		cin >> PLayerInput;
		switch (PLayerInput) {
		case 1:
			// The attack option 
			SimpleAttack(Player.HP, Player.DEF, LegendaryHero.DEF, LegendaryHero.HP);
			if (Player.HP <= 0 || LegendaryHero.HP <= 0) {
				CombatLoop = false;
			}
			break;
		case 2:

			// Use an Item 
			if (PotionAmount > 0) {
				PotionInventory(Player.HP, PotionAmount);
			}
			else {
				cout << "========================================" << endl;
				cout << "=              INVENTORY               =" << endl;
				cout << "=Don't know how a deer has an inventory=" << endl;
				cout << "========================================" << endl;
				cout << "=          INVENTORY EMPTY             =" << endl;
			}
			break;
		case 3:
			// Special Attacks 
			SpecialAttacksList(Player.HP, Player.DEF, LegendaryHero.DEF, LegendaryHero.HP, GoringBlade);
			break;
		case 4:
			// Run 
			CombatLoop = false;
			break;
		}
	};
}

