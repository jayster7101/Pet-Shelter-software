#include "helpers_main.h"
#include "Adopters.h"
#include <vector>
 
std::string local_file = "0______0";
 
 
/**
* @brief gets the name of the file
* has a fail safe for when the users file doesnt exist and asks if they would like to postpone this operation tell later
* used for reading in from a text file
* @param  NONE
* @return string of the files name or defaults to  "nofile"
*/
   std::string get_file()
   {
       int count = 0;
       std::string _file;
       std::cout << "You stated that you have current inventroy.\nPlease input the files name to access that data\n> ";
       std::cin >> _file;
       std::ifstream file;
       file.open(_file);
       while(file.fail())
       {
          count++;
          std::cout<< "It seems that that file does not exist please try again\n> ";
          std::cin >> _file;
          file.open(_file);
          if(!file.fail())
          {
              file.clear();
          }
          if(count == 4)
           {
               std::cout << "It seems that you are having trouble opening a file, would you like for us to bypass this and create a new file later on instead?\nPlease enter yes or no\n>";
               bool _enter = enter();
               if(_enter)
               {
                   _file = "nofile";
                   return _file;
               }
               count = 0;
 
           }
       }
       local_file = _file;
       return _file;
   };
 
/**
* @brief greets the user and explains the program
* then it asks if they would like to enter the program
* @param  NONE
* @return NONE
*/
   void greet()
   {
        std::cout << "Hello Welcome to pet shelter express! We provide top of the line software for pet shelters all over the united states\n";
        std::cout << "Would you like to enter the program?\n";
        std::cout<< "Please enter yes or no?\n> ";
   }
 
/**
* @brief gets the users responce to yes or no questions
* @param  NONE
* @return bool true if the answer is yes, false if the answer is no
*/
bool enter()
{
   bool return_value;
   std::string yes_no;
   bool reprompt = false;
       while(!reprompt) // this is the first instance of input validation which only accepts yes or Yes or No or no and will keep prompting until valid
       {
           if(std::cin.fail()) std::cin.ignore(100,'\n'); // ignores the flag on the error
           std::cin >> yes_no;
           if(yes_no =="yes" || yes_no =="Yes")// the logic below compares the string to the 4 possible values, and then returns true or false to either enter the if statement or skip to the else statement in the main function
           {
               reprompt = true;
               return_value = true;
           }
           else if (yes_no =="no" || yes_no =="No")
           {
               reprompt = true;
               return_value = false;
           }
           else
           {
               std::cout<<"Please enter yes or no only\n> ";
           }
       }
   return return_value;
}
 
/**
* @brief greets the user if they have inventory and then call the enterr function to get their responce
* @param  NONE
* @return bool
*/
bool filepath()
{
   std::cout << "Do you have inventory that needs to be accounted for?\nPlease enter yes or no\n> ";
   bool pick = enter();
   return pick;
}
 
/**
* @brief This function work along side parse_reader, this first part gets the users .txt file and opens an input file stream
* it then uses the getline method to get each line of the stream from the .txt file
* it then passes each line into the parse_reader with the index of the next available spot in the array
* also passes in the line from get line and the pets array
* @param  *pets [pointer to the array of type Pet]
* @return NONE
*/
void read_write (Pet **pets, std::vector<Adopter> &adopters, int &amount)
{
   std::string file = get_file(); // gets a file
   if(file == "nofile")
   {
       return;
   }
   std::ifstream in;
   in.open(file);
   std::string get_line;
   int count = 0;
   std::string _amount;
   getline(in,_amount);
   amount = stoi(_amount);
   while(getline(in,get_line) && amount <= MAX && count < MAX)
   {
       parse_reader(get_line , pets, count, adopters);
       count++;
   }
   read_write_vector(adopters);
} 
/**
* @brief This function works along side read_write
* it takes the line and opens a string stream with the value passsed in from the read_write function
* it assigns values from the text file to their appropriate values and then creates an instance of an object with those specified values
* lastly it pushes that object into the Pet pets array
* @param  *pets [pointer to the array of type Pet], _text from the getline in read_write, count to know where we are in the array
* @return NONE
*/
void parse_reader(std::string _text, Pet **pets, int count, std::vector<Adopter> &adopters) {
       std::string type;
       double age;
       std::string name;
       int days;
       double weight;
       int id;
       int current_grooming;
       int current_checkup;
       std::string breed;
       std::string fav_chew_toy;
       std::string color;
       bool speak;
 
       bool adopt;
       std::string phone_number;
       std::string adopter_name;
 
       std::stringstream ss (_text);
       ss >> type;// >> name >> age >> days >> weight >> id;
       if(type == "Bird")
       {
           ss >> name >> age >> days >> weight >> id >> color >> speak >> current_grooming >> current_checkup >> adopt >> phone_number >> adopter_name;
           Bird *bird= new Bird(name,id,days,color);
           bird->set_age(age);
           bird->set_weight(weight);
           bird->set_can_speak(speak);
           bird->set_current_grooming(current_grooming);
           bird->set_current_checkup(current_checkup);
           bird->potential.set_adopt(adopt);
           bird->potential.set_phone_number(phone_number);
           bird->potential.set_name_of_adopter(adopter_name);
           pets[count] = bird;
           if(adopt == true)
           {
               Adopter temp;
               temp.set_adopt(adopt);
               temp.set_phone_number(phone_number);
               temp.set_name_of_adopter(adopter_name);
               temp.set_pets_id(id);
               adopters.push_back(temp);
           }
           //delete bird;
       }
       else
       {
           ss >> name >> age >> days >> weight >> id  >> fav_chew_toy >> breed >> current_grooming >> current_checkup >> adopt >> phone_number >> adopter_name;
           Dog *dog= new Dog(name,id,days);
           dog->set_age(age);
           dog->set_weight(weight);
           dog->set_fav_toy(fav_chew_toy);
           dog->set_breed(breed);
           dog->set_current_grooming(current_grooming);
           dog->set_current_checkup(current_checkup);
           dog->potential.set_adopt(adopt);
           dog->potential.set_phone_number(phone_number);
           dog->potential.set_name_of_adopter(adopter_name);           
           pets[count] = dog;
           if(adopt == true)
           {
               Adopter temp;
               temp.set_adopt(adopt);
               temp.set_phone_number(phone_number);
               temp.set_name_of_adopter(adopter_name);
               temp.set_pets_id(id);
               adopters.push_back(temp);
           }
           //delete dog;           
       }
 
 
}
 
