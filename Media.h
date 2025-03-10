#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <vector>
#include "Product.h"

class Media : public Product
{
    private:
        std::string type;
        std::string targetAudience;

    public:
        Media();
        Media(const std::string& name, const std::string& description,  
            const std::string& type, const std::string& targetAudience);
        virtual ~Media();


        std::string getType() const;
        std::string getTargetAudience() const;
        void setType(const std::string& type);
        void setTargetAudience(const std::string& targetAudience);

        void display() const;
        bool sell(const int& quantity);
};

#endif //MEDIA_H
