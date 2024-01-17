#include "Animal.hpp"

Animal:: Animal(const char* animalName, const char* species, int age) {
    this->animalName = new char[strlen(animalName) + 1];
    if(this->animalName == NULL) {
        return;
    }
    strcpy(this->animalName, animalName);

    this->species = new char[strlen(species) + 1];
    if(this->species == NULL) {
        delete[] this->animalName;
        return;
    }
    strcpy(this->species, species);

    this->age = age;
}

Animal:: ~Animal() {
    delete[] animalName;
    delete[] species;
}

const char* Animal:: getAnimalName() const {
    return animalName;
}

const char* Animal:: getAnimalSpecies() const {
    return species;
}

const int Animal:: getAnimalAge() const {
    return age;
}

void Animal:: displayDetails() const {
    cout << "  - Animal Name: " << this->getAnimalName() << ", ";
    cout << "Animal Species: " << this->getAnimalSpecies() << ", ";
    cout << "Animal Age: " << this->getAnimalAge() << ".";
}

void Animal:: setAnimal(const char* animalName, const char* species, int age) {
    delete[] this->animalName;
    this->animalName = new char[strlen(animalName) + 1];
    strcpy(this->animalName, animalName);

    delete[] this->species;
    this->species = new char[strlen(species) + 1];
    strcpy(this->species, species);

    this->age = age;
}



