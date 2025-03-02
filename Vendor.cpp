// TO DO: #include needed standard libraries and your own libraries here
#include <iostream>
#include <string>
#include "LinkedBagDS/LinkedBag.h"

#include"Good.h"
#include"Media.h"
#include"Product.h"
#include "Vendor.h"

// TO DO: function implementations

// Operator == overloading implementation
Vendor::Vendor(){};
Vendor ::Vendor(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture){
    this->username = username;
   this->email = email;
    this->password = password;
    this->bio = bio;
    this->profilePicture = profilePicture;

    this->bag = new LinkedBag<Product>();


}
void Vendor::addProduct( Product* product){
bag->add(*product);
}
bool Vendor ::operator==(const Vendor& otherVendor) const {
	return (Vendor::username == otherVendor.username) && (Vendor::email == otherVendor.email);
}
std::string Vendor::getUsername() {
  return Vendor::username;
}
std::string Vendor::getEmail(){
  return Vendor::email;
}
std::string Vendor::getBio(){
  return Vendor::bio;
}
std::string Vendor::getProfilePicture(){
  return Vendor::profilePicture;
}
void Vendor::display() {
  std::cout << "Vendor: " << Vendor::getUsername() << std::endl;
}
bool Vendor::modifyPassword() {
  std::cout<<"Enter the new password: "<<std::endl;
  std::cin>>Vendor::password;
  return true;
}
void Vendor::displayProduct(int k) {
  std::vector<Product> products = bag->toVector();
std::cout << "Product " << k << ": " << std::endl;
        std::cout << "Name: " << products[k-1].getName() << std::endl;
        std::cout << "Description: " << products[k-1].getDescription() << std::endl;
        std::cout << "Rating: " << products[k-1].getRating() << std::endl;
        std::cout << "Add Count: " << products[k-1].getAddCount() << std::endl;
}
;