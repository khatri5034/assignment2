//
// Created by kiran khatri on 3/1/25.
//

#ifndef GOOD_H
#define GOOD_H

#include"string"
#include"vector"
#include"Product.h"
class Good:public Product {

private:
    std::string expirationDate;
    int quantity;
public:
    Good();
    ~Good() ;
    Good(std::string name, std::string description, int rating, int addCount, std::string expirationDate,int quantity);
    void display() ;
    std::string getExpirationDate();
    int getQuantity();
    bool sell(int quantity);
    bool modify() ;
    bool operator==(const Good& otherMedia) const;

};


#endif //GOOD_H
