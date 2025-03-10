#include <iostream>
#include <string>
#include "Product.h"

using namespace std;

Product::Product() {}

Product::Product(const string& name, const string& description)
    : name(name), description(description) {}

Product::~Product() {}

string Product::getName() const
{
    return Product::name;
}

string Product::getDescription() const
{
    return Product::description;
}

int Product::getRating() const
{
    return Product::rating;
}

int Product::getSoldCount() const
{
    return Product::soldCount;
}

void Product::setName(const string& name)
{
    Product::name = name;
}

void Product::setDescription(const string& description)
{
    Product::description = description;
}

void Product::setRating(const int& rating)
{
    Product::rating = rating;
}

void Product::setSoldCount(const int& soldCount)
{
    Product::soldCount = soldCount;
}

void Product::sold()
{
    Product::soldCount++;
}

bool Product::modify(const string& name, const string& description)
{
    setName(name);
    setDescription(description);

    return 1;
}

bool Product::operator==(const Product& otherProduct) const
{
	return Product::name == otherProduct.name;
}
