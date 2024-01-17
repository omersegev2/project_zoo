//Arielle Farhi 314617812
#ifndef _ENCLOSURE_H_
#define _ENCLOSURE_H_

#include "Animal.hpp"

class ZooKeeper;

class Enclosure {
private:
    char* enclosureName;
    int numOfAnimals;
    Animal** animals;
    ZooKeeper* zookeeper;

public:
    Enclosure(const char* enclosureName);
    ~Enclosure();
    const char* getEnclosureName() const;
    void addAnimal(Animal* animal);
    void removeAnimal(Animal* animal);
    void displayAnimalsInEnclosre() const;
    void assignZooKeeper(ZooKeeper* zooKeeper);
    Animal** getAnimals() const;
    int getNumOfAnimals() const;
    void printDetails() const;
};

#endif

