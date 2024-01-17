//Arielle Farhi 314617812
#ifndef _ZOOKEEPER_H_
#define _ZOOKEEPER_H_

#include "Enclosure.hpp"

class ZooKeeper {
private:
    char* zooKeeperName;
    int numOfAssignedEnclosures;
    Enclosure** assingedEnclosures;

public:
    ZooKeeper(const char* zooKeeperName);
    ~ZooKeeper();
    const char* getZooKeeperName() const;
    void assignToEnclosure(Enclosure* enclosure);
    void setZooKeeperName(char* zooKeeperName);
    void displayZooKeepers() const;
    int getNumOfAssigndEnclosures() const;
    Enclosure** getAssignedEnclosures() const;
};

#endif

