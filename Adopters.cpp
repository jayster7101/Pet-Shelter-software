#include "Adopters.h"
/**
 * @brief  Default construct a new Adopter:: Adopter object
 * sets the initial state of the variables to 
 *  adopt = false;
 *  phone_number = "No_Number";
 *  name_of_adopter = "none";
 * @param NONE 
 * @return NONE
 */
Adopter::Adopter()
{
    adopt = false;
    phone_number = "No_Number";
    name_of_adopter = "none";
};

/**
 * @brief Overloaded Construter that constructs a new Adopter:: Adopter object
 * sets inital state of variables to parameter values
 * @param _dec bool
 * @param _name string
 * @param _number string
 * @return NONE
 */
Adopter::Adopter(bool _dec, std::string _name, std::string _number)
{
    adopt = _dec;
    phone_number = _number;
    name_of_adopter = _name;
};


/**
 * @brief set the phone_number variable to parameter value
 * @param _number 
 * @return NONE
 */
void Adopter::set_phone_number(std::string _number)
{
    phone_number = _number;
};

/**
 * @brief returns the phone_number variable 
 * @param NONE 
 * @return phone_number
 */
std::string Adopter::get_phone_number() const
{
    return phone_number;
};

/**
 * @brief set the name_of_adopter variable to parameter value
 * @param _name 
 * @return NONE
 */
void Adopter::set_name_of_adopter(std::string _name)
{
    name_of_adopter = _name;
};

/**
 * @brief returns the name_of_adopter variable 
 * @param NONE 
 * @return name_of_adopter
 */
std::string Adopter::get_name_of_adopter() const
{
    return name_of_adopter;
};


/**
 * @brief set the adopt variable to parameter value
 * @param _dec  
 * @return NONE
 */
void Adopter::set_adopt(bool _dec)
{
    adopt = _dec;
};

/**
 * @brief returns the adopt variable 
 * @param NONE  
 * @return adopt
 */
bool Adopter::get_adopt()
{
    return adopt;
};

/**
 * @brief set the pets_id variable to parameter value
 * @param _id  
 * @return NONE
 */
void Adopter::set_pets_id(int _id)
{
    pets_id = _id;
};

/**
 * @brief returns the pets_id variable 
 * @param NONE  
 * @return pets_id
 */
int Adopter::get_pets_id() const
{
    return pets_id;
};