/**
 * @author Omer Segev
 * @ID 313772295
 * 
*/
#include "Zoo.hpp"

void menu();

int main()
{
    int choice = 10, age = 0;
    string name, species, id;
    Zoo *zoo = new Zoo();

    cout << endl;
    cout << "Welcome to the Zoo!" << endl;
    cout << "--------------------" << endl;

    while (choice != 0)
    {
        menu();
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 0:
            delete zoo;
            exit(0);
            break;
        case 1:
            cout << "Enter animal name: ";
            cin >> name;
            cout << "Enter animal species: ";
            cin >> species;
            cout << "Enter animal age: ";
            cin >> age;
            zoo->addAnimal(name, species, age);
            break;
        case 2:
            cout << "Enter animal name: ";
            cin >> name;
            cout << "Enter animal species: ";
            cin >> species;
            zoo->removeAnimal(name);
            break;
        case 3:
            zoo->displayZoo();
            break;
        case 4:
            cout << "Enter keeper name: ";
            cin >> name;
            cout << "Enter enclosure: ";
            cin >> id;
            zoo->assignZooKeeper(name, id);
            break;
        default:
            cout << endl;
            cout << "Invalid choice, please try again " << endl;
            cout << endl;
            menu();
            cin >> choice;
            break;
        }
        cout << endl;
    }
}
void menu()
{
    cout << "Menu options: " << endl;
    cout << "0. Exit" << endl;
    cout << "1. Add Animal to the zoo" << endl;
    cout << "2. Remove Animal from the zoo" << endl;
    cout << "3. display all the Animals" << endl;
    cout << "4. Allocation of Zoo keeper to the enclosure" << endl;
    cout << "Please enter your choice: ";
}
