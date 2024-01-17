/**
 * @author Omer Segev
 * @ID 313772295
 * 
*/
#include "Enclosure.hpp"

Enclosure::Enclosure(string name)
    : name(name), num_of_animals(0), animals(nullptr), zoo_keeper(nullptr){};

Enclosure::~Enclosure()
{
    delete[] animals;
};

bool Enclosure::addAnimal(Animal *animal)
{
    Animal **new_animals = new Animal *[num_of_animals + 1];

    if (!new_animals)
    {
        cout << "ERROR: Memory allocation failed" << endl;
        return false;
    }

    for (int i = 0; i < num_of_animals; i++)
    {
        new_animals[i] = animals[i];
    }

    new_animals[num_of_animals] = animal;
    num_of_animals++;

    delete[] animals;
    animals = new_animals;

    return true;
}

bool Enclosure::removeAnimal(string name)
{
    for (int i = 0; i < num_of_animals; i++)
    {
        if (animals[i]->getName() == name)
        {
            delete animals[i];

            for (int j = i; j < num_of_animals - 1; j++)
            {
                animals[j] = animals[j + 1];
            }

            num_of_animals--;
            animals[num_of_animals] = nullptr;

            return true;
        }
    }
    return false;
}

bool Enclosure::hasAnimal(string name)
{
    for (int i = 0; i < num_of_animals; i++)
    {
        if (animals[i]->getName() == name)
        {
            return true;
        }
    }
    return false;
}

void Enclosure::displayEnclosure() const
{
    cout << "Animals:" << endl;
    for (int i = 0; i < num_of_animals; i++)
    {
        animals[i]->display();
    }
};
