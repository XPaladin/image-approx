#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <class V>
class Stack{
protected:
    Node<V> *nTop;
 //   bool invariante();
public:
       Stack()
    {
        nTop=0;
    }

    V top()const{
        assert(!isEmpty());
        return nTop->getVal();
    }

    void pop(){
        assert(!isEmpty());
        Node<V> * aux=nTop;
        nTop=nTop->getNext();
        delete aux;
    }

    void push(V t){
        Node<V> *aux=new Node<V>(t);
        if(!isEmpty()){
            aux->setNext(nTop);
        }
        nTop=aux;


    }

    bool isEmpty()const{
        return nTop==0;

    }


};

#endif // STACK_H
