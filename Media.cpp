#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Media.h"

using namespace std;

Media::Media() {} //default constructor

Media::Media(const string& name, const string& description, 
    const string& type, const string& targetAudience)
    : Product(name, description), type(type), targetAudience(targetAudience) {}

Media::~Media() {} //destructor

string Media::getType() const //type getter
{
    return Media::type;
}

string Media::getTargetAudience() const //target audience getter
{
    return Media::targetAudience;
}

void Media::setType(const std::string& type) //type setter
{
    Media::type = type;
}

void Media::setTargetAudience(const std::string& targetAudience) //target audience setter
{
    Media::targetAudience = targetAudience;
}

void Media::display() const //display media info
{
    cout << "Name: " << getName() << endl //print media info
        << "Description: " << getDescription() << endl
        << "Rating: " << getRating() << endl
        << "Sold Count: " << getSoldCount() << endl
        << "Type: " << getType() << endl
        << "Target Audience: " << getTargetAudience() << endl;
}

bool Media::sell(const int& quantity) //sell media
{
    srand(time(0)); //random seed

    cout << "Media sold successfully!" << endl
        << "One-time access code: " << 100000 + rand() % 900000 << endl; //output random one-time access code

    sold(); //increase sell count

    return 1;
}
