#ifndef _ZOO_H_
#define _ZOO_H_

#include "Enclosure.hpp"
#include "ZooKeeper.hpp"

class Zoo {
private:
    int numOfEnclosures;
    Enclosure** enclosures;
    int numOfZooKeepers;
    ZooKeeper** zooKeepers;

public:
    Zoo();
    ~Zoo();
    void addAnimalToZoo(const char* name, const char* species, int age, const char* enclosureName);
    void removeAnimalFromZoo(const char* name);
    void displayAllanimals() const;
    void assignZookeeper(const char* zooKeeperName, const char* enclosureName);
};

#endif
