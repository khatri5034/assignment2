// TO DO: #include all the standard libraries and your own libraries here
#ifndef VENDOR_H
#define VENDOR_H
#include <iostream>
#include <string>
#include "LinkedBagDS/LinkedBag.h"

#include"Good.h"
#include"Media.h"
#include"Product.h"


//
// To DO: define the class Vendor with the necessary functions and data fields
class Vendor{
  private:
    std::string username;
    std::string email;
    std::string password;
    std::string bio;
    std::string profilePicture;
    LinkedBag<Product*> bag;

  public:
    Vendor();
  ~Vendor();
    Vendor(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture);
    std::string getUsername();
    std::string getEmail();
    std::string getPassword();
    std::string getBio();
    std::string getProfilePicture();

    void addProduct( Product* product);
    void display();
    bool modifyPassword();
    void createProduct();
    void displayProduct(int k);
    void displayAll();
    bool sellProduct(int k, int quantity);
    bool deleteProduct(int k);
    bool sell(int index);
    bool operator==(const Vendor& otherVendor) const;
};
#endif
// This is a function that allows you to compare two vendors based on their username and email address.  
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator == overloading function prototype:

