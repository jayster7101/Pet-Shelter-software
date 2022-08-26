/*
From: Jayden Jardine
Date: 02/18/2022
Description: This a simple business-oriented software for a small animal shelter. 
The shelter will be able to hold up to ten animals and store their name, type of animal, identification number, amount of days they have been in the shelter, and weight. 
you can read and write to a file which acts as saving the data anf updating inventroy 
as well find which animal has been in the shelter the longest
*/
// #include "helpers_main.h"
// #include "Pet.h"
// #include "Adopters.h"
// #include <vector>
#include "includes.h"

int main()
{   
    int amount;
    Pet *pets[20];
    std::vector<Adopter> adopter_array;
    greet();
    bool _enter = enter();
    if(_enter)
    {
        bool path = filepath();
        if(path)
        {
            read_write(pets,adopter_array,amount);
        }
        bool add = add_pet(pets,adopter_array, amount);
        end_of_day_routine(pets, amount);
        if(add) write_array(pets,adopter_array, amount);
        write_to_file_vector (adopter_array);
        find(pets, amount);
    }
    else no_enter();
}

