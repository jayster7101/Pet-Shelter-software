#include "Dog.h"
#include "helpers_main.h"

/**
 * @brief sets breed variable to whats passed in as a parmater 
 * @param _breed string 
 * @returns none
 */
void Dog::set_breed(std::string _breed)
{
    breed = _breed;
};

/**
 * @brief sets fav_toy variable to whats passed in as a parmater 
 * @param _toy string 
 * @returns none
 */
void Dog::set_fav_toy(std::string _toy)
{
    fav_toy = _toy;
};

/**
 * @brief returns breed variable 
 * @param none
 * @returns breed string
 */
std::string Dog::get_breed()const
{
    return breed;
};

/**
 * @brief Default Constructer constructs a new Dog:: Dog object
 * @param NONE
 * calls Pet base class constructer
 * @return NONE
 */
Dog::Dog() // default Dog constructor when a named is NOT passed in
:Pet()
{
}

/**
 * @brief Default Constructer constructs a new Dog:: Dog object
 * calls Pet base class overloaded constructer
 * 
 * @param name-name of dog
 * @param id-dogs id
 * @param days_in_shelter- days the dog has been in the shelter
 */
Dog::Dog(std::string name, int id, int days_in_shelter)
: Pet(name,id,days_in_shelter)
{
}

/**
 * @brief returns fav_toy variable 
 * @param none
 * @returns fav_toy string
 */
std::string Dog::get_fav_toy()const 
{
    return fav_toy;
}

/**
 * @brief returns type variable 
 * @param none
 * @returns type string
 */
std::string Dog::get_type()const
 {
     return type;
 };

 /**
 * @brief gets the current_grooming data member from Dog class
 * @param parameter none
 * @returns current_grooming int 
 */
int Dog::get_current_grooming() const
{
    return current_grooming;
};

/**
 * @brief gets the current_checkup data member from Dog class
 * @param parameter none
 * @returns current_checkup int 
 */
int Dog::get_current_checkups() const
{
    return current_checkups;
};

/**
 * @brief increments the current grooming by 1 and then checks against the int of when it should be groomed
 * if it should be groomed then it resets the current_grooming to 1 and displays which Dog has been groomed  
 * @param  none
 * @returns none
 */
void Dog::perform_grooming()
 {
     current_grooming++;
     if(current_grooming == grooming)
     {
        current_grooming = 0;
        std::cout << this->get_name() << " the " << this->get_type() << " has been groomed.\n";
     }
 };


 /**
 * @brief increments the current_checkup by 1 and then checks against the int of when it should have its checkup
 * if it should have its checkup then it resets the current_checkup to 1 and displays which Dog has had its checkup
 * @param  none
 * @returns none
 */
 void Dog::perform_checkup()
 {
     current_checkups++;
     if(current_checkups == checkups)
     {
        current_checkups = 0;
        std::cout << this->get_name() << " the " << this->get_type() << " has had its weekly checkup.\n";
     }
 };

 /**
 * @brief Sets the current_grooming to the paramter thats passed in 
 * @param current int 
 * @returns none 
 */
 void Dog::set_current_checkup(int current)
 {
    current_checkups = current;
 };


 /**
 * @brief Sets the current_checkup to the paramter thats passed in 
 * @param current int 
 * @returns none 
 */
 void Dog::set_current_grooming(int current)
 {
    current_grooming = current;
 };




