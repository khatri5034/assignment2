//
// Created by kiran khatri on 3/1/25.
//
//
// Created by kiran khatri on 3/1/25.
//
#include"iostream"
#include"string"
#include"Good.h"
#include<regex>
Good::Good(std::string name, std::string description, int rating, int soldCount,std::string expirationDate, int quantity):Product(name,description,rating,soldCount=0),expirationDate(expirationDate),quantity(quantity){
}
Good::~Good(){};
std::string Good::getExpirationDate(){
    return Good::expirationDate;
}
int Good::getQuantity(){
    return Good::quantity;
}

void Good::display(){
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Description: " << getDescription() << std::endl;
    std::cout << "Rating: " << getRating() << std::endl;
    std::cout << "Stock: " << getSoldCount() << std::endl;
    std::cout << "expiration date: " << getExpirationDate() << std::endl;
    std::cout << "quantity: " << getQuantity() << std::endl;
}
bool Good::sell(int index){
    if (index < 1) {
        std::cout << "Invalid product index. Please enter a valid number." << std::endl;
        return false;
    }
    else{
          if(Good::quantity == 0) {
            std::cout << "Out of stock!" << std::endl;
            return false;
          }
          else  {
            soldCount++;
            quantity -= soldCount;
            std::cout << soldCount << " item(s) sold! Remaining stock: " << quantity << std::endl;
            return true;
          }
    }
    return false;
}
bool Media::modify(){
    std::cout << "Please, enter the new description: ";
    std::getline(std::cin, description);

    std::cout << "Please, enter the new rating: ";
    std::cin >> rating;
    return true;
}

