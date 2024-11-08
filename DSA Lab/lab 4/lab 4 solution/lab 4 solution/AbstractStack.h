#include<iostream>
using namespace std;

template <typename T>
class AbstractClass {
protected:
    int currentSize;
    int maxSize;
    T* arr;
public:
    // constructor for stack
    AbstractClass(int maxSize) : currentSize(0) {
        // dynamic allocation of memory and commencing array with null values
        arr = new T[maxSize]{};
    };

    // pure virtual funcitons
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    
    // virtual function for destructor , read more about it
    virtual ~AbstractStack() {}
};