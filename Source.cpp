#include<iostream>
#include<string>
#include<fstream>
#include "Foodcort.h"
using namespace std;

int main()
{
	int choice;

	cout << "\n\t\t\t-----------------------------FoodCort WebApp-------------------------------" << endl;
	cout << "Press 1 to SignIn" << endl;
	cout << "Press 2 to SignUp" << endl;
	cout << "Press 3 to view customer detail" << endl;
	cout << "Press 4 to display Menu" << endl;
	cout << "Press 9 to Exit" << endl;

	do
	{
		cout << "Enter Option you want to select: " << endl;
		cin >> choice;
		cin.ignore();

		if (choice == 1)
		{
			Signin s1;
			string name, address, contact, password;

			cout << "Enter UserName: ";
			getline(cin, name);
			cout << "Enter Password: ";
			getline(cin, password);
			cout << "Enter Contact Info: ";
			getline(cin, contact);
			cout << "Enter Address: ";
			getline(cin, address);

			s1.setName(name);
			s1.setPassword(password);
			s1.setContactInfo(contact);
			s1.setAddress(address);

			s1.savingData();
			cout << "Data Saved Successfully!\n";
		}

		else if (choice == 2) // log in
		{
			string name, password;
			cout << "Enter UserName: ";
			getline(cin, name);  // read full name
			cout << "Enter Password: ";
			getline(cin, password);

			logIn l1(name, password);
			l1.checkfile();
			l1.display();
		}
		else if (choice == 3) // view customer
		{
			string uname;
			cout << "Enter username: ";
			getline(cin, uname);        // read full username with spaces

			Customer c1(uname);
			c1.display();
		}
		else if (choice == 4)
		{
			int menuChoice;
			int customerId = rand() % 100 + 1;
			Order currentOrder(1, customerId);

			do
			{
				cout << endl<<endl<<endl;
				cout << "===== MENU ====="<<endl;
				cout << "1. Vegetarian Dishes" << endl;
				cout << "2. Non-Vegetarian Dishes " << endl;
				cout << "3. Combo Dishes" << endl;
				cout << "4. Show Full Menu" << endl;;
				cout << "5. Add Item to Order" << endl;
				cout << "6. Remove Item from Order " << endl;
				cout << "7. View Current Order" << endl;
				cout << "8. Checkout & Pay " << endl;
				cout << "9. Rating " << endl;
				cout << "10. Exit Menu" << endl;

				cout << "Enter choice: ";
				cin >> menuChoice;
				cin.ignore();

				if (menuChoice == 1)
				{
					Vegetarion v1;
				}
				else if (menuChoice == 2)
				{
					Non_Vegetarion v2;
				}
				else if (menuChoice == 3)
				{
					comboDeals v3;
				}
				else if (menuChoice == 4)
				{
					Menu m;
					m.Veg();
					m.Non_Veg();
					m.ComboItems();
				}
				else if (menuChoice == 5)
				{
					ifstream files[3] = {
						ifstream("nonveg.txt"),
						ifstream("Veg.txt"),
						ifstream("comboItems.txt")
					};

					string itemName, savedItem;
					int savedId, savedPrice;
					bool found = false;

					cout << "Enter Item Name: ";
					getline(cin, itemName);

					for (int f = 0; f < 3 && !found; f++)
					{
						while (files[f] >> savedId >> savedPrice)
						{
							getline(files[f] >> ws, savedItem);
							if (savedItem == itemName)
							{
								Menu selectedItem;
								selectedItem.setId(savedId);
								selectedItem.setName(savedItem);
								selectedItem.setPrice(savedPrice);

								currentOrder + selectedItem;
								cout << "Item Added Successfully!" << endl;
								found = true;
								break;
							}
						}
						files[f].close();
					}

					if (!found)
						cout << "Item not found!" << endl;
				}

				else if (menuChoice == 6)
				{
					if (currentOrder.getTotalPrice() == 0)
					{
						cout << "Order is empty. Nothing to remove!" << endl;
						continue;
					}
					int id;
					cout << "Enter Item Id to Remove" << endl;
					cin >> id;
					Order order1(1, 101);
					currentOrder.removeItemById(id);
					currentOrder.displayOrder();

				}

				else if (menuChoice == 7)
				{
					currentOrder.displayOrder();
				}
				else if (menuChoice == 8)
				{
					if (currentOrder.getTotalPrice() == 0)
						cout << "No items in order!" << endl;
					else
					{
						currentOrder.displayOrder();
						Payment p(rand() % 1000 + 1, 1, currentOrder.getTotalPrice());
						p.processPayment();
						p.displayPayment();

						currentOrder = Order(1, customerId);
					}
				}
				else if (menuChoice == 9)
				{
					// ===== REVIEW USING USERNAME FROM FILE =====
					Review r1;
					int rating;
					string comment;

					cout << "Enter Rating from(1-5): ";
					cin >> rating;

					cout << "Enter Comment: ";
					cin.ignore();
					getline(cin, comment);

					r1.giveRating(rating, comment);
					r1.viewReviews();


				}
				else if (menuChoice == 10)
				{
					cout << "Exiting Menu..." << endl;
					break;
				}
				else
				{
					cout << "Invalid Option!" << endl;
				}

			} while (true);
		}

		else if (choice == 9)
		{
			cout << "Exiting Program..." << endl;
			break;
		}
		else
		{
			cout << "Invalid Option!" << endl;
		}

	} while (true);

	return 0;
}