void print_array (Pet *pets,int amount)
{
   for(int i = 0; i < amount; i++)
   {
       std::cout << pets[i].get_age() <<" " <<  pets[i].get_name() << " " <<  pets[i].get_days() << " " << pets[i].get_weight() << " " << pets[i].get_id() << "\n";
   }
}
/**
* @brief This function adds a pet to the array,
* it displays how many available spots are in the shelter,
* it gets all the relevant information with input validation and then pushes that object to the pets array
* if the max limit is reached then it displays helpful information and then calls the write_array function to handle saving the data
* @param  *pets [pointer to the array of type Pet]
* @return bool true if more pets can be added and false if the shelter is full
*/
bool add_pet(Pet **pets,std::vector<Adopter> &adopters, int &amount)
{
   bool temp = false;
    while(amount != MAX && !temp )
    {
       printBox();
       std::cout << "There are currently " << MAX-amount << " available spots.\n";
       std::cout << "Would you like to add an animal to the shelter?\n> ";
       bool ask = enter();
       if(ask)
       {

            std::string animal_type = pick_animal();
            if(animal_type == "Bird")
            {
                Bird *bird = add_pet_Bird(adopters);
                pets[amount] = bird;
                amount++;
            }
            else
            {
                Dog *dog = add_pet_Dog(adopters);
                pets[amount] = dog;
                amount++;
            }
       } 
       else
       {
           temp = true;
       }
    }
    printBox();
    if (amount == 20)
    {
        helpful_info();
        write_array(pets,adopters,amount);
        return false;
    }
    else
    {
        return true;
    }
}
/**
* @brief gets the users decision on saving the data or not
* double checks before erasing any data
* asks if the user wants to use the same file they read in from if applicable or asks for the new files name
* lastly it opens an output file stream and writes all data to the txt file
* @param  *pets [pointer to the array of type Pet]
* @return NONE
*/
void write_array(Pet **pets, std::vector <Adopter> &adopters, int &amount)
{
   std::ofstream out;
   std::cout << "Would you like to save this data to a txt file ?\n>";
   bool go = enter();
   if(!go)
   {
       std::cout << "Are you sure you dont want to save this data? All of it will be destroyed!!! Enter yes to destory data\n>";
       bool _enter = enter();
       if(_enter)
       {
           std::cout << "All data is not saved has since been purged!!!\n";
       }
       else
       {
           go = true;
       }
   }
   if(go)
   {
       if(local_file == "0______0")
       {
           std::string file;
           std::cout << "What you like to name this file?\n>";
           std::cin >> file;
           out.open(file+=".txt");
           local_file = file;
       }
       else
       {
           std::cout << "Would you like to use the file named " << local_file <<" to save the data?\n>";
           bool _enter = enter();
           if(_enter)
           {
               out.open(local_file);
           }
           else
           {
           std::string file;
           std::cout << "What would you like to name this file?\n>";
           std::cin >> file;
           out.open(file+=".txt");
           local_file = file;
 
           }
       }
   }
   int less = array_filter(pets,adopters,amount);
   int temp = amount-less;
   out << temp <<"\n";//-less
   if(less != 0) std::cout << "************************ Pets Adopted Today ************************\n";
   for(int i = 0; i < amount; i++) // ss >> type >> name >> age >> days >> weight >> id;
   {
       if(pets[i]->get_type() == "Bird")
       {
          if(pets[i]->get_age() != -1) { out << pets[i]->get_type() << " " << pets[i]->get_name() << " " << pets[i]->get_age() << " " <<  pets[i]->get_days()+1 << " " << pets[i]->get_weight() << " " << pets[i]->get_id() << " " << pets[i]->get_color() << " " << pets[i]->get_can_speak() << " " << pets[i]->get_current_grooming() << " " << pets[i]->get_current_checkups() << " " << pets[i]->potential.get_adopt() << " " << pets[i]->potential.get_phone_number()<< " " <<  pets[i]->potential.get_name_of_adopter() << "\n";}
       }
       else
       {
          if(pets[i]->get_age() != -1) out << pets[i]->get_type() << " " << pets[i]->get_name() << " " << pets[i]->get_age() << " " <<  pets[i]->get_days()+1 << " " << pets[i]->get_weight() << " " << pets[i]->get_id()<< " " << pets[i]->get_fav_toy() << " " << pets[i]->get_breed() << " " << pets[i]->get_current_grooming() << " " << pets[i]->get_current_checkups() << " " <<pets[i]->potential.get_adopt() << " " << pets[i]->potential.get_phone_number() << " " <<  pets[i]->potential.get_name_of_adopter() << "\n";
       }
       if(pets[i]->get_age() == -1) std::cout << pets[i]->get_name() << " the " << pets[i]->get_type() << " with an ID number of " << pets[i]->get_id() << "\n"; 
   }
      if(less != 0) std::cout << "********************************************************************\n" << "\n";
}
// outputs a simple helpul/meaningful message
void helpful_info()
{
   std::cout << "It seems that our shelter is at max capacity and isn't accepting any new animals.\nAnother great shelter is located just down the road at 1950 Stevenson Blvd, Fremont, CA 94538\nThey are open from 11:00am to 4:00pm Monday through Thursday.\nWe suggest getting ahold of them before driving down there, their phone number is : (510) 790-6640\n";
}
 
 
/**
* @brief finds the pet who has been in the shelter the longest by searching through the entire array and checking against the known largest or replacing the largest
* @param  *pets [pointer to the array of type Pet]
* @return Pet 
*/
 
int find_a_home(Pet **pets, int &amount)
{

   int longest = 0;
   int temp = 0;
   for (int i = 0; i < amount; i++)
   {
       if((pets[i]->get_days() > longest) && (pets[i]->get_age() != -1))
       {
           temp = i;
           longest = pets[i]->get_days();
       }
   }


   return temp;
}
 
/**
* @brief displays the animal thats been in the shelter the longest,
* used along side find_a_home, which gets the index of the animal thats been in the shelter the longest
* then prints the relevant information
* @param  *pets [pointer to the array of type Pet]
* @return NONE
*/
void find(Pet **pets, int &amount)
{
   std::cout << "Would you like to see the animal who has been in the shelter the longest?\n>";
   bool _enter = enter();
   if(_enter)
   {
        std::cout << "\n************************ Longest pet in shelter ************************\n";
        int index = find_a_home(pets,amount);
        std::cout << pets[index]->get_name() << " the " << pets[index]->get_type() << " has been in this shelter for " << pets[index]->get_days() << " days!\nBe his savior and adopt him.\n";
        std::cout << "*************************************************************************\n";
   }
 
}
 
void no_enter()
{
   std::cout << "Thank you for your time and have a good day.\n";
}
 
