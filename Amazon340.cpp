// TO DO: Implementation of Amazon340 functions
#include <iostream>
#include <string>
#include "Amazon340.h"
#include "Vendor.h"

// TO DO: implement constructor

// TO DO: implement destructor


void Amazon340::createVendor(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture){

	vendor =Vendor(username,email,password,bio,profilePicture);

}
Amazon340::~Amazon340(){
};
Amazon340::Amazon340(){};


Vendor Amazon340::getVendor() const{
  return vendor;
	// TO DO: implement function
}