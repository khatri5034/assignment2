#include <iostream>
#include <string>
#include "Good.h"

using namespace std;

Good::Good() {} //default constructor

Good::Good(const string& name, const string& description,  //constructor with param
    const string& expirationDate, const int& quantity)
    : Product(name, description), expirationDate(expirationDate), quantity(quantity) {}

Good::~Good() {} //destructor

string Good::getExpirationDate() const //expiration date getter
{
    return Good::expirationDate;
}

int Good::getQuantity() const //quantity getter
{
    return Good::quantity;
}

void Good::setExpirationDate(const string& date) //expiration date setter
{
    Good::expirationDate = date;
}

void Good::setQuantity(const int& quantity) //quantity setter
{
    Good::quantity = quantity;
}

void Good::display() const //display good info
{
    cout << "Name: " << getName() << endl //print good info
        << "Description: " << getDescription() << endl
        << "Rating: " << getRating() << endl
        << "Sold Count: " << getSoldCount() << endl
        << "Expiration date: " << getExpirationDate() << endl
        << "Quantity: " << getQuantity() << endl;
}

bool Good::sell(const int& quantity) //sell good
{
    int currAmount = getQuantity(); //retrieve stock quantity

    if (quantity >= 1 && quantity <= currAmount) //if available to sell
    {
        setQuantity(currAmount - quantity); //reduce stock quantity
        sold(quantity); //increase sell count
        return 1;
    }

    return 0; //if unavailable to sell
}