void printBox()
{
   std::cout << "-----------------------------------------------------\n";
}
 
/**
* @brief gets a type double from user
* built in error handeling
* @return double
*/
double get_double()
{
   double _double;
   std::cin >> _double;
   while(std::cin.fail() || (_double < 1))
   {
       if(_double < 1)
       {
           std::cout << "Sorry numbers under 1 are not accepted\n";
       }
       std::cin.ignore(100,'\n');
      
       std::cout << "Please enter a number only Ex:(1,3.4,45.78)\n>";
       std::cin >> _double;
       std::cin.clear();
      
   }
   return _double;
}
 
/**
* @brief gets the users animal they are putting into shelter
* checks to see if they are adding the right type of animal
*
* @return string
*/
std::string pick_animal()
{
   int array_size = (sizeof(list) / (sizeof(list[0])));
   std::cout << "Which type of animal would you like to enter into the shelter?\nWe are currently only accepting ";
   for(int i = 0; i < array_size; i++)
   {
       std::cout << list[i];
       if(i != array_size-1)
       {
           std::cout <<"s, ";
       }
       else std::cout << "s!\n> ";
   }
   std::string user;
   std::cin >> user;
   while (!(is_in_array(user, list)))
   {
       std::cout << "Sorry we aren't accepting " << user << ". Please enter in the word correctly Ex:";
       for(int i = 0; i < array_size; i++)
   {
       std::cout << list[i];
       if(i != array_size-1)
       {
           std::cout <<", ";
       }
       else std::cout << "...etc!\n";
   }
   std::cin >> user;
   }
   return user;
}
 
/**
* @brief checks to see if a type string is in an array of strings
*
* @param in
* @param array
* @return true
* @return false
*/
bool is_in_array(std::string in, const std::string array[])
{
   int size = (sizeof(list) / (sizeof(list[0])));
   for(int i = 0; i < size; i ++)
   {
       if(in == array[i])
       {
           return true;
       }
   }
   return false;
}
 
 























/**
 * @brief creates an instance of a Bird object dynamically, assigns data and then returns the pointer 
 * if the Bird has a potential adopter it will populate the data members for the aggregated class and push it to the vector
 * @param adopters -passed by reference 
 * @return Bird* pointer of type Bird
 */
Bird* add_pet_Bird (std::vector<Adopter> &adopters)
{
   Bird *bird = new Bird();
   bird->set_name();
   double age;
   double weight;
   std::cout << "What is the estimated age of this animal in years? Ex: 12.5, 8.2\n> ";
   age = get_double();
   bird->set_age(age);
   std::cout << "How much does " << bird->get_name() << " Weigh in pounds? Ex: 67.23, 12.82\n> ";
   std::cin >> weight;
   while(std::cin.fail())
   {
       std::cin.clear();
       std::cin.ignore(100, '\n');
       std::cout<<"sorry please enter a number\n> ";
       std::cin >> weight;
   }
   bird->set_weight(weight);
   std::string color;
   std::cout << "What color is this bird?\n> ";
   std::cin >> color;
   bird->set_color(color);
   bool input;
   std::cout << "Can the bird speak? Yes or No only\n> ";
   input = enter();
   bird->set_can_speak(input);
   std::cout << "Does the Bird have a potential adopter? Yes or No only\n> ";
   bool adopt = enter();
   if(adopt == true)
   {
       bird->potential.set_adopt(adopt);
       std::cout << "Whats the name of the potential adopter?\n> ";
       std::string name;
       std::cin >> name;
       std::cout << "Whats is " << name << "s phone number? Ex:5102347834\n> " ;
       bird->potential.set_name_of_adopter(name);
       std::string number = get_number(name);
       bird->potential.set_phone_number(number);
       bird->potential.set_pets_id(bird->get_id());
       Adopter temp;
       temp.set_adopt(adopt);
       temp.set_phone_number(number);
       temp.set_name_of_adopter(name);
       temp.set_pets_id(bird->get_id());
       adopters.push_back(temp);
   }
   return bird;
}

/**
 * @brief creates an instance of a Dog object dynamically, assigns data and then returns the pointer 
 * if the Dog has a potential adopter it will populate the data members for the aggregated class and push it to the vector
 * @param adopters -passed by reference 
 * @return Dog* pointer of type Dog
 */
 
