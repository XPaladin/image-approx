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
public:
	List(){
		curr=f=l=0;
	}
	void append(T t){
		Node<T> *aux=new Node<T>(t);
        if(empty()){
            f=aux;
        }else{
            l->setNext(aux);
        }
        l=aux;

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
	bool empty(){
		return f==0;
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
	}
};

#endif // LIST_H
