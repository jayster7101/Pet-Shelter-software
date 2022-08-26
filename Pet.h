#include "includes.h"
#ifndef PET_H
#define PET_H

class Pet {
    public:
    Pet(); // creates an instance of a pet, with empty string and an ID# and days at 0
    Pet(std::string,int, int); // creates an instance of a pet, assigns the name, the ID# and the days the pet has been in shelter
    std::string get_name() const; // returns the name of Pet in string format
    double get_weight() const; // returns type double of weight
    int get_id() const; // returns the ID number if that instance of the pet
    int get_days() const; // returns the amount days that the pet has been in the shelter 
    void set_name(); // changes the name if the name is set to ""
    void set_weight(double); // sets the weight of the Pet
    void set_age(double);  // sets the age of the Pet 
    double get_age() const; // returns the age of the Pet
    virtual std::string get_breed() const;// (virtual) returns the string breed variable from Dog class 
    virtual std::string get_fav_toy()const;// (virtual) returns the string fav_toy variable from Dog class
    virtual std::string get_color()const;// (virtual) returns the sting color variable from Bird class
    virtual bool get_can_speak()const;// (virtual) returns the boolean value of can_speak from Bird class
    virtual std::string get_type()const;// (virtual) returns the string type variable on all Pet classes and classes derived from Pet

    virtual int get_current_grooming() const;// (virtual) returns the int of current_grooming on derived classes
    virtual int get_current_checkups() const;// (virtual) returns the int of current_checkup on derived classes

    virtual void perform_checkup(); // (virtual) perfroms checkup when needed and resets current_checkup variable back to zero 
    virtual void perform_grooming(); // (virtual) perfroms grooming when needed and resets current_grooming variable back to zero 

    // Aggregated Class
    Adopter potential;

    
    private:
    int create_id(); // creates a random id with a length of 5 digits   (FUTURE IDEA !!!!!!****CHANGE TO A MAPPING ****!!!!! )

    double age;
    std::string name;
    double weight = 0.0;
    int id;
    int days = 0;
    
};
#endif