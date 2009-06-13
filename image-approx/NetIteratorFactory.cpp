#include "NetIteratorFactory.h"

NetIteratorFactory* NetIteratorFactory::instance=0;
NetIteratorFactory::NetIteratorFactory()
{
}


NetIteratorFactory::~NetIteratorFactory()
{
}
NetIteratorFactory* NetIteratorFactory::getInstance(){
        if(instance==0)
		instance=new NetIteratorFactory();
	return instance;
}

NetIterator *NetIteratorFactory::createNetIterator(Net* net){

	if((dynamic_cast<BTree *>( net ))!=0){
		return new BTreeIter((BTree*)net);
	}
	if((dynamic_cast<QuadTree *>( net ))!=0){
		return new QuadTreeIter((QuadTree*)net);
	}
	return 0;
}

NetIterator *NetIteratorFactory::createNetLeafIterator(Net* net){

	if((dynamic_cast<BTree *>( net ))!=0){
		return new BTreeLeafIter((BTree*)net);
	}
	if((dynamic_cast<QuadTree *>( net ))!=0){
		return new QuadTreeLeafIter((QuadTree*)net);
	}
	return 0;
}
