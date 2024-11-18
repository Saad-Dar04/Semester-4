#include<iostream>
using namespace std;


template <typename T>
class AbstractStack {
protected:
    int currentSize;
    int maxSize;
    T* arr;
public:
    // constructor for stack
    AbstractStack(int maxSize) : currentSize(0), maxSize(maxSize) {
        // dynamic allocation of memory and commencing array with null values
        arr = new T[this->maxSize]{};
    };

    // pure virtual funcitons
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;

    // virtual function for destructor , read more about it
    // virtual destructor comes in handy when freeing up memory by using the baseclass pointer
    // first the derived class(jis ka object assign kiya hae ) and then the base class ka destructor is called
    // making sure that memory is appropriately freed up
    virtual ~AbstractStack() {
        // freeing up dynamically allocated memory
       // cout << "Abstract Stack destructor has been called" << endl;
        delete[] arr;
    }
};


