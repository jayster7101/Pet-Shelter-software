#include "Pet.h"
#ifndef DOG_H
#define DOG_H
class Dog : public Pet
{
    public:
    const std::string type = "Dog";
    Dog(); // creates an instance of a Dog, with empty string and an ID# and days at 0
    Dog(std::string, int, int);
    void set_breed(std::string); //sets the breed variable to whats passed in as a parameter type string
    void set_fav_toy(std::string); //sets the fav_toy variable to whats passed in as a parameter type string
    virtual std::string get_breed()const; // returns the breed variable from the Dog class type string 
    virtual std::string get_fav_toy()const; // returns fav_toy variable from the Dog class type string 
    virtual std::string get_type()const; // returns type variable from the Dog class type string 
    
    
    // grooming & checkup interval
    virtual int get_current_grooming() const;// returns the int current_grooming variable
    virtual int get_current_checkups() const;// returns the int current_checkup variable
    void set_current_checkup(int current);// sets the current_checkup to whats passed in as a parameter type int
    void set_current_grooming(int current);// sets the current_grooming to whats passed in as a parameter type int

    // perform checup&grooming & update days
    virtual void perform_checkup();// perfroms checkup and resets current_checkup when neccesary 
    virtual void perform_grooming();// perfroms grooming and resets current_grooming when neccesary 
     
    private:
    std::string breed;
    std::string fav_toy;

    int grooming = 3;
    int checkups = 7;
    int current_checkups = 0;
    int current_grooming = 0;
};
#endif