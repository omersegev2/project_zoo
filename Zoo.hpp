/**
 * @author Omer Segev
 * @ID 313772295
 * 
*/
#ifndef __Z00_HPP__
#define __Z00_HPP__

#include "Enclosure.hpp"
#include "ZooKeeper.hpp"

class Zoo
{
private:
    int num_of_enclosures;
    int num_of_zooKeepers;
    Enclosure **enclosures;
    ZooKeeper **zooKeepers;

public:
    Zoo();
    ~Zoo();
    void addAnimal(string name, string species, int age);
    void removeAnimal(string name);
    void addEnclosure(Enclosure* enclosure);
    void removeEnclosure(Enclosure* enclosure);
    void addZooKeeper(ZooKeeper* ZooKeeper);
    void displayZoo() const;
    void assignZooKeeper(string keeper_name, string enclosure_id);
    Enclosure* findEnclosureByName(string id);
    ZooKeeper* findZooKeeperByName(string name);
};

#endif //__Z00_HPP__

