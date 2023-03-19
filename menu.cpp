#include <iostream>
#include "menu.h"

using std::cout;
using std::cin;

void Menu::menu() {

    cout << "Hello, if you want to create a subset of integers, write yes" << "\n";

    std::string message;
    cin >> message;
    if (message != "Yes" and message != "yes") {
        cout << "Ok, bye";
        return;
    }

    cout << "What is the maximum number of elements in your subset?" << "\n";
    int size;
    cin >> size;
    Set subset(size);
    cout << "Subset crated" << "\n";

    int operation;
    while (true) {
        cout << "\n\n";
        cout << "What you gon do next? Type the number of operation" << "\n";
        cout << "1. Add element to subset" << "\n"
             << "2. Remove element from subset" << "\n"
             << "3. Check if element exists in subset" << "\n"
             << "4. Get the intersection of your subset with another" << "\n"
             << "5. Get the union of your subset with another" << "\n"
             << "6. Add elements contained in another subset" << "\n"
             << "7. Remove elements contained in another subset" << "\n"
             << "8. Print the subset" << "\n"
             << "9. Stop the program" << "\n\n";

        cin >> operation;

        if (operation < 1 or operation > 9) {
            cout << "You just had to enter a number from 1 to 9.. I'll give you a chance to improve" << "\n";
            continue;
        }

        if (operation == 9) {
            cout << "Bye!" << "\n";
            break;
        }

        if (operation == 1) {
            if (subset.getIter() == size) {
                cout << "There is maximum number of elements in the subset, you can't add another one" << "\n";
                continue;
            }
            cout << "Enter the integer you want to add" << "\n";
            int elem;
            cin >> elem;
            if (subset.add(elem)) {
                cout << "Element added" << "\n";
            } else {
                cout << elem << " already exists in the subset" << "\n";
            }
            continue;
        }

        if (operation == 2) {
            if (subset.getIter() == 0){
                cout << "The subset is empty, you can't remove the element" << "\n";
                continue;
            }
            cout << "Enter the element you want to remove from subset" << "\n";
            int elem;
            cin >> elem;
            if (subset.remove(elem)) {
                cout << "Element removed" << "\n";
            } else {
                cout << "There is no " << elem << " in the subset" << "\n";
            }
            continue;
        }

        if (operation == 3) {
            cout << "Enter the element you want to check" << "\n";
            int elem;
            cin >> elem;
            if (subset.search(elem) == -1) {
                cout << "There is no " << elem << " in the subset" << "\n";
            } else {
                cout << elem << " exists in the subset";
            }
            continue;
        }

        if (operation == 4) {
            cout << "How many elements in the subset you want to get the intersection with?" << "\n";
            int setSize;
            cin >> setSize;
            Set newSet(setSize);

            cout << "Enter elements of this subset" << "\n";
            for (int i = 0; i < setSize; i++) {
                int elem;
                cin >> elem;
                newSet.add(elem);
            }

            Set intersect;
            intersect = subset.intersectionOfSets(newSet);

            cout << "Here is the intersection:" << "\n\n";
            intersect.print();

            continue;
        }

        if (operation == 5) {
            cout << "How many elements in the subset you want to get the union with?" << "\n";
            int setSize;
            cin >> setSize;
            Set newSet(setSize);

            cout << "Enter elements of this subset" << "\n";
            for (int i = 0; i < setSize; i++) {
                int elem;
                cin >> elem;
                newSet.add(elem);
            }

            Set unionOfSets;
            unionOfSets = subset.unionOfSets(newSet);

            cout << "Here is the union:" << "\n\n";
            unionOfSets.print();

            continue;
        }

        if (operation == 6) {
            cout << "How many elements in the subset, which you want to add elements in your subset from?" << "\n";
            int setSize;
            cin >> setSize;
            Set newSet(setSize);

            cout << "Enter elements of this subset" << "\n";
            for (int i = 0; i < setSize; i++) {
                int elem;
                cin >> elem;
                newSet.add(elem);
            }

            if (subset.addElementsWhichInAnotherSet(newSet)) {
                cout << "Your subset is updated" << "\n";
            } else {
                cout << "Your subset has all the elements that you added to the additional subset" << "\n";
            }

            continue;
        }

        if (operation == 7) {
            cout
                    << "How many elements in the subset, that will contain the elements that will be removed from your subset?"
                    << "\n";
            int setSize;
            cin >> setSize;
            Set newSet(setSize);

            cout << "Enter elements of this subset" << "\n";
            for (int i = 0; i < setSize; i++) {
                int elem;
                cin >> elem;
                newSet.add(elem);
            }

            if (subset.removeElementsWhichInAnotherSet(newSet)) {
                cout << "Your subset is updated" << "\n";
            } else {
                cout << "Your subset has no elements which the additional has" << "\n";
            }

            continue;
        }

        if (operation == 8) {
            cout << "Here is your subset:" << "\n\n";
            subset.print();
        }

    }
}