#include "Pet.h"
#include "Dog.h"
/**
 * @brief is a member function of the pet class 
 * creates a random number of length 5 using the current time as the seed and then assigns numbers 0-9
 * turns each charater to a string and concatonates it to the iSecret var and then when the for loop ends it turns the string to an int using thr stoi() method
 * @param parameter-NONE
 * @return int with length 5
 */
int Pet::create_id()
    {
        std::string name;
        srand(time(NULL));
        for(int i = 0; i < 5; i++)
        {
            int iSecret = rand() % 9;
            std::string s = std::to_string(iSecret);    
            name+=s;
        }
        int returning = std::stoi(name);
        return returning;
    }


/**
 * @brief is a member function of the pet class that gets the name of the pet
 * @param NONE
 * @return string of the name of the pet
 */
    std::string Pet:: get_name() const
    {
        return name;
    } 
/**
 * @brief is a member function of the pet class that sets the name of the pet
 * first it checks if the name is able to be set, will only work if its never been assigned 
 * tells user if the name cant be changed 
 * @param  NONE
 * @return NONE
 */
    void Pet:: set_name()
    {
        std::string _name;
        std::cout << "What is the animals name\n> ";
        std::cin >> _name;
        std::string temp = get_name();
        if(temp == "")
        {
            name = _name;
        }
        else 
        {
            std::cout << "Sorry you can not change the name of animal once it has been set";
        }

    }

/**
 * @brief is a member function of the pet class that gets the ID of the pet
 * @param NONE
 * @return int of the pets ID#
 */
    int Pet::get_id() const
    {
        return id;
    }

/**
 * @brief is a member function of the pet class that gets the days the pet has been in the shelter
 * @param NONE
 * @return int of the number of days 
 */
    int Pet:: get_days() const
    {
        return days;
    }

/**
 * @brief is a member function of the pet class that gets the weight of the pet
 * @param NONE
 * @return double of the weight of the animal
 */
    double Pet:: get_weight() const
    {
        return weight;
    };

/**
 * @brief is a member function of the pet class that sets the weight of the pet
 * @param  double _temp 
 * @return NONE
 */

    void Pet:: set_weight(double _temp)
    {
        weight = _temp;
    };

/**
 * @brief ***CONSTRUCTOR*** is a member function of the pet class
 *  sets the name of the pet to an empty string
 * sets the ID# of the pet/animal
 * @param  NONE
 * @return NONE
 */
    Pet::Pet() // default Pet constructor when a named is NOT passed in
    {
        name = "";
        id = create_id();
    }
   
/**
 * @brief ***CONSTRUCTOR*** is a member function of the pet class
 * sets the name of the pet to the string that is passed in
 * sets the days the animal has been in the shelter for 
 * sets the ID# of the pet/animal
 * @param  string _name, int _id, int _days
 * @return NONE
 */
    Pet::Pet(std::string _name, int _id, int _days) // Pet constructor when a named is passed in
    {
        name = _name;
        id = _id;
        days = _days++;
    }

/**
 * @brief sets the age on Pet class (age) variable 
 * member function of Pet class 
 * @param _age double
 * @return none
 */
void Pet::set_age(double _age)
{
    age = _age;
}

/**
 * @brief gets the age from data member (age) on Pet class
 * @param parameter none
 * @return double 
 */
double Pet::get_age() const 
{
    return age;
}

/**
 * @brief (virtual) gets the breed from data member Dog 
 * supplies error message because Pet should never call this function
 * @param parameter none
 * @return string 
 */
 std::string Pet::get_breed() const
 {
     return "Wrong data, this is Pet should be Dog(breed)";
 }

/**
 * @brief (virtual) gets the fav_toy from data member on Dog Class
 * supplies error message because Pet should never call this function
 * @param parameter none
 * @return string 
 */
std::string Pet::get_fav_toy()const
{
    return "Wrong data, this is Pet should be Dog (favtoy)";
};

/**
 * @brief (virtual) gets the color from data member on Bird class 
 * supplies error message because Pet should never call this function
 * @param parameter none
 * @return string 
 */
std::string Pet::get_color()const
{
    return "Wrong data, this is Pet should be Bird (color)";

};

/**
 * @brief (virtual) gets the speak boolean from data member on Bird class 
 * supplies error message because Pet should never call this function
 * @param parameter none
 * @return bool 
 */
bool Pet::get_can_speak()const
{
    std::cout << "Wrong data, this is Pet should be Bird (speak)\n";
    return false;
};

/**
 * @brief (virtual) gets the type from data member on Pet
 * @param parameter none
 * @return string 
 */
 std::string Pet::get_type()const
 {
     return "PET";
 };

/**
 * @brief (virtual) gets the current_grooming data member from Pet class but should be called from derived class
 * returns -1 because Pet should never call this function
 * @param parameter none
 * @return int 
 */
 int Pet::get_current_grooming() const
{
    return -1;
};
/**
 * @brief (virtual) gets the current_checkups data member from Pet class but should be called from derived class
 * returns -1 because Pet should never call this function
 * @param parameter none
 * @return int 
 */
int Pet::get_current_checkups() const
{
    return -1;
};

/**
 * @brief (virtual) performs a checkup and resets the variable current_checkup variable back to zero on derived classes 
 * supplies error message because Pet should never call this function
 * @param parameter none
 * @return string 
 */
void Pet::perform_checkup()
{
    std::cout << "Wrong, this is pet... perfrom_checkup";
};

/**
 * @brief (virtual) performs thr grooming and resets the variable current_grooming variable back to zero on derived classes 
 * @param parameter none
 * @return string 
 */
 void Pet::perform_grooming()
 {
     std::cout << "Wrong, this is pet...perform_grooming";
 };
