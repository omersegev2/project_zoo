/**
 * @author Omer Segev
 * @ID 313772295
 * 
*/

#include "Animal.hpp"

Animal::Animal(string name, string species, int age) : name(name), species(species), age(age){};

void Animal::display() const
{
    cout << "Name: " << this->name << endl;
    cout << "Species: " << this->species << endl;
    cout << "Age: " << this->age << endl;
}
