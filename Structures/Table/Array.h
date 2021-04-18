//
// Created by Luka Mitrović on 04/03/2021.
//

#ifndef SDIZO_ARRAY_H
#define SDIZO_ARRAY_H

#include <string>

class Array {
private:
    int *array;
    int size;
public:
    ////Constructors
    Array();
    explicit Array(int size);
    ~Array();

    ////Adding functions
    void push_back(int value);
    void push_front(int value);
    void push(int position, int value);

    //// Deleting functions
    void pop_back(); // TODO; Add realisation
    void pop_front(); // TODO; Add realisation
    void pop(); // TODO; Add realisation

    int* find(int value); // TODO; Add realisation


    bool is_empty() const;
    int getSize() const;
    std::string outPutString(); // For printing in the UI

    //// Operatots
    bool operator==(const Array& newInstance) const;
    bool operator!=(const Array& newInstance) const;
    int& operator[](int value) const ;


};





#endif //SDIZO_ARRAY_H
