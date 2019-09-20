//
// Created by alexander on 18.09.2019.
//

#ifndef UNTITLED_ARRAYLIST_H
#define UNTITLED_ARRAYLIST_H


template <typename T>
class ArrayList {
private:
    T *array;
    int size;
    int lastElementIndex;
public:
    ArrayList();
    ArrayList(int);
    ~ArrayList();
    void add(T);
    T get(int);
    int getSize();
    void toString();
};


#endif //UNTITLED_ARRAYLIST_H
