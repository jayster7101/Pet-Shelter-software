#include "Pet.h"
#ifndef BIRD_H
#define BIRD_H
class Bird: public Pet
{
    public:
    const std::string type = "Bird";
    Bird(); // creates an instance of a Dog, with empty string and an ID# and days at 0
    Bird(std::string,int, int,std::string);
    void set_color(std::string); //sets the color variable to whats passed in as a parameter type string
    void set_can_speak(bool);//sets the can_speak variable to the bool thats passed in as a parameter type string
    virtual std::string get_color()const; // returns the string color variable of the bird
    virtual bool get_can_speak()const; // returns the bool value of can_speak
    virtual std::string get_type()const; // returns the string type variable 
    virtual int get_current_grooming() const; // returns the int current_grooming variable
    virtual int get_current_checkups() const;// returns the int current_checkup variable
    virtual void perform_checkup(); // perfroms checkup and resets current_checkup when neccesary 
    virtual void perform_grooming();// perfroms grooming and resets current_grooming when neccesary 
    void set_current_checkup(int); // sets the current_checkup to whats passed in as a parameter type int
    void set_current_grooming(int);// sets the current_grooming to whats passed in as a parameter type int
    private:
    //
    std::string color;
    bool can_speak;

    // For Birds grooming and check up schedules
    int grooming = 2;
    int checkups = 7;
    int current_checkups = 0;
    int current_grooming = 0;
};
#endif