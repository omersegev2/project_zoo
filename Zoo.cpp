/**
 * @author Omer Segev
 * @ID 313772295
 *
 */
#include "Zoo.hpp"

Zoo::Zoo() : num_of_enclosures(0), num_of_zooKeepers(0), enclosures(nullptr), zooKeepers(nullptr){};

Zoo::~Zoo()
{
    delete[] enclosures;
    delete[] zooKeepers;
};

void Zoo::addAnimal(string name, string species, int age)
{
    Enclosure *enclosure = findEnclosureByName(species);

    if (enclosure == nullptr)
    {
        enclosure = new Enclosure(species);
        addEnclosure(enclosure);
    }

    Animal *animal = new Animal(name, species, age);

    if (enclosure->addAnimal(animal))
    {
        cout << name << " added successfully to the zoo." << endl;
    }
    else
    {
        cout << "Error adding animal " << name << "." << endl;
        delete animal;
    }
}

void Zoo::removeAnimal(string name)
{
    for (int i = 0; i < num_of_enclosures; i++)
    {
        if (enclosures[i]->hasAnimal(name))
        {
            if (enclosures[i]->removeAnimal(name))
            {
                cout << "Animal " << name << " successfuly removed from the zoo." << endl;
                if (enclosures[i]->getNumOfAnimals() == 0)
                {
                    removeEnclosure(enclosures[i]);
                }
                return;
            }
            else
            {
                cout << "Error removing animal " << name << "." << endl;
            }
        }
    }
    cout << "Animal " << name << " not found in the zoo." << endl;
};

void Zoo::addEnclosure(Enclosure *enclosure)
{
    Enclosure **new_enclosures = new Enclosure *[num_of_enclosures + 1];

    for (int i = 0; i < num_of_enclosures; i++)
    {
        new_enclosures[i] = enclosures[i];
    }

    new_enclosures[num_of_enclosures] = enclosure;
    num_of_enclosures++;

    delete[] enclosures;
    enclosures = new_enclosures;
}

void Zoo::removeEnclosure(Enclosure *enclosure)
{
    for (int i = 0; i < num_of_enclosures; i++)
    {
        if (enclosures[i] == enclosure)
        {

            for (int j = i; j < num_of_enclosures - 1; j++)
            {
                enclosures[j] = enclosures[j + 1];
            }

            num_of_enclosures--;

            delete enclosures[num_of_enclosures];
            enclosures[num_of_enclosures] = nullptr;
            return;
        }
    }
}

void Zoo::displayZoo() const
{
    if (num_of_enclosures == 0)
    {
        cout << "The zoo is currently empty." << endl;
        return;
    }
    for (int i = 0; i < num_of_enclosures; i++)
    {
        cout << "ENCLOSURE " << enclosures[i]->getName() << ":" << endl;

        ZooKeeper *zk = reinterpret_cast<ZooKeeper *>(enclosures[i]->getZooKeeper());
        if (zk)
        {
            cout << "Keeper: " << reinterpret_cast<ZooKeeper *>(enclosures[i]->getZooKeeper())->getName() << endl;
        }
        enclosures[i]->displayEnclosure();
        cout << endl;
    }
};

void Zoo::assignZooKeeper(string keeper_name, string enclosure_id)
{
    Enclosure *enclosure = findEnclosureByName(enclosure_id);

    if (enclosure == nullptr)
    {
        cout << "Enclosure " << enclosure_id << " not found in the zoo. Cannot assign ZooKeeper." << endl;
        return;
    }

    ZooKeeper *zooKeeper = findZooKeeperByName(keeper_name);

    if (zooKeeper == nullptr)
    {
        zooKeeper = new ZooKeeper(keeper_name);
        addZooKeeper(zooKeeper);
    }
    else if (zooKeeper->isAssignedToEnclosure(enclosure))
    {
        cout << "ZooKeeper " << zooKeeper->getName() << " is already assigned to Enclosure " << enclosure->getName() << "." << endl;
        return;
    }

    zooKeeper->assignToEnclosures(enclosure);
    enclosure->setZooKeeper(zooKeeper);
};

void Zoo::addZooKeeper(ZooKeeper *zooKeeper)
{
    ZooKeeper **new_zooKeepers = new ZooKeeper *[num_of_zooKeepers + 1];

    for (int i = 0; i < num_of_zooKeepers; i++)
    {
        new_zooKeepers[i] = zooKeepers[i];
    }

    new_zooKeepers[num_of_zooKeepers] = zooKeeper;
    num_of_zooKeepers++;

    delete[] zooKeepers;
    zooKeepers = new_zooKeepers;
    
    cout << "ZooKeeper " << zooKeeper->getName() << " added successfully to the zoo." << endl;
};

Enclosure *Zoo::findEnclosureByName(string name)
{
    for (int i = 0; i < num_of_enclosures; i++)
    {
        if (enclosures[i]->getName() == name)
        {
            return enclosures[i];
        }
    }
    return nullptr;
};

ZooKeeper *Zoo::findZooKeeperByName(string name) {
    for (int i = 0; i < num_of_zooKeepers; i++)
    {
        if (zooKeepers[i]->getName() == name)
        {
            return zooKeepers[i];
        }
    }
    return nullptr;
};
