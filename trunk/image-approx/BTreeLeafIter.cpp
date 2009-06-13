#include "BTreeLeafIter.h"

BTreeLeafIter::BTreeLeafIter()
{
    assert(false);
}

BTreeLeafIter::~BTreeLeafIter()
{
}
void BTreeLeafIter::agregar(BTree * bt){
    if(!bt->isLeaf()){
    	agregar(bt->son(0));
    	agregar(bt->son(1));
    }else{
    	list->append(bt);
    }
}
