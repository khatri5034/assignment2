#ifndef GOOD_H
#define GOOD_H

#include <string>
#include "Product.h"

class Good : public Product
{
    private:
        std::string expirationDate;
        int quantity;

    public:
        Good();
        Good(const std::string& name, const std::string& description, 
            const std::string& expirationDate, const int& quantity);
        virtual ~Good();

        std::string getExpirationDate() const;
        int getQuantity() const;
        void setExpirationDate(const std::string& date);
        void setQuantity(const int& quantity);

        void display() const;
        bool sell(const int& quantity);
};

#endif //GOOD_H
