//
// Created by kiran khatri on 3/1/25.

#include"String"
#include"vector"
#include"Product.h"
#ifndef MEDIA_H
#define MEDIA_H
class Media:public Product {

  private:
    string type;
    string targetAudience
    public:
      Media();
      ~Media();
     Media(std::string name, std::string description, int rating, int addCount, string type, string targetAudience);
    bool operator==(const Media& otherMedia) const;

};
#endif //MEDIA_H
