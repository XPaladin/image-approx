#ifndef BTREEITER_H_
#define BTREEITER_H_

#include "Netiterator.h"
#include "BTree.h"
#include "List.h"

class BTreeIter : public NetIterator
{
protected:
	List<BTree *> *list;
	BTree * bt;
	BTreeIter();
	virtual void agregar(BTree * btree);
public:
	BTreeIter(BTree* btree);
	virtual int size()const;
	virtual bool isDone();
	virtual void next();
	virtual void first();
	virtual Rectangle::Rectangle *currentItem()const;
	virtual ~BTreeIter();
};

#endif /*BTREEITER_H_*/