Dog* add_pet_Dog (std::vector <Adopter> &adopters)
{
   Dog *dog = new Dog();
   dog->set_name();
   double age;
   double weight;
   std::cout << "What is the estimated age of this animal? Ex: 15.5\n> ";
   age = get_double();
   dog->set_age(age);
   std::cout << "How much does " << dog->get_name() << " Weigh in pounds? Ex: 27.3\n> ";
   weight = get_double();
   dog->set_weight(weight);
   std::string toy;
   std::cout << "Whats the dogs favorite toy? Ex: ball,kong,TugOWar\n> ";
   std::cin >> toy;
   dog->set_fav_toy(toy);
   std::string breed;
   std::cout << "Whats breed is the dog? Ex:German_shepard,PitBull,yorkie\n> ";
   std::cin >> breed;
   dog->set_breed(breed);
   std::cout << "Does the dog have a potential adopter Yes or No only\n> ";
   bool adopt = enter();
   if(adopt == true)
   {
       dog->potential.set_adopt(adopt);
       std::cout << "Whats the name of the potential adopter?\n> ";
       std::string name;
       std::cin >> name;
       dog->potential.set_name_of_adopter(name);
       std::cout << "Whats is " << name << "s phone number?\n> ";
       std::string number = get_number(name);
       dog->potential.set_phone_number(number);
       dog->potential.set_pets_id(dog->get_id());
       Adopter temp;
       temp.set_adopt(adopt);
       temp.set_phone_number(number);
       temp.set_name_of_adopter(name);
       temp.set_pets_id(dog->get_id());
       adopters.push_back(temp);
   }
   return dog;
}
 
 
 /**
  * @brief filters through the array and calls both
  * perform_grooming();
  * perform_checkup();
  * outputs when the pet is either groomed or has had a checkup 
  * @warning are virtual functions so be carefull
  * @param pets 
  * @param amount 
  * @return NONE
  */
void end_of_day_routine(Pet **pets, int &amount)
{
   std::cout << "\n************************ Animal Maintence Log ************************" << "\n";
   for (int i = 0; i < amount; i++)
   {
       pets[i]->perform_grooming();
       pets[i]->perform_checkup();
   }
   std::cout << "**********************************************************************" << "\n";
  
};

/**
 * @brief Gets the phone number for the user of the program
 * @warning this doesn't check if what the user enters is valid 
 * @param name - name of potential adopter
 * @return number string 
 */
std::string get_number(std::string name)
{
   std::string number;
   std::cout << "Whats is " << name << "s phone number?\n>";
   std::cin >> number;
 
   while(number.length() != 10 )
   {
       std::cin.ignore(100,'\n');
       std::cout << "please enter a valid phone number\n>";
       std::cin >> number;
   }
   return number;
}
 
 /**
  * @brief creates an instance of the Adopter class object and reads in file
  *  assigns all data members and pushes to vector 
  * @param line - line from .txt file
  * @param adopter_array 
  */
void push_to_vector(std::string line,std::vector<Adopter> &adopter_array)
{
   Adopter temp;
   std::stringstream ss(line);
   std::string number;
   std::string name;
   bool adopt;
   int id;
   ss >> adopt >> number  >> name >> id;
   temp.set_adopt(adopt);
   temp.set_phone_number(number);
   temp.set_name_of_adopter(name);
   temp.set_pets_id(id);
   adopter_array.push_back(temp);
}
 
 /**
  * @brief reads in data from .txt file and assigns pushes to vector 
  * gets the .txt file for potential adopters
  * opens an ifsream
  * gets the line using the getline() function 
  * and then passes both the vector and line to push_to_vector()
  
  * 
  * @param adopter_array 
  */
void read_write_vector (std::vector<Adopter> adopter_array)
{
   std::string file = get_file_vector(); // gets a file
   if(file == "nofile")
   {
       return;
   }
   std::ifstream in;
   in.open(file);
   std::string get_line;
 
   while(getline(in,get_line) )
   {
       push_to_vector(get_line,adopter_array);
   }
}
 
 /**
  * @brief Gets the file for the potential adopters 
  * has built in data validation and allows the user to exit the loop if they cant get a file to open
  * @param NONE 
  * @return file string 
  */
