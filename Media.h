//
// Created by kiran khatri on 3/1/25.

#include"string"
#include"vector"
#include"Product.h"
#ifndef MEDIA_H
#define MEDIA_H
class Media:public Product {

  private:
    std::string type;
    std::string targetAudience;
    public:
      Media();
      ~Media();
     Media(std::string name, std::string description, int rating, int addCount, std::string type, std::string targetAudience);
     void display();
     std::string getType();
     std::string getTargetAudience();
     bool sell(int quantity);
     bool modify();
    bool operator==(const Media& otherMedia) const;

};
#endif //MEDIA_H
