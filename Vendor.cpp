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

}
    Vendor::~Vendor(){
}
void Vendor::addProduct( Product* product){
Vendor::bag.add(product);
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
  std::cout << "Vendor: " << Vendor::getUsername()<<"\nEmail: "<<email<<"\nBio: "<<bio<<"\nProfile picture: "<<profilePicture<< std::endl;
}

bool Vendor::modifyPassword() {
  bool modified = false;
  std::string newPassword;
  while(true){
  std::cout<<"Enter the new password: "<<std::endl;
  std::cin>>newPassword;
  if(newPassword == Vendor::password||newPassword.length()<8){
    if(newPassword.length()<8){
      std::cout<<"Password should be at least 8 or more characters!"<<std::endl;
    }
    else{
    std::cout<<"Please, enter the password different than the old password!"<<std::endl;
}
  }
  else
    {
    password=newPassword;
        modified = true;
    std::cout<<"Successfuly updated password!"<<std::endl;
    break;
    }
  }
return modified;
}

bool Vendor::sell(int index) {
  std::vector<Product*> products = bag.toVector();
  if (index < 1 || index > products.size()) {
        std::cout << "Invalid product index! Please enter a number between 1 and " << products.size() << "." << std::endl;
        return false;
    }
    else
      {
      Product* product = products[index - 1];
      product->sell(index);
      delete product;
    }return true;

}

void Vendor::displayProduct(int k) {
  std::vector<Product*> products = bag.toVector();
 if (k < 1 || k > products.size()) {
        std::cout << "Invalid product index. Please enter a number between 1 and "
                  << products.size() << "." << std::endl;
        return;
    }
    std::cout << "Product " << k << ":" << std::endl;
    products[k-1]->display();
}

void Vendor::displayAll(){
    std::vector<Product*> products = bag.toVector();
    if (products.empty()) {
        std::cout << "No products available." << std::endl;
        return;
    }
    for (int i = 0; i < products.size(); ++i) {
        std::cout << "Product " << (i+1) << ":" << std::endl;
        products[i]->display();
        std::cout << std::endl;
    }
}

bool Vendor::deleteProduct(int k) {
    std::vector<Product*> products = bag.toVector();
    if (k < 1 || k > products.size()) {
        std::cout << "Invalid product index. Please enter a number between 1 and "
                  << products.size() << "." << std::endl;
        return false;
    }
    Product* productToDelete = products[k-1];
    bag.remove(productToDelete);
    delete productToDelete;
    return true;
}


