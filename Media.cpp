//
// Created by kiran khatri on 3/1/25.
//
#include <algorithm> // For random_shuffle
#include <random>    // For random_device, uniform_int_distribution and mt19937
#include"iostream"
#include"string"
#include"Media.h"
Media::Media(std::string name, std::string description, int rating, int soldCount,std::string type, std::string targetAudience):Product(name,description,rating,soldCount=0),type(type),targetAudience(targetAudience){
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
    std::cout << "Stock: " << getSoldCount() << std::endl;
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Target Audience: " << getTargetAudience() << std::endl;
  }
  bool Media::sell(int index){

    if (index < 1) {
        std::cout << "Invalid product index. Please enter a valid number." << std::endl;
        return false;
    }


    std::random_device rd;   // Non-deterministic random number generator
    std::mt19937 gen(rd());  // Seed the generator
    std::uniform_int_distribution<> dis(100000, 999999);  // 6-digit code range

    int accessCode = dis(gen);


    std::cout << "Media sold successfully!" << std::endl;
    std::cout << "One-time access code: " << accessCode << std::endl;


    this->soldCount++;

    return true;
 }
 bool Media::modify(){
   std::cout << "Please, enter the new description: ";
        std::getline(std::cin, description);

        std::cout << "Please, enter the new rating: ";
        std::cin >> rating;
        return true;
 }
