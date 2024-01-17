#include "Zoo.hpp"

Zoo:: Zoo(): numOfEnclosures(0), enclosures(nullptr), numOfZooKeepers(0), zooKeepers(nullptr) { }

Zoo:: ~Zoo() { 
    delete[] enclosures;
    delete[] zooKeepers;
}

/*Function thats add a new animal to zoo.
  Animal must be in enclosure */
void Zoo:: addAnimalToZoo(const char* name, const char* species, int age, const char* enclosureName) {
     for(int j = 0; j < numOfEnclosures; j++) {
        Animal** animals = enclosures[j]->getAnimals();
        
        for(int k = 0; k < enclosures[j]->getNumOfAnimals(); k++) {
            if(strcmp(animals[k]->getAnimalName(), name) == 0) {
                cout << "ERROR: animal with this name allready exist" << endl;
                return;
            }
        }
    }
    
    Animal* newAnimal = new Animal(name, species, age);

    Enclosure* targetEnclosure = nullptr;

    for (int i = 0; i < numOfEnclosures; i++) {
        if (strcmp(enclosures[i]->getEnclosureName(), enclosureName) == 0) {
            targetEnclosure = enclosures[i];
            break;;
        }
    }

    if (targetEnclosure == nullptr) {
        targetEnclosure = new Enclosure(enclosureName);
        Enclosure** newEnclosures = new Enclosure* [numOfEnclosures + 1];
        for (int i = 0; i < numOfEnclosures; i++) {
            newEnclosures[i] = enclosures[i];
        }
        newEnclosures[numOfEnclosures] = targetEnclosure;
        delete[] enclosures;
        enclosures = newEnclosures;
        numOfEnclosures++;
        cout << "NEW ENCLOSURE CREATED!: " << enclosureName << endl;
    }

    targetEnclosure->addAnimal(newAnimal);
    cout << "Animal added successfully!" << endl << endl;
}

void Zoo:: removeAnimalFromZoo(const char* name) {
    if(numOfEnclosures < 1) {
        cout << "ERROR: animal list is empty" << endl << endl;;
    }

    for (int i = 0; i < numOfEnclosures; i++) {
        Animal** animals = enclosures[i]->getAnimals();

        for (int j = 0; j < enclosures[i]->getNumOfAnimals(); j++) {
            if (strcmp(animals[j]->getAnimalName(), name) == 0) {
                enclosures[i]->removeAnimal(animals[j]);
                if(enclosures[i]->getNumOfAnimals() == 0) {
                    delete enclosures[i];
                    
                    for (int k = i; k < numOfEnclosures - 1; k++) {
                        enclosures[k] = enclosures[k + 1];
                    }

                    numOfEnclosures--;
                    Enclosure** newEnclosures = new Enclosure* [numOfEnclosures];
                    for (int k = 0; k < numOfEnclosures; k++) {
                        newEnclosures[k] = enclosures[k];
                    }
                    delete[] enclosures;
                    enclosures = newEnclosures;
                }
                cout << "Animal removed successfully!" << endl <<endl;
                return;
            }
        }
    }

    cout << "Animal with name " << name << " not found in the zoo." << endl << endl;
}

void Zoo::displayAllanimals() const {
    if (numOfEnclosures < 1) {
        cout << "ERROR: animal list is empty" << endl;
    }

    for (int i = 0; i < numOfEnclosures; i++) {
        cout << endl;
        cout << i + 1 << ". ";
        this->enclosures[i]->displayAnimalsInEnclosre();
    }
    cout << endl;

    for (int j = 0; j < numOfZooKeepers; j++) {
        cout << "Zoo keeper: " << zooKeepers[j]->getZooKeeperName() << endl;
        cout << "Assignd enclosures: " << endl;

        Enclosure** assignedEnclosures = zooKeepers[j]->getAssignedEnclosures();
        for (int k = 0; k < zooKeepers[j]->getNumOfAssigndEnclosures(); k++) {
            cout << " - " << assignedEnclosures[k]->getEnclosureName();
        }
        cout << endl; 
    }
}


void Zoo:: assignZookeeper(const char* zooKeeperName, const char* enclosureName) {
    ZooKeeper* newZooKeeper = new ZooKeeper(zooKeeperName);


}


