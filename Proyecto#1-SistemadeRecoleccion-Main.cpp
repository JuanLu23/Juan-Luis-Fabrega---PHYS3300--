//Importamos las librerias necesarias.
#include<iostream>
#include<vector>
#include<string>
#include<ctime>

//Incluimos el namespace std.
using namespace std;

//Declaramos las funciones a utilizar con punteros y pass by reference.
vector<string> generateInventory(vector<string>& allItems);
void pickUpInventory(vector<string>& inventoryRef, vector<string>& pickUpItemsRef);
void openInventory(vector<string>& inventoryRef, vector<string>& allItemsRef);

//Funcion para generar el inventario realizando un pass by reference.
vector<string> generateInventory(vector<string>& allItemsRef)
{
	//Declaramos el inventario.
	vector<string> randomInventory(7, "NA");

	//Variables para el uso de rand.
	int randomItemPos;
	int min = 0;
	int max = allItemsRef.size() - 1;

	//Variable de contador para el ciclo while.
	int counter = 0;

	//Ciclo para llenar el inventario de manera aleatoria.
	while (counter < randomInventory.size())
	{
		//Para la posicion random
		randomItemPos = rand() % (max - min + 1) + min;
		randomInventory[counter] = allItemsRef[randomItemPos];
		counter++;
	}
	system("CLS");
	cout << "INVENTORY GENERATED! \n\n" << endl;
	system("pause");
	return randomInventory;
}

//Funcion para generar nuevos objetos y que el usuario los recoja realizando un pass by reference.
void pickUpInventory(vector<string>& inventoryRef, vector<string>& pickUpItemsRef)
{
	//Vector para los items que se podran recoger.
	vector<string> pickItemsInventory(5);

	//Crear un seed distinto
	srand(time(0));

	//Variables para entrada del usuario, contador y para crea las posiciones random de los items.
	int destroyed;
	int userInput;
	int randomItemPos;
	int min = 0;
	int max = pickUpItemsRef.size() - 1;
	int counter = 0;

	//Booleanas para mantener el inventario abierto y determinar la cantidad de objetos y cristales sean la cantidad posible(1 cristal y maximo 3 fishermen plate).
	bool pickUpInventoryOpened = true;
	bool containsCrystal = false;
	bool longBooleanExpression;
	bool shortBooleanExpression;

	//Ciclo que genera los 5 objetos aleatorias para escoger del usuario.
	while (counter < pickItemsInventory.size())
	{
		//Para la posicion random
		randomItemPos = rand() % (max - min + 1) + min;

		//Si el item random que se escoge es un cristal y hay un cristal en el inventario, este cambiara a true.
		longBooleanExpression = ((pickUpItemsRef[randomItemPos] == "Roca Blanda") || (pickUpItemsRef[randomItemPos] == "Roca Dura") || (pickUpItemsRef[randomItemPos] == "Roca Cristalina") || (pickUpItemsRef[randomItemPos] == "Roca Magica")) && containsCrystal;

		//Agregara cualquier cosa siempre y cuando no exista un cristal
		if (!longBooleanExpression)
		{
			pickItemsInventory[counter] = pickUpItemsRef[randomItemPos];
			counter++;
		}
	}

	//Ciclo para mantener el recolector de objetos abierto.
	while (pickUpInventoryOpened)
	{
		system("CLS");
		cout << "===============================================================" << endl;
		cout << "= = ITEMS PICK UP = =" << "\n" << endl;

		//Ciclo que itera sobre los pick up items y lo imprime.
		for (int counter = 0; counter < pickItemsInventory.size(); counter++)
		{
			cout << counter + 1 << ". " << pickItemsInventory[counter] << endl;
		}
		cout << pickItemsInventory.size() + 1 << ". " << "EXIT" << endl;
		cout << "===============================================================" << endl;
		cout << "AWAITING USER INPUT:  "; cin >> userInput;

		//If para determinar los objetos que pasaran al inventario.
		if (userInput <= pickItemsInventory.size())
		{
			//If que a;ade los nuevos objetos al inventario.
			if ((pickItemsInventory[userInput - 1] == "Roca Blanda") || (pickItemsInventory[userInput - 1] == "Roca Dura") || (pickItemsInventory[userInput - 1] == "Roca Cristalina"))
			{
				//If/Else if para limitar la capacidad del inventario y enviar el item seleccionado al inventario.
				if (inventoryRef.size() >= 20)
				{
					cout << "INVENTORY FULL" << endl;
					system("pause");
				}
				else if (inventoryRef.size() < 20)
				{
					//Variable que guardara el valor asignado por rand.
					destroyed = rand() % 100 + 1;

					//if que actuara cuando el valor de rand sea mayor a 25 y agregare el objeto al inventario.
					if (destroyed > 25)
					{
						inventoryRef.push_back(pickItemsInventory[userInput - 1]);
						cout << "New Item Added!" << endl;
						cout << "You have " << inventoryRef.size() << " out of 20." << endl;
						system("pause");
						pickItemsInventory.erase(pickItemsInventory.begin() + userInput - 1);
					}
					//De ser menor a 26 este destruira el objeto.
					else if (destroyed < 26)
					{
						cout << "The rock got destroyed right in your hand..." << endl;
						system("pause");
						pickItemsInventory.erase(pickItemsInventory.begin() + userInput - 1);
					}
				}
			}
			else if ((pickItemsInventory[userInput - 1] == "Roca Magica"))
			{
				if (inventoryRef.size() >= 20)
				{
					cout << "INVENTORY FULL" << endl;
					system("pause");
				}
				else if (inventoryRef.size() < 20)
				{
					//Variable que guardara el valor asignado por rand.
					destroyed = rand() % 100 + 1;

					//If que agregara la piedra magica al inventario si la variable es mayor a 50.
					if (destroyed > 50)
					{
						inventoryRef.push_back(pickItemsInventory[userInput - 1]);
						cout << "New Item Added!" << endl;
						cout << "You have " << inventoryRef.size() << " out of 20." << endl;
						system("pause");
						pickItemsInventory.erase(pickItemsInventory.begin() + userInput - 1);
					}
					//Destruira la piedra si la variable destroyed es menor a 50.
					else if (destroyed < 51)
					{
						cout << "The magic rock just dissapear right in your hand..." << endl;
						system("pause");
						pickItemsInventory.erase(pickItemsInventory.begin() + userInput - 1);
					}
				}
			}
		}
		else if (userInput == pickItemsInventory.size() + 1)
		{
			pickUpInventoryOpened = false;
		}
	}
}

