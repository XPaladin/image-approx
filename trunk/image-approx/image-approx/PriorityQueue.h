#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include "Node.h"
class PriorityQueue
{
protected:
	bool ascendente;
	Node<int> *first;
	int tamano;
public:
	int extract();
	int getFirst();
	PriorityQueue();
	PriorityQueue(bool asc);
	virtual ~PriorityQueue();
	void add(int n);
	int size()const;
	bool empty()const;
};

#endif /*PRIORITYQUEUE_H_*/
