#ifndef BTREELEAFITER_H_
#define BTREELEAFITER_H_

#include "BTreeIter.h"

class BTreeLeafIter : public BTreeIter
{
protected:
	BTreeLeafIter();
	virtual void agregar(BTree *bt);
public:
	BTreeLeafIter(BTree *b):BTreeIter(b){}

	virtual ~BTreeLeafIter();
};

#endif /*BTREELEAFITER_H_*/
