#include <iostream>
#include <string>
#include "Vendor.h"
#include "Product.h"
#include "Good.h"
#include "Media.h"

using namespace std;

Vendor::Vendor() {}

Vendor::Vendor(const string& username, const string& email, const string& password, const string& bio, const string& profilePicture)
    : username(username), email(email), password(password), bio(bio), profilePicture(profilePicture) {}

Vendor::~Vendor() {}

string Vendor::getUsername() const
{
    return Vendor::username;
}

string Vendor::getEmail() const
{
    return Vendor::email;
}

string Vendor::getPassword() const
{
    return Vendor::password;
}

string Vendor::getBio() const
{
    return Vendor::bio;
}

string Vendor::getProfilePicture() const
{
    return Vendor::profilePicture;
}

void Vendor::setUsername(const string& username)
{
    Vendor::username = username;
}

void Vendor::setEmail(const string& email)
{
    Vendor::email = email;
}

void Vendor::setPassword(const string& password)
{
    Vendor::password = password;
}

void Vendor::setBio(const string& bio)
{
    Vendor::bio = bio;
}

void Vendor::setProfilePicture(const string& profilePicture)
{
    Vendor::profilePicture = profilePicture;
}

int Vendor::getProductListSize() const
{
    return productList.getCurrentSize();
}

void Vendor::displayProfile() const
{
    cout << "Vendor: " << getUsername() << endl << "Email: " << getEmail() << endl
        << "Bio: " << getBio() << endl << "Profile Picture: " << getProfilePicture() << endl;
}

bool Vendor::modifyPassword(const string& newPassword)
{
    if (getPassword() != newPassword)
    {
        setPassword(newPassword);
        cout << "Your new password: " << getPassword() << endl;
        return 1;
    }

    return 0;
}

bool Vendor::createProduct(Product* product)
{
    if (product == nullptr) 
        return 0;

    productList.add(product);
    return 1;
}

void Vendor::displayProductK(const int& k) const
{
    productList.findKthItem(k)->getItem()->display();
}

void Vendor::displayAllProducts() const
{
    vector<Product*> products = productList.toVector();

    if (products.empty())
    {
        cout << "No products available." << endl;
    }
    else
    {
        for (int i = 0; i < products.size(); i++)
        {
            cout << "Product " << (i + 1) << ":" << endl;
            products[i]->display();
            cout << endl;
        }
    }
}

bool Vendor::modifyProduct(const int& k, const string& name, const string& description)
{
    return productList.findKthItem(k)->getItem()->modify(name, description);
}

bool Vendor::sellProduct(const int& k, const int& quantity)
{
    return productList.findKthItem(k)->getItem()->sell(quantity);
}

bool Vendor::deleteProduct(const int& k)
{
    return productList.remove(productList.findKthItem(k)->getItem());
}

bool Vendor::operator==(const Vendor& otherVendor) const
{
    return (Vendor::username == otherVendor.username) && (Vendor::email == otherVendor.email);
}
