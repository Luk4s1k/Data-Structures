//
// Created by Luka Mitrović on 03/04/2021.
//

#ifndef SDIZO_HEAP_H
#define SDIZO_HEAP_H
enum HeapProperty{ MIN_HEAP , MAX_HEAP};

class Heap {

    int *baseArray;                         // Array from which the heap will be created
    int heapSize;
    HeapProperty heapProperty;
public:
    Heap(int *array,int size, HeapProperty heapProperty);

    void MinHeapify(int i);
    void MaxHeapify(int i);

    void swap(int *a, int *b);
    void insertKey(int value);
    void deleteKey(int position);
    void modifyElement(int position, int newValue);

    int extractMin();
    int extractMax();


    int getParentIndex(int position);
    int getLeftIndex(int position);
    int getRightIndex(int position);

};


#endif //SDIZO_HEAP_H
