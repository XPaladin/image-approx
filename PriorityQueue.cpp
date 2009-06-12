#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
{
	ascendente=true;
	first=0;
	tamano=0;
}
PriorityQueue::PriorityQueue(bool asc){
	ascendente=asc;
	first=0;
	tamano=0;
}
PriorityQueue::~PriorityQueue()
{
	while(!empty)
		extract();
	first=0;
}
int PriorityQueue::getFirst(){
	return first->getVal();
}
int PriorityQueue::extract(){
        assert(!empty());
        Node<int> *aux=first;
        first=first->getNext();
        int aux2= aux->getVal();
        delete aux;
        tamano--;
        return aux2;
}
void PriorityQueue::add(int n){
	Node<int> *aux=new Node<int>(n);
	tamano++;
	if(empty()){
		first=aux;
		return;
	}
	if(first->getVal()>n*(ascendente?1:-1)){
		aux->setNext(first);
		first=aux;
	}
	Node<int> *it;
	for(it=first;it->getNext()&&
	(it->getNext()->getVal()>n*(ascendente?1:-1));
	aux->setNext(it->getNext()));

	it->setNext(aux);
}
int PriorityQueue::size()const{
	return tamano;
}
bool PriorityQueue::empty()const{
	return first==0;
}