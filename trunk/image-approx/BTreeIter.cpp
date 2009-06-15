#include "BTreeIter.h"

BTreeIter::BTreeIter()
{
	assert(false);
}

BTreeIter::~BTreeIter()
{
	delete list;
}

BTreeIter::BTreeIter(BTree *btree){
    bt=btree;
    list=new List<BTree *>();
}
bool BTreeIter::isDone(){
    return list->isDone();
}
void BTreeIter::next(){
    list->next();
}
void BTreeIter::first(){
    agregar(bt);
    list->first();


}
int BTreeIter::size()const{
    return list->size();
}

Rectangle * BTreeIter::currentItem()const{
    return list->currentItem()->getRectangle().clone();
}

void BTreeIter::agregar(BTree * bt){
    if(!bt->isLeaf()){
     agregar(bt->son(0));
     agregar(bt->son(1));

    }
    list->append(bt);
}