//Funcion para el inventario con pass by reference.
void openInventory(vector<string> &inventoryRef, vector<string> &allItemsRef)
{
	//Booleana para abrir el inventaro y determinar si se destruyo algun cristal.
	bool inventoryOpened = true;

	//Variable para entrada del usuario.
	int userInput;
	string userInput2;

	//Ciclo para mantener el inventario abierto.
	while (inventoryOpened)
	{
		system("CLS");
		cout << "===============================================================" << endl;
		cout << "= = INVENTORY = =" << "\n" << endl;

		//Ciclo que itera sobre el inventario y lo imprime.
		for (int counter = 0; counter < inventoryRef.size(); counter++)
		{
			cout << counter + 1 << ". " << inventoryRef[counter] << endl;
		}

		cout << inventoryRef.size() + 1 << ". " << "EXIT" << endl;
		cout << "===============================================================" << endl;
		cout << "You have " << inventoryRef.size() << " out of 20." << endl;
		cout << "AWAITING USER INPUT:  "; cin >> userInput;
		
		if (userInput <= inventoryRef.size())
		{
			inventoryRef.erase(inventoryRef.begin() + userInput - 1);
		}
		else if (userInput == inventoryRef.size() + 1)
		{
			inventoryOpened = false;
		}
	}
}

int main()
{
	//Vector para el inventario y los items disponibles.
	vector<string> inventory;
	vector<string> allItems = { "Hierba Mala(HM)", "Gusano Dorado(GD)" };
	vector<string> pickUpItems = { "Roca Blanda", "Roca Dura", "Roca Cristalina", "Roca Magica" };

	//Booleana para mantener el menu abierto.
	bool menuOpen = true;

	//Entrada del usuario.
	int mainMenuOption;

	//Ciclo while para mantener el menu abierto.
	while (menuOpen)
	{

		//Este comando limpia la ventana de comandos. 
		system("CLS");

		//UI para el menu
		cout << "===============================================================" << endl;
		cout << "= = MAIN MENU = =" << "\n" << endl;
		cout << "1. INVENTORY GENERATOR (FOR DEVELOPERS)" << endl;
		cout << "2. OPEN INVENTORY" << endl;
		cout << "3. PICK UP ITEMS" << endl;
		cout << "4. EXIT GAME" << endl;
		cout << "===============================================================" << endl;

		//Leemos la entrada del usuario. 
		cout << "AWAITING USER INPUT:  "; cin >> mainMenuOption;

		//Switch para el menu de entrada del usuario.
		switch (mainMenuOption)
		{

		case 1:
			inventory = generateInventory(allItems);
			break;

		case 2:
			openInventory(inventory, allItems);
			break;

		case 3:
			pickUpInventory(inventory, pickUpItems);
			break;

		case 4:
			menuOpen = false;
			break;

		default:
			system("CLS");
			break;
		}
	}
	return 0;
}