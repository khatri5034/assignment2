#include <iostream>
#include <string>
#include "Vendor.h"
#include "Product.h"
#include "Good.h"
#include "Media.h"

using namespace std;

Vendor::Vendor() {} //default constructor

Vendor::Vendor(const string& username, const string& email, const string& password, const string& bio, const string& profilePicture) //constructor with param
    : username(username), email(email), password(password), bio(bio), profilePicture(profilePicture) {}

Vendor::~Vendor() {} //destructor

string Vendor::getUsername() const //username getter
{
    return Vendor::username;
}

string Vendor::getEmail() const //email getter
{
    return Vendor::email;
}

string Vendor::getPassword() const //password getter
{
    return Vendor::password;
}

string Vendor::getBio() const //bio getter
{
    return Vendor::bio;
}

string Vendor::getProfilePicture() const //profile picture path getter
{
    return Vendor::profilePicture;
}

void Vendor::setUsername(const string& username) //username setter
{
    Vendor::username = username;
}

void Vendor::setEmail(const string& email) //email setter
{
    Vendor::email = email;
}

void Vendor::setPassword(const string& password) //password setter
{
    Vendor::password = password;
}

void Vendor::setBio(const string& bio) //bio setter
{
    Vendor::bio = bio;
}

void Vendor::setProfilePicture(const string& profilePicture) //profile picture path setter
{
    Vendor::profilePicture = profilePicture;
}

int Vendor::getProductListSize() const //retrieve size of product list
{
    return productList.getCurrentSize();
}

void Vendor::displayProfile() const //display vendor profile
{
    cout << "Vendor: " << getUsername() << endl << "Email: " << getEmail() << endl //print vendor profile
        << "Bio: " << getBio() << endl << "Profile Picture: " << getProfilePicture() << endl;
}

bool Vendor::modifyPassword(const string& newPassword) //modify vendor password
{
    if (getPassword() != newPassword) //if different from old password
    {
        setPassword(newPassword); //call setter to set new password
        cout << "Your new password: " << getPassword() << endl; //print new password
        return 1;
    }

    return 0; //return false if same as old password
}

bool Vendor::createProduct(Product* product) //create new product
{
    if (product == nullptr) 
        return 0;

    productList.add(product); //add product into product list

    return 1;
}

void Vendor::displayProductK(const int& k) const //display kth product
{
    productList.findKthItem(k)->getItem()->display(); //call display function of product
}

void Vendor::displayAllProducts() const //display all products from product list
{
    vector<Product*> products = productList.toVector(); //transfer product list to vector

    if (products.empty()) //if the list is empty
    {
        cout << "No products available." << endl;
    }
    else //if there is product in the list
    {
        for (int i = 0; i < products.size(); i++) //loop for all products
        {
            cout << "Product " << (i + 1) << ":" << endl; //print position of product
            products[i]->display(); //call display function of product
            cout << endl;
        }
    }
}

bool Vendor::modifyProduct(const int& k, const string& name, const string& description) //modify product info
{
    return productList.findKthItem(k)->getItem()->modify(name, description); //call modify function of product
}

bool Vendor::sellProduct(const int& k, const int& quantity) //sell product
{
    return productList.findKthItem(k)->getItem()->sell(quantity); //call sell function of product
}

bool Vendor::deleteProduct(const int& k) //delete product
{
    return productList.remove(productList.findKthItem(k)->getItem()); //call remove function from linked bag
}

bool Vendor::appendK(Product* product, const int& k) //append product to kth position in product list
{
    if (product == nullptr)
        return 0;

    productList.appendK(product, k); //call appendk function from linked bag

    return 1;
}

bool Vendor::operator==(const Vendor& otherVendor) const //operator to compare vendors
{
    return (Vendor::username == otherVendor.username) && (Vendor::email == otherVendor.email);
}
