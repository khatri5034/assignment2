#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <vector>
#include "Product.h"

class Media : public Product //subclass of product
{
    private:
        std::string type; //store media type
        std::string targetAudience; //store target audience

    public:
        Media(); //default constructor
        Media(const std::string& name, const std::string& description,  //constructor with param
            const std::string& type, const std::string& targetAudience);
        virtual ~Media(); //destructor


        std::string getType() const; //getters and setters
        std::string getTargetAudience() const;
        void setType(const std::string& type);
        void setTargetAudience(const std::string& targetAudience);

        /** display info of media **/
        void display() const;
        /** sell the good
        * @param quantity - quantity being sold
        * @return true if sell success, or false otherwise
        **/
        bool sell(const int& quantity);
};

#endif //MEDIA_H
