//
// Created by kiran khatri on 3/1/25.
//
#include"iostream"
#include"string"
#include"Media.h"
Media::Media(std::string name, std::string description, int rating, int addCount,std::string type, std::string targetAudience):Product(name,description,rating,addCount),type(type),targetAudience(targetAudience){
  }
  Media::~Media(){};
  std::string Media::getType(){
    return Media::type;
  }
  std::string Media::getTargetAudience(){
    return Media::targetAudience;
  }

void Media::display(){
  std::cout << "Name: " << getName() << std::endl;
    std::cout << "Description: " << getDescription() << std::endl;
    std::cout << "Rating: " << getRating() << std::endl;
    std::cout << "Stock: " << getAddCount() << std::endl;
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Target Audience: " << getTargetAudience() << std::endl;
  }
  bool Media::sell(int quantity){
    if (addCount == 0) {
        std::cout << "Out of stock!" << std::endl;
        return false;
    }
    if (addCount >= quantity) {
        addCount -= quantity;
        std::cout << quantity << " item(s) sold! Remaining stock: " << addCount << std::endl;
        return true;
    } else {
        std::cout << "Not enough stock available!" << std::endl;
        return false;
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
