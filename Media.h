//
// Created by kiran khatri on 3/1/25.
#ifndef MEDIA_H
#define MEDIA_H
#include"string"
#include"vector"
#include"Product.h"

class Media:public Product {

  private:
    std::string type;
    std::string targetAudience;
    public:
      Media();
      ~Media() ;
     Media(std::string name, std::string description, int rating, int soldCount, std::string type, std::string targetAudience);
     void display() ;
     std::string getType();
     std::string getTargetAudience();
     bool sell(int quantity) ;
     bool modify();
    bool operator==(const Media& otherMedia) const;

};
#endif //MEDIA_H
