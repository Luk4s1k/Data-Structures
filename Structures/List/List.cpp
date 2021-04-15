//
// Created by Luka Mitrović on 06/03/2021.
//

#include "List.h"
#include <iostream>

// Parametrized constructor makes a node
// which is head and a tail at the same time
// both are null pointers
// value the node is holding given value
List::List(int data){

    Node* nodePtr = (Node*)malloc(sizeof(Node));

    nodePtr->data = data;

    nodePtr->next = nullptr;
    nodePtr->previous = nullptr;

    head = nodePtr;
    tail = nodePtr;
}


// Default constructor creates
// an empty list with no Nodes
List::List(){
    head = nullptr;
    tail = nullptr;
}

// Makes the new Node a head of the list
// and previous head to point to the new Node
void List::push_front(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    newNode->previous = nullptr;

    if(head != NULL)
        head->previous = newNode ;

    head = newNode;

}

// Makes a new Node a tail of the list
// And changes the previous tail to point to new Node
void List::push_back(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = nullptr;
    newNode->previous = tail;

    tail = newNode;

}

// Inserts the element on the given position
// Checks is the given positions is not out of range
// If the position is 0 uses the push_front function
// If the position is equal to last one uses push_back function
// Otherwise uses the marker to find the pointer to the element after which
// new Node needs to be inserted
// and uses marker as argument for List::push_after(Node* previousNode, value)
void List::push_after(int position, int value) {

    if(position < 0 || position >= Length){
        std::cout << "Error: Out of range exception!\n";
        return; //TODO: exception throw

    }else if(position == 0){
        this->push_front(value);

    }else if(position == (Length - 1)){
        this->push_back(value);

    }else{
        Node* marker = this->head;
        // Make marker to point the Node which will be before the new Node
        for (int i = 0; i < position - 1; ++i) {
            marker = marker->next;
        }
        this->push_after(marker,value);
    }

}
// Function takes the node after which the node will be inserted and a new Node value
// given Node next is now the New Node
// new Nodes previous now is a given Node
// new Nodes next is the next Node of the given Node
void List::push_after(List::Node *previousNode, int value) {
    if(previousNode == nullptr){
        std::cout << "Error: Out of range exception!\n";
        return; //TODO: exception throw
    }else if(previousNode == tail){
        this->push_back(value);
    }else{
        //Allocate memory for the new Node
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = previousNode->next;
        previousNode->next = newNode;
        newNode->previous = previousNode;

        //Make the next Node after the new one to point to new Node
        if (newNode->next != nullptr)
            newNode->next->previous = newNode;
    }
}



void List::pop_front() {
//TODO
}

void List::pop_back() {
//TODO
}

void List::pop() {
//TODO
}

// Returns the number of elements in the list
int List::length() const{
    return Length;
}
