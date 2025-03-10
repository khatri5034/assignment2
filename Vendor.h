#ifndef VENDOR_H
#define VENDOR_H

#include <string>
#include "LinkedBagDS/LinkedBag.h"
#include "Product.h"
#include "Good.h"
#include "Media.h"

class Vendor
{
    private:
        std::string username;
        std::string email;
        std::string password;
        std::string bio;
        std::string profilePicture;
        LinkedBag<Product*> productList;

    public:
        Vendor();
        Vendor(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture);
        virtual ~Vendor();

        std::string getUsername() const;
        std::string getEmail() const;
        std::string getPassword() const;
        std::string getBio() const;
        std::string getProfilePicture() const;
        void setUsername(const std::string& username);
        void setEmail(const std::string& email);
        void setPassword(const std::string& password);
        void setBio(const std::string& bio);
        void setProfilePicture(const std::string& profilePicture);

        int getProductListSize() const;

        void displayProfile() const;
        bool modifyPassword(const std::string& newPassword);
        bool appendK(Product* product, const int& k);
        bool createProduct(Product* product);
        void displayProductK(const int& k) const;
        void displayAllProducts() const;
        bool modifyProduct(const int& k, const std::string& name, const std::string& description);
        bool sellProduct(const int& k, const int& quantity);
        bool deleteProduct(const int& k);

        bool operator==(const Vendor& otherVendor) const;
};

#endif
