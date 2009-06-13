#ifndef NETITERATORFACTORY_H_
#define NETITERATORFACTORY_H_

#include "NetIterator.h"
#include "BTreeIter.h"
#include "BTreeLeafIter.h"
#include "QuadTreeIter.h"
#include "QuadTreeLeafIter.h"

class NetIteratorFactory
{
protected:
	static NetIteratorFactory *instance;
	NetIteratorFactory();
public:
	enum Iterator {QUADTREE, BTREE, LEAFQUADTREE, LEAFBTREE};
	static NetIteratorFactory* getInstance();

	virtual NetIterator *createNetIterator(Net* net);
	virtual NetIterator *createNetLeafIterator(Net* net);



	virtual ~NetIteratorFactory();
};

#endif /*NETITERATORFACTORY_H_*/
