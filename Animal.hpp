/**
 * @author Omer Segev
 * @ID 313772295
 * 
*/
#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <string>
#include <iostream>

using namespace std;

class Animal
{
private:
    string name;
    string species;
    int age;

public:
    Animal(string name, string species, int age);
    ~Animal(){};
    string getName() { return name; };
    void display() const;
};

#endif //__ANIMAL_HPP__
