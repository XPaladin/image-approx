#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <class T>
class Queue
{
protected:
    Node<T> *first;
    Node<T> *last;
public:
    Queue(){
        first=last=0;
    }

    void add(T t){
        Node<T> *aux=new Node<T>(t);
        if(empty()){
            first=aux;
        }else{
            last->setNext(aux);
        }
        last=aux;

    }
    T extract(){
        assert(!empty());
        Node<T> *aux=first;
        if(first==last){
            last=0;
        }
        first=first->getNext();
        T aux2= aux->getVal();
        delete aux;
        return aux2;
    }
    bool empty(){
        return first==0;
    }

};

#endif // QUEUE_H
