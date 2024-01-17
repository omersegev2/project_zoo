#include "Zoo.hpp"

const int MAX_NAME_LENGTH = 100;  
const int MAX_SPECIES_LENGTH = 100;  
const int MAX_ENCLOSURE_LENGTH = 100;  
const int MAX_ZOOKEEPER_LENGHT = 100; 

int printMenu();
int main() {
    Zoo* zoo = new Zoo();

    char* AnimalName = nullptr;
    char* AnimalSpecies = nullptr;
    char* Enclosure = nullptr;
    char* zooKeeperName = nullptr;

    cout << endl;
    cout << "PAY ATTENTION!" << endl;
    cout << "1. If enclosure is empty, he will be deleted automatically." << endl; 
    cout << "2. If you add animal to enclosure that doesn't exist, it will create a new enclosure automatically." << endl;
    cout << "3. Every animal has different name!!! Not possible to give the same name for to different animals." << endl;
    cout << endl;
    while (1) {
        switch (printMenu()) {
            case 1:
                AnimalName = new char[MAX_NAME_LENGTH];
                AnimalSpecies = new char[MAX_SPECIES_LENGTH];
                int AnimalAge;
                Enclosure = new char[MAX_ENCLOSURE_LENGTH];

                cout << "Enter animal name: ";
                cin >> AnimalName;
                cout << "Enter species: ";
                cin >> AnimalSpecies;
                cout << "Enter age: ";
                cin >> AnimalAge;
                cout << "Enter an Enclosure: ";
                cin >> Enclosure;
                cout << endl;

                zoo->addAnimalToZoo(AnimalName, AnimalSpecies, AnimalAge, Enclosure);

                delete[] AnimalName;
                delete[] AnimalSpecies;
                delete[] Enclosure;                
                break;

            case 2:
                AnimalName = new char[MAX_NAME_LENGTH];
                cout << "Enter animal name to delete: ";
                cin >> AnimalName;
                cout << endl;

                zoo->removeAnimalFromZoo(AnimalName);
                delete [] AnimalName;
                break;

            case 3:
                zoo->displayAllanimals();
                break;

            case 4:
                zooKeeperName = new char[MAX_ZOOKEEPER_LENGHT];
                Enclosure = new char[MAX_ENCLOSURE_LENGTH];

                cout << "Enter zoo keeper name: ";
                cin >> zooKeeperName;
                cout << "Enter enclosure: ";
                cin >> Enclosure;
                
                zoo->assignZookeeper(zooKeeperName, Enclosure);

                delete[] zooKeeperName;
                delete[] Enclosure;
                break;
            
            case 5:
                delete zoo;
                break;

            default:
                cout << "Invalid choice, TRY AGAIN!: " << endl;
                break;
        }
    }

    return 0;
}


int printMenu() {
    cout << "MENU:" << endl;
    cout << "1. Add an animal." << endl;
    cout << "2. Remove an animal." << endl;
    cout << "3. Display all animals." << endl;
    cout << "4. Add zoo keeper." << endl;
    cout << "5. exit." << endl;
    cout << "Please choose: ";

    int choice;
    cin >> choice;
    cout << endl;
    return choice;
}
