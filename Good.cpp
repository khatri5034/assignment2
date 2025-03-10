#include <iostream>
#include <string>
#include "Good.h"

using namespace std;

Good::Good() {}

Good::Good(const string& name, const string& description, 
    const string& expirationDate, const int& quantity)
    : Product(name, description), expirationDate(expirationDate), quantity(quantity) {}

Good::~Good() {}

string Good::getExpirationDate() const
{
    return Good::expirationDate;
}

int Good::getQuantity() const
{
    return Good::quantity;
}

void Good::setExpirationDate(const string& date)
{
    Good::expirationDate = date;
}

void Good::setQuantity(const int& quantity)
{
    Good::quantity = quantity;
}

void Good::display() const
{
    cout << "Name: " << getName() << endl
        << "Description: " << getDescription() << endl
        << "Rating: " << getRating() << endl
        << "Sold Count: " << getSoldCount() << endl
        << "Expiration date: " << getExpirationDate() << endl
        << "Quantity: " << getQuantity() << endl;
}

bool Good::sell(const int& quantity)
{
    int currAmount = getQuantity();

    if (quantity >= 1 && quantity <= currAmount)
    {
        setQuantity(currAmount - quantity);
        sold();
        return 1;
    }

    return 0;
}
