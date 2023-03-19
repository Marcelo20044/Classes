#include <algorithm>
#include <iostream>
#include "menu.h"

bool Set::add(int x) {
    if (search(x) == -1 and iter != size) {
        array[iter] = x;
        iter++;
        return true;
    }
    return false;
}

int Set::search(int x) {
    for (int i = 0; i < iter; i++) {
        if (array[i] == x) {
            return i;
        }
    }
    return -1;
}

bool Set::remove(int x) {
    int pos = search(x);

    if (pos != -1) {
        int *newArr = new int[size];
        iter--;

        for (int i = 0; i < iter; i++) {
            if (i < pos) {
                newArr[i] = array[i];
            } else {
                newArr[i] = array[i + 1];
            }
        }
        array = newArr;
        return true;
    }
    return false;
}

Set &Set::intersectionOfSets(Set &set) {
    int newSize = std::max(size, set.size);
    Set *intersectionSet = new Set(newSize);

    for (int i = 0; i < size; i++) {
        int elem = array[i];
        if (set.search(elem) >= 0) {
            intersectionSet->add(elem);
        }
    }
    return *intersectionSet;
}

Set &Set::unionOfSets(Set &set) {
    int newSize = size + set.size;
    Set *unionSet = new Set(newSize);

    for (int i = 0; i < size; i++) {
        int elem = array[i];
        if (unionSet->search(elem) == -1) {
            unionSet->add(elem);
        }
    }

    for (int i = 0; i < set.size; i++) {
        int elem = set.array[i];
        if (unionSet->search(elem) == -1) {
            unionSet->add(elem);
        }
    }
    return *unionSet;
}

bool Set::addElementsWhichInAnotherSet(Set &set) {
    bool flag = false;
    for (int i = 0; i < set.size; i++) {
        if (add(set.array[i])) {
            flag = true;
        }
    }
    return flag;
}

bool Set::removeElementsWhichInAnotherSet(Set &set) {
    bool flag = false;
    for (int i = 0; i < set.size; i++) {
        if (remove(set.array[i])) {
            flag = true;
        } else {
            continue;
        }
    }
    return flag;
}

void Set::print() {
    if (iter == 0) {
        std::cout << "The subset is empty";
    } else {
        for (int i = 0; i < iter; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << "\n";
    }
}


