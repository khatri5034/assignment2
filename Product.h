// TO DO: #include all the standard libraries and your own libraries here
#include <iostream>
#include <string>
#include"Vendor.h"

#include <vector>
#ifndef PRODUCT_H_
    #define PRODUCT_H_
//
// To DO: define the class Product with the necessary functions' prototypes and data fields
class Product{
  protected:
    std::string name;
    std:: string description;
    int rating;
    int soldCount;
    public:
      Product ();

      Product(std::string name, std::string description, int rating, int soldCount);
      virtual ~Product ();
      std::string getName();
      std::string getDescription();
      int getRating();
      int getSoldCount();
      virtual void display()=0;
      virtual bool modify()=0;
    virtual bool sell(int index)=0;
      bool operator==(const Product& otherProduct) const;

};
#endif
// This is a function that allows you to compare two products based on their name. 
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator overloading function prototype:

