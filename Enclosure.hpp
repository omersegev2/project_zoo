/**
 * @author Omer Segev
 * @ID 313772295
 * 
*/
#ifndef __ENCLOSURE_HPP__
#define __ENCLOSURE_HPP__

#include "Animal.hpp"

class Enclosure
{
private:
    string name;
    int num_of_animals;
    Animal **animals;
    void *zoo_keeper;

public:
    Enclosure(string name);
    ~Enclosure();

    bool addAnimal(Animal *animal);
    bool removeAnimal(string name);

    Animal **getAnimal() { return animals; };
    string getName() { return name; };
    int getNumOfAnimals() { return num_of_animals; };

    void setZooKeeper(void *keeper) { zoo_keeper = keeper; };
    void* getZooKeeper() { return zoo_keeper; };

    bool hasAnimal(string name);

    void displayEnclosure() const;
};

#endif //__ENCLOSURE_HPP__
