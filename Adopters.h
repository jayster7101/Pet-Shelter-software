#include <iostream>
#ifndef ADOPTERS_H
#define ADOPTERS_H
class Adopter
{
    public:
    Adopter(); // Default constructor
    Adopter(bool,std::string,std::string); // overloaded constructor sets the adopt,phone_number,name_of_adopter variables to paramter values
    void set_phone_number(std::string); // sets the phone_number to the paramter value of type string
    std::string get_phone_number() const; // returns the phone variable as a string
    void set_name_of_adopter(std::string); // sets the name_of_adopter variable to the paramter value of type string
    std::string get_name_of_adopter() const; // returns the name_of_adopter variable as a string
    void set_adopt(bool); // sets adopt variable to parmater of type bool
    bool get_adopt(); // returns the adopt variable as a boolean

    void set_pets_id(int); // sets the pets id to whats passed in as a parameter type int
    int get_pets_id() const; // returns the pets_id as type int

    private:
    bool adopt;
    std::string phone_number;
    int pets_id;
    std::string name_of_adopter;

};
#endif