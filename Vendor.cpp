// TO DO: #include needed standard libraries and your own libraries here
#include "Vendor.h"
//
// TO DO: function implementations

// Operator == overloading implementation
Vendor ::Vendor(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture){
    Vendor::username = username;
    Vendor::email = email;
    Vendor::password = password;
    Vendor::bio = bio;
    Vendor::profilePicture = profilePicture;

}
bool Vendor ::operator==(const Vendor& otherVendor) const {
	return (Vendor::username == otherVendor.username) && (Vendor::email == otherVendor.email);
};
