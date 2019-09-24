//
// Created by alexander on 18.09.2019.
//

#include "ArrayList.h"
#include <iostream>

using namespace std;

template<typename T>
ArrayList<T>::ArrayList() {
    size = 10;
    array = new T[size];
    lastElementIndex = -1;
}

template<typename T>
ArrayList<T>::ArrayList(int size) {
    size = size > 0 ? size : 10;

    this->size = size;
    array = new T[size];
    lastElementIndex = -1;

}

template<typename T>
ArrayList<T>::~ArrayList() {
    size = lastElementIndex = 0;
    delete[] array;
}

template<typename T>
void ArrayList<T>::add(T item) {
    if (++lastElementIndex >= size) {
        cout << "SIZE" << endl;
        T *newArray = new T[size + 10];

        for (int i = 0; i < this->size; ++i) {
            newArray[i] = array[i];
        }

        newArray[lastElementIndex] = item;
        this->array = newArray;
        this->size = size + 10;
    } else {
        array[lastElementIndex] = item;
    }
}

template<typename T>
T ArrayList<T>::get(int index) {
    if (index >= 0 && index <= lastElementIndex) {
        return array[index];
    }

    return nullptr;
}

template <typename T>
void ArrayList<T>::set(int index, T object) {
    if (index >= 0 && index < size) {
        array[index] = object;
    }
}

template<typename T>
int ArrayList<T>::getSize() {
    return size;
}

template <typename T>
void ArrayList<T>::toString() {
    cout << "[";
    for (int i = 0; i < size - 1; ++i) {
        cout << array[i] << ", ";
    }

    cout << array[size - 1] << "]" << endl;
}
