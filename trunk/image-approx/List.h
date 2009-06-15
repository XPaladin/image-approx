#ifndef LIST_H
#define LIST_H
#include "Node.h"

template <class T>
class List
{
protected:
    Node<T> *f;
    Node<T> *l;
    Node<T> *curr;
    int tamano;
public:
	List(){
		curr=f=l=0;
		tamano=0;
	}
	void append(T t){
		Node<T> *aux=new Node<T>(t);
        if(empty()){
            f=aux;
        }else{
            l->setNext(aux);
        }
        l=aux;
        tamano++;

    };

	void first(){
		curr=f;
	}
	void next(){
		assert(!isDone());
		curr=curr->getNext();
	}
	T currentItem(){
		return curr->getVal();
	}
	bool isDone(){
		return curr==0;
	}
	int size()const{
		return tamano;
	}
	bool empty()const{
		return tamano==0;
	}
	virtual ~List(){
		Node<T> *aux=f;
		Node<T> *aux2;
		while(aux->getNext()!=0){
			aux2=aux->getNext();
			delete aux;
			aux=aux2;
		}
		delete aux;
		f=l=curr=0;
		tamano=0;
	}
};

#endif // LIST_H
