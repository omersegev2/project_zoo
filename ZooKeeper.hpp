/**
 * @author Omer Segev
 * @ID 313772295
 * 
*/
#ifndef __ZOOKEEPER_HPP__
#define __ZOOKEEPER_HPP__

#include "Enclosure.hpp"

class ZooKeeper
{
private:
    int num_of_assigned_enclosures;
    string name;
    Enclosure **assignedEnclosures;

public:
    ZooKeeper(string name);
    ~ZooKeeper();
    string getName() { return name; };
    void assignToEnclosures(Enclosure *enclosure);
    bool isAssignedToEnclosure(Enclosure *enclosure);
};

#endif //__ZOOKEEPER_HPP__
