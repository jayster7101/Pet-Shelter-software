#include "Bird.h"
#include "helpers_main.h"
/**
 * @brief sets color variable to whats passed in as a parmater 
 * @param _color string 
 * @returns none
 */
void Bird::set_color(std::string _color)
{
    color = _color;
};

/**
 * @brief sets can_speak variable to whats passed in as a parmater 
 * @param _speak bool 
 * @returns none
 */
void Bird::set_can_speak(bool _speak)
{
    can_speak = _speak;

};

/**
 * @brief returns color variable
 * @param none 
 * @returns color string
 */
std::string Bird::get_color()const
{
    return color;
};

/**
 * @brief returns can_speak variable
 * @param none 
 * @returns can_speak bool
 */
bool Bird::get_can_speak()const
{
    return can_speak;
};

/**
 * @brief gets type variable
 * @param none 
 * @returns color string
 */
std::string Bird::get_type()const
 {
     return type;
 };

/**
 * @brief Construct a new Bird:
 * calls base class constructor and then initializes color to "none"
 * @param NONE 
 * @returns NONE
 */
Bird::Bird() // default Dog constructor when a named is NOT passed in
:Pet()
{
    color = "None";
};

/**
 * @brief OVERLOADED Constructer 
 * calls base class overloaded constructor and also sets color variable to paramter value
 * 
 * @param name string
 * @param id int 
 * @param days_in_shelter int
 * @param _color string
 * @returns  NONE
 */
Bird::Bird(std::string name, int id, int days_in_shelter,std::string _color)
: Pet(name,id,days_in_shelter)
{
    if(_color == "") color = "none";
    else color = _color;
};

/**
 * @brief gets the current_grooming data member from Bird class
 * @param parameter none
 * @returns current_grooming int 
 */
int Bird::get_current_grooming() const
{
    return current_grooming;
};

/**
 * @brief gets the current_checkup data member from Bird class
 * @param parameter none
 * @returns current_checkup int 
 */
int Bird::get_current_checkups() const
{
    return current_checkups;
};


/**
 * @brief increments the current grooming by 1 and then checks against the int of when it should be groomed
 * if it should be groomed then it resets the current_grooming to 1 and displays which bird has been groomed  
 * @param  none
 * @returns none
 */
 void Bird::perform_grooming()
 {
     current_grooming++;
     if(current_grooming == grooming)
     {
        current_grooming = 1;
        std::cout << this->get_name() << " the " << this->get_type() << " has been groomed.\n";
     }
 };
 /**
 * @brief increments the current_checkup by 1 and then checks against the int of when it should have its checkup
 * if it should have its checkup then it resets the current_checkup to 1 and displays which bird has had its checkup
 * @param  none
 * @returns none
 */
 void Bird::perform_checkup()
 {
     current_checkups++;
     if(current_checkups == checkups)
     {
        current_checkups = 1;
        std::cout << this->get_name() << " the " << this->get_type() << " has had its weekly checkup.\n";
     } 
 };



/**
 * @brief Sets the current_checkup to the paramter thats passed in 
 * @param current int 
 * @returns none 
 */
 void Bird::set_current_checkup(int current)
 {
    current_checkups = current;
 };

 /**
 * @brief Sets the current_grooming to the paramter thats passed in 
 * @param current int 
 * @returns none 
 */
 void Bird::set_current_grooming(int current)
 {
    current_grooming = current;
 };