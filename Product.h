// TO DO: #include all the standard libraries and your own libraries here
#include <iostream>
#include <string>
#include <vector>
// To DO: define the class Product with the necessary functions' prototypes and data fields
class Product{
  private:
    std::string name;
    std:: string description;
    int rating;
    int addCount;
    public:
      Product ();

      Product(std::string name, std::string description, int rating, int addCount);
      ~Product ();
      std::string getName();
      std::string getDescription();
      int getRating();
      int getAddCount();
      void display();
      bool modify();
      bool sell(int quantity);
      bool operator==(const Product& otherProduct) const;

};
// This is a function that allows you to compare two products based on their name. 
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator overloading function prototype:

