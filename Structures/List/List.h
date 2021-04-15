#include <__bit_reference>
//
// Created by Luka Mitrović on 06/03/2021.
//

#ifndef SDIZO_LIST_H
#define SDIZO_LIST_H


class List {
private:
    // Node structure that holds the value and
    // pointers to the next and previous elements of the list
    struct Node{
        int data;
        Node* previous;
        Node* next;
    };
    //Stores the number of nodes in list
    int Length;

    // Special nodes that represent the beginning and the end of the list
    // Head node has previous pointer nullptr
    // Tail node has next pointer nullptr
    Node* head;
    Node* tail;
public:

// TODO: make a copy constructor
    //// Constructors
    explicit List(int data);
    List();
    ////Adding element methods
    void push_front(int value);
    void push_back(int value);
    void push_after(int position, int value);
    void push_after(Node* previousNode, int value);

    //// Removing element methods
    void pop_front();
    void pop_back();
    void pop();

    //// Getters
    int length() const;
};


#endif //SDIZO_LIST_H
