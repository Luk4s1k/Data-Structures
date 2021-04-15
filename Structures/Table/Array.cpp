//
// Created by Luka Mitrović on 04/03/2021.
//
#include "Array.h"
#include <iostream>

Array::Array(int size) :
        size(size),array(new int[size]){
    for (int i = 0; i < size; ++i) {
        array[i] = 0;
    }
}

Array::~Array() {
    delete [] array;
}

// Returns 0 if the array is empty
// Returns 1 if array has at least 1 element
bool Array::is_empty() const{
    return size == 0;
}

// Reallocates memory for array with bigger size
// copies all the array data to new memory
// rewrites the pointer
// adds given value to the end of the new array
void Array::push_back(int value) {
    size++;
    int *newArray;
    newArray = (int*)realloc(array,size * sizeof (int));
    array= newArray;
    array[size - 1] = value;
}

// Returns the size of the array
int Array::getSize() const{
    return size;
}

// Reallocate memory for array with bigger size
// copy all the array data to new memory
// rewrite the pointer
// move all the elements right by 1 position
// insert the given value to the beginning
void Array::push_front(int value) { // TODO: change to smart pointers
    size++;

    int *newArray;

    newArray = (int*)realloc(array,size * sizeof (int));

    array= newArray;

    for (int i = size - 1 ; i > 0; --i) {
        array[i] = array[i - 1];
    }

    array[0] = value;
}

// TODO: check for position less than size
void Array::push(int position, int value) {
    if(position >= size || position < 0){
        return; // Todo: make and exception here
    }
        // if user is trying to insert to the beginning of array
        // function push_front is used for insertion
    else if (position == 0) {
        this->push_front(value);

        // if user is trying to insert to the end of array
        // function push_back is used for insertion
    } else if (position == (size - 1)) {
        this->push_back(value);
        //if user tries to insert in position different from and and
    } else if (position > 0 && position < size){
        size++;
        int *newArray;
        newArray = (int *) realloc(array, size * sizeof(int));
        array = newArray;
        for (int i = size - 1; i > position; --i) {
            array[i] = array[i - 1];
        }
        array[position] = value;
    }
}



int &Array::operator[](int value)const {
    return array[value];
}

std::string Array::outPutString() const {
    std::string outString = "";
    for (int i = 0; i < this->size; ++i){
        outString += this->array[i];
    }
    return std::string();
}

//bool Array::operator==(const Array &newInstance) const{
//    if (size != newInstance.getSize()){
//        return false;
//    }
//    for (int i = 0; i < size; ++i) {
//        if(array[i] != newInstance[i]){
//            return false;
//        }
//    }
//    return true;
//}
//
//bool Array::operator !=(const Array &newInstance) const{
//    return !(array == newInstance);
//}



