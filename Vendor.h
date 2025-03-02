// TO DO: #include all the standard libraries and your own libraries here
#include <iostream>
#include <string>

// To DO: define the class Vendor with the necessary functions and data fields
class Vendor{
  private:
    std::string username;
    std::string email;
    std::string password;
    std::string bio;
    std::string profilePicture;

  public:
    Vendor(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture);
    std::string getName();
    std::string getEmail();
    std::string getPassword();
    std::string getBio();
    std::string getProfilePicture();
    bool operator==(const Vendor& otherVendor) const;
};
// This is a function that allows you to compare two vendors based on their username and email address.  
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator == overloading function prototype:

