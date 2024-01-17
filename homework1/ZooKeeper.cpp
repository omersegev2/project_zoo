#include "ZooKeeper.hpp"

ZooKeeper:: ZooKeeper(const char* zooKeeperName): numOfAssignedEnclosures(0), assingedEnclosures(nullptr) {
    this->zooKeeperName = new char[strlen(zooKeeperName) + 1];
    if(this->zooKeeperName == NULL) {
        return;
    }
    strcpy(this->zooKeeperName, zooKeeperName);
}

ZooKeeper:: ~ZooKeeper() {
    delete [] zooKeeperName;
    delete[] assingedEnclosures;
}

const char* ZooKeeper:: getZooKeeperName() const {
    return zooKeeperName;
}

void ZooKeeper::assignToEnclosure(Enclosure* enclosure){
    Enclosure** newEnclosures = new Enclosure*[numOfAssignedEnclosures + 1];
    for (int i = 0; i < numOfAssignedEnclosures; i++) {
        newEnclosures[i] = this->assingedEnclosures[i];
    }
    newEnclosures[numOfAssignedEnclosures] = enclosure;
    delete[] this->assingedEnclosures;
    this->assingedEnclosures = newEnclosures;
    numOfAssignedEnclosures++;
}

void ZooKeeper:: setZooKeeperName(char* zooKeeperName) { 
    delete[] this->zooKeeperName;

    this->zooKeeperName = new char[strlen(zooKeeperName) + 1];
    if(this->zooKeeperName == NULL) {
        return;
    }
    strcpy(this->zooKeeperName, zooKeeperName);
}

void ZooKeeper:: displayZooKeepers() const {
    cout << "Zoo keeper name: " << this->getZooKeeperName() << endl;
    cout << "Assignd enclosures: " << endl;
    for(int i = 0; i < numOfAssignedEnclosures; i++) {
        this->assingedEnclosures[i]->printDetails();
    }
    cout << endl;
}

int ZooKeeper:: getNumOfAssigndEnclosures() const {
    return numOfAssignedEnclosures;
}

Enclosure** ZooKeeper::getAssignedEnclosures() const {
    return assingedEnclosures;
}