std::string get_file_vector()
   {
 
       std::cout << "\n*****[Adopters]*****" << "\n";
       std::cout << "Do you have any potential adopeters for the current inventory? Yes or No\n> ";
       bool guess = enter();
       if (!guess) return "nofile";
       int count = 0;
       std::string _file;
       std::cout << "You stated that you have current inventroy for potential adopters.\nPlease input the file name to access the data for the potential adopters Ex: adopter_(filename)\n> ";
       std::cin >> _file;
       std::ifstream file;
       file.open(_file);
       while(file.fail())
       {
          count++;
          std::cout<< "It seems that that file does not exist please try again\n> ";
          std::cin >> _file;
          file.open(_file);
          if(!file.fail())
          {
              file.clear();
          }
          if(count == 4)
           {
               std::cout << "It seems that you are having trouble opening a file, would you like for us to bypass this and create a new file later on instead?\nPlease enter yes or no\n>";
               bool _enter = enter();
               if(_enter)
               {
                   _file = "nofile";
                   return _file;
               }
               count = 0;
           }
       }
       std::cout <<"\n";
       return _file;
   };
 
 /**
  * @brief opens a ofstream given the name ouy and and writes to a .txt file 
  * @param adopt 
  * @returns NONE
  */
   void write_to_file_vector (std::vector<Adopter> adopt)
   {
       std::string file = get_output_file();
       if(file == "nofile")
       {
           return;
       }
       else
       {
           std::ofstream out;
           out.open(file);
 
           int count = adopt.size();
           out << adopt.size() << "\n";
           for(int i = 0; i < count; i++)
           {
               out << adopt[i].get_adopt() << " " << adopt[i].get_phone_number() << " " << adopt[i].get_name_of_adopter() << " " << adopt[i].get_pets_id() << "\n";
           }
       }
   }
 /**
  * @brief Gets the output file name 
  * if the user had already entered in a file name in the begging of the program
  * the program will ask if they want to save it using that 
  * @param NONE 
  * @return file string
  */
   std::string get_output_file()
   {
       std::cout << "Would you like to save the data from all of the potential adopeters?\n>";
       bool go = enter();
       if(!go)
       {
           std::cout << "Are you sure you dont want to save this data? All of it will be destroyed!!! Enter yes to destory data\n>";
           bool _enter = enter();
           if(_enter)
           {
               std::cout << "All data is not saved has since been purged!!!\n";
               return "nofile";
           }
           else
           {
               go = true;
           }
       }
       if(go)
       {
           if(local_file == "0______0")
           {
               std::string file;
               std::cout << "What would you like to name this file?\n>";
               std::cin >> file;
               return file+=".txt";
           }
           else
           {
               std::cout << "Would you like to use the file named adopter_" << local_file <<" to save the data?\n>";
               bool _enter = enter();
               if(_enter)
               {
                   return ("adopter_"+local_file);
               }
               else
               {
               std::string file;
               std::cout << "What would you like to name this file?\n>";
               std::cin >> file;
               return file;
               }
           }
       }
   };
 

 /**
  * @brief filters through the array and find what animals have been adopted
  * if an pet needs to be adopted then it will get its age value set to -1 
  * so that the write_array() function knows which animals have been adopted
  * 
  * also sends the id number of the adopted pet to a function that deals with removing it from the vector
  * @param pets 
  * @param adopters 
  * @param amount 
  * @return count int -> which is how much smaller the array should be after teh pets are adopted
  */
int array_filter(Pet **pets,std::vector <Adopter> &adopters, int &amount)
{
   int count = 0;
   for(int i = 0; i < amount; i++)
   {
       if((pets[i]->potential.get_adopt() == true) && (pets[i]->get_days() == 10))
       {
           pets[i]->set_age(-1);
           int temp;
           temp = pets[i]->potential.get_pets_id();
           swap_and_pop(adopters,temp);
           count++;
       }
       if((pets[i]->potential.get_adopt() == false) && (pets[i]->get_days() == 15))
       {
           pets[i]->set_age(-1);
 
           int temp;
           temp = pets[i]->potential.get_pets_id();
           swap_and_pop(adopters,temp);           
           count++;           
       }
   }
   return count;
}
/**
 * @brief deletes the pet that has been adopted from the vector 
 * first it filters through the vector and finds which animals id matches with the id passed as a parmater  
 * it then erases that index of the vector
 * 
 * @param adopters 
 * @param id 
 */
void swap_and_pop(std::vector <Adopter> &adopters, int id)
{
   int from = 0;
   //int to = (adopters.size());
   for(int i = 0; i < adopters.size(); i++)
   {
       if(adopters[i].get_pets_id() == id)
       {
           from = i;
       }
   }
   adopters.erase(adopters.begin() + from);
}
 

