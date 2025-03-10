#include <iostream> 
#include <string>
#include "Amazon340.h"
#include "Vendor.h"

using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type Vendor
 * @param vendor object to interact with
 * 
 * */
void displayVendorMenu(Vendor& vendor)
{
	int vendorChoice = 0;

	do
	{
		cout << endl << "Hi, " << vendor.getUsername() << ", what would you like to do:\n"
			<< "1. Display Profile\n"
			<< "2. Modify Password\n"
			<< "3. Create Product\n"
			<< "4. Display All Products\n"
			<< "5. Display Kth Product\n"
			<< "6. Modify Product\n"
			<< "7. Sell Product\n"
			<< "8. Delete Product\n"
			<< "0. Logout\n"
			<< "Choice: ";
		cin >> vendorChoice;
		cin.ignore();
		cout << endl;

		switch (vendorChoice)
		{
			case 1:
			{
				vendor.displayProfile();
				break;
			}
			case 2:
			{
				string password;

				cout << "Enter new password: " << endl;
				getline(cin, password);

				if (vendor.modifyPassword(password))
					cout << "Your password has been modified successfully." << endl;
				else
					cout << "Your new password cannot be same as old password." << endl;

				break;
			}
			case 3:
			{
				int productType;
				string name, description;

				cout << "What type of product (1 for Media, 2 for Good, 0 for Return): ";
				cin >> productType;
				cin.ignore();
				cout << endl;

				switch (productType)
				{
					case 1:
					{
						string type, targetAudience;

						cout << "Enter media name: " << endl;
						getline(cin, name);

						cout << "Enter media description: " << endl;
						getline(cin, description);

						cout << "Enter media type: " << endl;
						getline(cin, type);

						cout << "Enter target audience: " << endl;
						getline(cin, targetAudience);

						Media* media = new Media(name, description, type, targetAudience);
						
						cout << endl;

						if (vendor.createProduct(media))
							cout << media->getName() << " has been created successfully." << endl;
						else
							cout << "Failed to create media." << endl;

						break;
					}
					case 2:
					{
						string expirationDate;
						int quantity;

						cout << "Enter good name: " << endl;
						getline(cin, name);

						cout << "Enter good description: " << endl;
						getline(cin, description);

						cout << "Enter expiration date: " << endl;
						getline(cin, expirationDate);

						cout << "Enter quantity: " << endl;
						cin >> quantity;
						cin.ignore();

						Good* good = new Good(name, description, expirationDate, quantity);

						cout << endl;

						if (vendor.createProduct(good))
							cout << good->getName() << " has been created successfully." << endl;
						else
							cout << "Failed to create good." << endl;

						break;
					}
					case 0:
						break;
					default:
						cout << "Invalid choice." << endl;
				}

				break;
			}
			case 4:
			{
				cout << "Product List: " << endl;
				vendor.displayAllProducts();

				break;
			}
			case 5:
			{
				int k, size = vendor.getProductListSize();

				cout << "Enter the value K: ";
				cin >> k;
				cin.ignore();

				cout << endl;

				if (k < 1 || k > size)
					cout << "Value entered must be between 1 and the product list size." << endl
						<< "Product list size: " << size << endl;
				else
					vendor.displayProductK(size - k);

				break;
			}
			case 6:
			{
				int k, size = vendor.getProductListSize();

				cout << "Enter the product index to modify: ";
				cin >> k;
				cin.ignore();

				if (k < 1 || k > size)
					cout << "Value entered must be between 1 and the product list size." << endl
					<< "Product list size: " << size << endl;
				else
				{
					string name, description;

					cout << "Enter new name: " << endl;
					getline(cin, name);

					cout << "Enter new description: " << endl;
					getline(cin, description);

					cout << endl;

					if (vendor.modifyProduct(k, name, description))
						cout << "Product has been modified." << endl;
					else
						cout << "Failed to modify product." << endl;
				}

				break;
			}
			case 7:
			{
				int k, size = vendor.getProductListSize();

				cout << "Enter the product index to sell: ";
				cin >> k;
				cin.ignore();

				if (k < 1 || k > size)
					cout << "Value entered must be between 1 and the product list size." << endl
					<< "Product list size: " << size << endl;
				else
				{
					int quantity;

					cout << "Enter the quantity to sell: ";
					cin >> quantity;
					cin.ignore();

					cout << endl;

					if (vendor.sellProduct(k, quantity))
						cout << "Product has been sold." << endl;
					else
						cout << "The product is sold-out." << endl;
				}

				break;
			}
			case 8:
			{
				int k, size = vendor.getProductListSize();

				cout << "Enter the product index to delete: ";
				cin >> k;
				cin.ignore();

				cout << endl;

				if (k < 1 || k > size)
					cout << "Value entered must be between 1 and the product list size." << endl
					<< "Product list size: " << size << endl;
				else
					if (vendor.deleteProduct(k))
						cout << "Product has been deleted." << endl;
					else
						cout << "Failed to delete product." << endl;

				break;
			}
			case 0: {
				cout << "Logging you out." << endl;
				break;
			}
			default:
				cout << "Invalid choice. Please try again." << endl;
		}

	} while (vendorChoice != 0);
}


int main()
{
	Amazon340 amazon340;
	string username, email, password, bio, profilePicture;

	cout << "Welcome to Amazon340:" << endl;

	cout << "Enter your username: " << endl;; //prompt to enter vendor information
	getline(cin, username);
	
	cout << "Enter your email: " << endl;;
	getline(cin, email);

	cout << "Enter your password: " << endl;;
	getline(cin, password);

	cout << "Enter your bio: " << endl;;
	getline(cin, bio);

	cout << "Enter your profile picture path: " << endl;;
	getline(cin, profilePicture);

	amazon340.createVendor(username, email, password, bio, profilePicture); //create vendor
	Vendor currentVendor = amazon340.getVendor(); //retrieve vendor

	displayVendorMenu(currentVendor); //display main menu
				
	return 0;
}
