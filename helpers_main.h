//#include "includes.h"
#include "Pet.h"
#include "Dog.h"
#include "Bird.h"
#include "Adopters.h"
#ifndef HELPERS_MAIN_H
#define HELPERS_MAIN_H
const int MAX = 20;
const std::string list[] = {"Bird","Dog"};
 
 
// *****NON MEMBER FUNCTIONS*****
 
std::string get_file(); // gets and returns file as a string
void greet();// simple greeting
bool enter(); // takes users input for yes and no questions and returns a bool
bool filepath();// asks if the user has a file and calls enter()
void read_write(Pet **pets,std::vector<Adopter>&,int&); // creates an input file stream and calls parse_reader to parse data into an array
void parse_reader(std::string,Pet **pets, int count,std::vector<Adopter>&); // parses data into the array
void print_array(Pet **pets); // prints the array of whats available
bool add_pet(Pet **pets,std::vector<Adopter>&,int&); // adds an instance of a pet to the pets array at the next relevent position
//void write_array(Pet **pets, std::vector <Adopter> &); //opens an outstream to write to, asks for file name or if a file was used to read in then it asks to use that one
void write_array(Pet **pets, std::vector <Adopter> &,int&);
void helpful_info();// writes helpful information to the console
int find_a_home(Pet **pets,int&); // finds the animal that has been in the shelter the longest
void find(Pet **pets, int &);// asks if the user wants to find the animal that has been in the shelter the longest and then calls find_a_home
void no_enter(); // default information when the user deices to not enter the program
void printBox(); // simple print function   outputs this -> "-----------------------------------------------------\n";
std::string get_number(std::string); // gets a 10 character for a phone number but doesn't check if all characters are of type int
std::string get_output_file(); // gets the file name to write to 
 
 
 
 
//Vector functions for reading in
std::string get_file_vector(); // gets the file name so that read_write vector can be used
void read_write_vector (std::vector<Adopter> ); // read in data from file and calls push_to_vector
void push_to_vector(std::string,std::vector<Adopter>&); // writes data from .txt file to a vector of type <Adopter>
void write_to_file_vector (std::vector<Adopter>); // writes data from a vector to a .txt file
 
 
//void swap_and_pop(Pet **pets);
void end_of_day_routine(Pet **,int&); // loops and calls derived class functions for grooming and checkups
int array_filter(Pet **pets,std::vector<Adopter>&,int&); // filters through array and vector and decides what animals need to be adopted
void swap_and_pop(std::vector <Adopter> &, int); // switches the pet that needed to be adopted to the last index and calls pop_back()
 
Bird* add_pet_Bird(std::vector<Adopter>&); // creates a Bird obj, assigns data, and then returns a pointer to it 
Dog* add_pet_Dog(std::vector<Adopter>&); // creates a Dog obj, assigns data, and then returns a pointer to it 
double get_double(); // checks to make sure data is of type double and in this case bigger than 0
 
std::string pick_animal(); // filters through array of pets that the shelter is accepting and gets what type to user wants to enter 
bool is_in_array(std::string, const std::string[]); // returns true if a certain string is in array of strings
#endif

