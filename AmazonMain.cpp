#include <iostream> 
#include <string>
#include "LinkedBagDS/LinkedBag.h"
// TO DO: #include any other libraries you need
#include "Amazon340.h"
#include"Vendor.h"
#include"vector"
#include"Media.h"
#include"Product.h"

using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type Vendor
 * @param vendor object to interact with
 * 
 * */
void displayVendorMenu(Vendor& vendor){
	int vendorChoice = 0;
	do {
		cout << "\n Hi, "<< vendor.getUsername() <<", what would you like to do:\n"
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

		switch (vendorChoice) {
			case 1:{
				// TO DO: display vendor's profile information
				 vendor.display();
				break;
			}
			case 2: {
				// TO DO: ask for new password and update vendor's password
				vendor.modifyPassword();
				break;
			}
			case 3: {
				// TO DO: ask vendor to choose product type, then ask them to input product details.
				int productType;
				std::string name, description, type, targetAudience,expirationDate;
				int rating, soldCount, quantity;

				std::cout << "Enter Product type: 1 for Media and 2 for Good: "<<std::endl;
				std::cin >> productType;
				std::cin.ignore();

				std::cout << "Enter Product Name: "<<std::endl;
				std::getline(std::cin, name);

				std::cout << "Enter Product Description: "<<std::endl;
				std::getline(std::cin, description);

				std::cout << "Enter Product Rating (0-5): "<<std::endl;

				while (true) {
					if (std::cin >> rating && rating >= 0 && rating <= 5) {
						break;
					}
					else {
						std::cout << "Please enter a valid rating! (0-5)"<<std::endl;
					}
				}
				std::cin.ignore();
				if (productType == 1) {
					std::cout << "Enter Media Type: "<<std::endl;
					std::getline(std::cin, type);

					std::cout << "Enter Target Audience: "<<std::endl;
					std::getline(std::cin, targetAudience);
					soldCount=0;

					Media* newMedia= new Media(name, description, rating, soldCount, type, targetAudience);

					vendor.addProduct(newMedia);
					std::cout << "Media product added successfully!\n"<<std::endl;
				}
				else if (productType == 2) {

					std::cout << "Enter Good's expiration date: "<<std::endl;
					std::getline(std::cin,expirationDate);

					std::cout << "Enter Stock Quantity: "<<std::endl;
					while (true) {
						if (cin >> quantity && quantity > 0) {
							break;
						}
						else {
							std::cout << "Please enter a valid add count!"<<std::endl;
						}
					}
						}
				else {
							std::cout << "Invalid product type selection.\n"<<std::endl;
				}
				Good* newGood= new Good(name, description, rating, soldCount, , targetAudience);

				vendor.addProduct(newGood);
				std::cout << "Good product added successfully!\n"<<std::endl;
				break;
			}
			case 4:{
				std::cout << "Products you have in stock: "<<std::endl;
				vendor.displayAll();
				// TO DO: display all vendor's products
				//        You may re-use code from class demo
				break;
			}
			case 5: {
				std::cout<<"Enter the kth product :"<<std::endl;
				int k;
				std::cin>>k;
				// TO DO: ask the vendor for a value k
				// Find the Kth product, if k > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				vendor.displayProduct(k);
				break;
			}
			case 6: {
				// TO DO: ask the vendor for the index of the product they want to modify.
				// Find the product, then prompt them for the new name and description.
				// Modify the product accordingly. 
				// If index > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				break;
			}
			case 7: {

				// TO DO: ask the vendor for the index of the product they want to sell
				std::cout<<"Enter the product index you want to sell: "<<std::endl;
				int index;
				std::cin>>index;
				vendor.sell(index);
				// Find the product, then sell the product. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
				break;
			}
			case 8:{
				std::cout<<"Enter the product index you want to delete: "<<std::endl;
				int index;
				std::cin>>index;
				vendor.sell(index);
				// TO DO: ask the vendor for the index of the product they want to delete 
				// Find the product, then remove it from the list. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
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


int main(){
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one vendor
	Amazon340 amazon340; 

	cout << "\n Welcome to Amazon340:" << endl;
	// TO DO: Ask the vendor to enter their information 
	//        Instantiate a new Vendor object


	// call amazon340 createVendor function 
	// replace /*...*/ with the right parameters
	amazon340.createVendor("kiran", "kiran@gmail", "Kiran5034", "hello", ".jjjf.kkf");


	// Retrieve the vendor 
	Vendor currentVendor = amazon340.getVendor();

	// Display the main menu
	displayVendorMenu(currentVendor);
				
	return 0;
}