#include "Enclosure.hpp"

Enclosure::Enclosure(const char* enclosureName) : numOfAnimals(0), animals(nullptr), zookeeper(nullptr) {
    this->enclosureName = new char[strlen(enclosureName) + 1];
    if(this->enclosureName == NULL) {
        return;
    }
    strcpy(this->enclosureName, enclosureName);
}

Enclosure::~Enclosure() {
    delete[] enclosureName;
    delete[] animals;
}

const char* Enclosure::getEnclosureName() const {
    return enclosureName;
} 

void Enclosure::addAnimal(Animal* animal) {
    Animal** newAnimals = new Animal*[numOfAnimals + 1];
    for (int i = 0; i < numOfAnimals; i++) {
        newAnimals[i] = animals[i];
    }
    newAnimals[numOfAnimals] = animal;
    delete[] animals;
    animals = newAnimals;
    numOfAnimals++;
}

void Enclosure::removeAnimal(Animal* animal) {
    for(int i = 0; i < numOfAnimals; i++) {
        if(strcmp(animal->getAnimalName(), animals[i]->getAnimalName()) == 0) {
            for(int j = i; j < numOfAnimals; j++) {
                animals[j] = animals[j + 1];
            }
            numOfAnimals--;
            return;
        }
    }
}

void Enclosure:: displayAnimalsInEnclosre() const {
    cout << "Animals in Enclosure " << this->getEnclosureName() << ": " << endl;
    for(int i = 0; i < numOfAnimals; i++) {
        this->animals[i]->displayDetails();
        cout << endl;
    }
}

void Enclosure:: assignZooKeeper(ZooKeeper* zooKeeper) {
    this->zookeeper = zooKeeper;
}

Animal** Enclosure:: getAnimals() const {
    return this->animals;
}

int Enclosure:: getNumOfAnimals() const {
    return this->numOfAnimals;
}

void Enclosure:: printDetails() const {
    cout << this->getEnclosureName() << endl;
}