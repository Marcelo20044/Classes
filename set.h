#ifndef LABA2PLUSI_SET_H
#define LABA2PLUSI_SET_H

class Set {
private:
    int size;
    int *array;
    int iter;

public:
    Set(int setSize) {      //constructor with parameter
        size = setSize;
        iter = 0;
        array = new int[size];
    }

    Set() {           //default constructor
        size = 0;
        iter = 0;
        array = nullptr;
    }

    Set(Set &sample) {            //copy constructor
        size = sample.size;
        if (sample.array == nullptr) {
            array = nullptr;
        } else {
            array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = sample.array[i];
            }
        }
    }

    Set &operator=(const Set &set) {         //operator = overload
        if (this == &set) {
            return *this;
        }

        delete[] array;
        if (set.array != nullptr) {
            size = set.size;
            iter = set.iter;
            array = new int[size];

            for (int i = 0; i < iter; i++) {
                array[i] = set.array[i];
            }
        } else {
            array = nullptr;
        }

        return *this;
    }

    ~Set() {            //destructor
        delete[] array;
    }

    int getIter() const {        //getter for iter
        return iter;
    }

    bool add(int);

    int search(int);

    bool remove(int);

    Set &intersectionOfSets(Set &);

    Set &unionOfSets(Set &);

    bool addElementsWhichInAnotherSet(Set &);

    bool removeElementsWhichInAnotherSet(Set &);

    void print();

};

#endif
