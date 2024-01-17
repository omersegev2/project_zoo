/**
 * @author Omer Segev
 * @ID 313772295
 *
 */
#include "ZooKeeper.hpp"

ZooKeeper::ZooKeeper(string name) : name(name), assignedEnclosures(nullptr){};

ZooKeeper::~ZooKeeper()
{
    delete[] assignedEnclosures;
};

void ZooKeeper::assignToEnclosures(Enclosure *enclosure)
{
    if (enclosure == nullptr)
    {
        cout << "Cannot assign to a null enclosure." << endl;
        return;
    }

    for (int i = 0; i < num_of_assigned_enclosures; i++)
    {
        if (assignedEnclosures[i] == enclosure)
        {
            cout << "ZooKeeper " << name << " is already assigned to Enclosure " << enclosure->getName() << "." << endl;
            return;
        }
    }

    Enclosure **new_assigned_enclosures = new Enclosure *[num_of_assigned_enclosures + 1];

    for (int i = 0; i < num_of_assigned_enclosures; i++)
    {
        new_assigned_enclosures[i] = assignedEnclosures[i];
    }

    new_assigned_enclosures[num_of_assigned_enclosures] = enclosure;
    num_of_assigned_enclosures++;

    delete[] assignedEnclosures;
    assignedEnclosures = new_assigned_enclosures;

    cout << "ZooKeeper " << name << " assigned to Enclosure " << enclosure->getName() << "." << endl;
}

bool ZooKeeper::isAssignedToEnclosure(Enclosure *enclosure)
{
    for (int i = 0; i < num_of_assigned_enclosures; i++)
    {
        if (assignedEnclosures[i] == enclosure)
        {
            return true;
        }
    }
    return false;
}