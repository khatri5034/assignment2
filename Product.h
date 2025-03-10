#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <string>

class Product
{
    protected:
        std::string name;
        std::string description;
        int rating = 0;
        int soldCount = 0;

    public:
        Product();
        Product(const std::string& name, const std::string& description);
        virtual ~Product();

        std::string getName() const;
        std::string getDescription() const;
        int getRating() const;
        int getSoldCount() const;
        void setName(const std::string& name);
        void setDescription(const std::string& description);
        void setRating(const int& rating);
        void setSoldCount(const int& soldCount);

        void sold();

        virtual void display() const = 0;
        bool modify(const std::string& name, const std::string& description);
        virtual bool sell(const int& quantity) = 0;

        bool operator==(const Product& otherProduct) const;
};

#endif
