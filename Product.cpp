// TO DO: #include all the standard libraries and your own libraries here
#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "LinkedBagDS/LinkedBag.h"
//

// TO DO: function implementations
Product::Product(){}

Product::Product(std::string name, std::string description, int rating, int addCount){
   Product::name = name;
   Product::description = description;
   Product::rating = rating;
   Product::addCount = addCount;

}
  Product:: ~Product(){}
// ------------------------------------------------------------------------------
// Operator overloading implementation
  std::string Product:: getName(){
    return Product::name;}
  std::string Product:: getDescription(){
    return Product::description;

  }
  int Product::getRating(){
    return Product::rating;
  }
  int Product::getAddCount(){
    return Product::addCount;
  }

bool Product::operator==(const Product& otherProduct) const {
	return Product::name == otherProduct.name;
}




