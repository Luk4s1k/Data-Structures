//
// Created by Luka Mitrović on 03/04/2021.
//

#include "Heap.h"
#include <cstdlib>
#include <iostream>


// Parametrized constructor gets the pointer to array from which the heap needs to be created
// Size parameter determines the size of the heap
// Property can be either MAX_HEAP or MIN_HEAP
Heap::Heap(int *array,int size, HeapProperty heapProperty)
        :heapSize(size),heapProperty(heapProperty){
    baseArray = new int[heapSize];
    if(heapProperty == MIN_HEAP) MinHeapify(baseArray[0]);
    else if(heapProperty == MAX_HEAP) MaxHeapify(baseArray[0]);
}


// Heapify the array with the property that
// Minimum key value is in the root and value of the left and right child
// Are not smaller than the parent key value
void Heap::MinHeapify(int position) {
    int l = getLeftIndex(position);
    int r = getRightIndex(position);
    int smallest;
    if((l <= this->heapSize) && (baseArray[l] < baseArray[position])){
        smallest = l;
    } else {
        smallest = position;
    }
    if((r <= this->heapSize) && (baseArray[r] < baseArray[smallest])){
        smallest = r;
    }
    if (smallest != position){
        swap(&baseArray[position], &baseArray[smallest]);
        MinHeapify(smallest);
    }

}


// Heapify the array with the property that
// Maximum key value is in the root and value of the left and right child
// Are not greater than the parent key value
void Heap::MaxHeapify(int position) {
    int l = getLeftIndex(position);
    int r = getRightIndex(position);
    int largest;
    if((l <= this->heapSize) && (baseArray[l] > baseArray[position])){
        largest = l;
    } else {
        largest = position;
    }
    if((r <= this->heapSize) && (baseArray[r] > baseArray[largest])){
        largest = r;
    }
    if (largest != position){
        swap(&baseArray[position], &baseArray[largest]);
        MinHeapify(largest);
    }
}


// Swap the values of the array
void Heap::swap(int *a, int *b) {
    int *temp = a;
    *a = *b;
    *b = *temp;
}


// Reallocates the baseArray to store 1 more element
// Adds the new element to the array
// According to the heap property checks if conditions is met after insertion
void Heap::insertKey(int value) {
    heapSize++;
    int *newArray;
    newArray = (int*)realloc(baseArray,heapSize * sizeof (int));
    baseArray= newArray;
    baseArray[heapSize - 1] = value;

    if(this->heapProperty == MIN_HEAP){
        int position = heapSize - 1;
        while (position != 0 && baseArray[getRightIndex(position)] > baseArray[position]){
            swap(&baseArray[position], &baseArray[getRightIndex(position)]);
            position = getRightIndex(position);
        }
    }else if(this->heapProperty == MAX_HEAP){
        int position = heapSize - 1;
        while (position != 0 && baseArray[getRightIndex(position)] < baseArray[position]){
            swap(&baseArray[position], &baseArray[getRightIndex(position)]);
            position = getRightIndex(position);
        }
    }
}

// In case of the minimal heap property
// Function decreases the key value to the smallest possible and extracts it as a root
// In case of the maximal heap property
// Function increases the key value to the smallest possible and extracts it as a root
void Heap::deleteKey(int position) {
    switch(heapProperty){
        case MIN_HEAP:
            modifyElement(position, INT_MIN);
            extractMin();
            break;
        case MAX_HEAP:
            modifyElement(position, INT_MAX);
            extractMax();
            break;
        default:
            std::cout << "Heap property unknown! " << std::endl;
            break;
    }
}

// Function changes the value of the element and adapts the heap for the new value
void Heap::modifyElement(int position, int newValue) {
    switch (heapProperty) {
        //-----------------------------------------------------------------------//
        case MIN_HEAP:
            // If user wants to decrease key value
            if (baseArray[position] <= newValue) {
                baseArray[position] = newValue;
                while (position != 0 && baseArray[getParentIndex(position)] > baseArray[position]) {
                    swap(&baseArray[position], &baseArray[getParentIndex(position)]);
                    position = getParentIndex(position);
                }
                // If user wants to increase the value of the element
            } else if (baseArray[position] > newValue) {
                baseArray[position] = newValue;
                MinHeapify(0); // Reheapify
            }
            break;

            //-----------------------------------------------------------------------//
        case MAX_HEAP:
            // If user wants to decrease the key value
            if (baseArray[position] <= newValue) {
                baseArray[position] = newValue;
                MaxHeapify(0); // Reheapify

                // If user wants to increase the value of the element
            } else if (baseArray[position] > newValue) {
                baseArray[position] = newValue;
                while (position != 0 && baseArray[getParentIndex(position)] < baseArray[position]) {
                    swap(&baseArray[position], &baseArray[getParentIndex(position)]);
                    position = getParentIndex(position);
                }
            }
            break;
            //-----------------------------------------------------------------------//
        default:
            std::cout << "Heap property unknown! " << std::endl;
            break;

    }
}

// Remove the minimal element of the heap
// According to the heap property it either return the root (MIN_HEAP)
// or finds the minimal element and returns it (MAX_HEAP)
int Heap::extractMin() {
    //-----------------------------------------------------------------------//
    if(heapProperty == MIN_HEAP){
        // If heap is empty return the minimal integer value and given a warning
        if(heapSize <= 0){
            std::cout << "There are no elements in the heap" << std::endl;
            return INT_MIN;
        }
        // If heap has only one element it is the smallest value
        // so the function return the root
        if(heapSize == 1){
            heapSize --;
            return baseArray[0];
        }
        int minimumElement = baseArray[0]; // minimum element is a root
        baseArray[0] = baseArray[heapSize - 1]; // now leaf is a root
        heapSize--;

        return minimumElement;
        //-----------------------------------------------------------------------//
    }else if (heapProperty == MAX_HEAP){
        // Start from the leaf
        int minimumElement = baseArray[heapSize - 1];

        // Comparing all elements from the end of array
        for (int position = heapSize - 1; position >= 0; --position){
            if(baseArray[position] < minimumElement)
                minimumElement = baseArray[position];
        }

        return minimumElement;
    }
    //-----------------------------------------------------------------------//
}

// Remove the maximum element of the heap
// According to the heap property it either return the root (MAX_HEAP)
// or finds the minimal element and returns it (MIN_HEAP)
int Heap::extractMax() {
    //-----------------------------------------------------------------------//
    if(heapProperty == MAX_HEAP){
        // If heap is empty return the maximum integer value and given a warning
        if(heapSize <= 0){
            std::cout << "There are no elements in the heap" << std::endl;
            return INT_MAX;
        }
        // If heap has only one element it is the biggest value
        // so the function return the root
        if(heapSize == 1){
            heapSize --;
            return baseArray[0];
        }
        int maximumElement = baseArray[0]; // maximum element is a root
        baseArray[0] = baseArray[heapSize - 1]; // now leaf is a root
        heapSize--;

        return maximumElement;
        //-----------------------------------------------------------------------//
    }else if (heapProperty == MIN_HEAP){
        // Start from the leaf
        int maximumElement = baseArray[heapSize - 1];

        // Comparing all elements from the end of array
        for (int position = heapSize - 1; position >= 0; --position){
            if(baseArray[position] < maximumElement)
                maximumElement = baseArray[position];
        }

        return maximumElement;
    }
    //-----------------------------------------------------------------------//
}

int Heap::getParentIndex(int position) {
    return (position - 1)/2;
}

int Heap::getLeftIndex(int position) {
    return (2*position + 1);
}

int Heap::getRightIndex(int position) {
    return (2*position + 2);
}







