#ifndef GOOD_H
#define GOOD_H

#include <string>
#include "Product.h"

class Good : public Product
{
    private:
        std::string expirationDate; //store expiration date
        int quantity; //store quantity

    public:
        Good(); //default constructor
        Good(const std::string& name, const std::string& description, //constructor with param
            const std::string& expirationDate, const int& quantity);
        virtual ~Good(); //destructor

        std::string getExpirationDate() const; //getters and setters
        int getQuantity() const;
        void setExpirationDate(const std::string& date);
        void setQuantity(const int& quantity);

        /** display info of good **/
        void display() const;
        /** sell the good
        * @param quantity - quantity being sold
        * @return true if sell success, or false otherwise
        **/
        bool sell(const int& quantity);
};

#endif //GOOD_H
