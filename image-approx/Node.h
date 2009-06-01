#ifndef NODE_H
#define NODE_H

#include <assert.h>

template <class T>
class Node
{
private:
    Node()
    {
        assert(false);
    }
protected:
    T val;
    Node *next;

public:
    Node(T v){
        val=v;
        next=0;
    }

    void setNext(Node<T> *n){
        next=n;
    }

    Node<T> * getNext(){
        return next;
    }

    T getVal(){
        return val;
    }

};

#endif // NODE_H
