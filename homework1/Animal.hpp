//Arielle Farhi 314617812
#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <iostream>
#include <cstring>
using namespace std;

class Animal {
private:
    char* animalName;
    char* species;
    int age;

public:
    Animal(const char* animalName, const char* species, int age);
    ~Animal();
    const char* getAnimalName() const; 
    const char* getAnimalSpecies() const; 
    const int getAnimalAge() const;
    void displayDetails() const;
    void setAnimal(const char* animalName, const char* species, int age);
};

#endif

