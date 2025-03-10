#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Media.h"

using namespace std;

Media::Media() {}

Media::Media(const string& name, const string& description, 
    const string& type, const string& targetAudience)
    : Product(name, description), type(type), targetAudience(targetAudience) {}

Media::~Media() {}

string Media::getType() const
{
    return Media::type;
}

string Media::getTargetAudience() const
{
    return Media::targetAudience;
}

void Media::setType(const std::string& type)
{
    Media::type = type;
}

void Media::setTargetAudience(const std::string& targetAudience)
{
    Media::targetAudience = targetAudience;
}

void Media::display() const
{
    cout << "Name: " << getName() << endl
        << "Description: " << getDescription() << endl
        << "Rating: " << getRating() << endl
        << "Sold Count: " << getSoldCount() << endl
        << "Type: " << getType() << endl
        << "Target Audience: " << getTargetAudience() << endl;
}

bool Media::sell(const int& quantity)
{
    srand(time(0));

    cout << "Media sold successfully!" << endl
        << "One-time access code: " << 100000 + rand() % 900000 << endl;

    sold();

    return 1;
}
