#include "QuadTreeIter.h"


QuadTreeIter::QuadTreeIter()
{
    assert(false);

}
QuadTreeIter::QuadTreeIter(QuadTree *_qt){
	assert(_qt!=0);
    qt=_qt;
    list=new List<QuadTree *>();
}
QuadTreeIter::~QuadTreeIter(){
	if(list!=0)
    delete list;
}
bool QuadTreeIter::isDone(){
    return list->isDone();
}
void QuadTreeIter::next(){
	assert(!isDone());
    list->next();
}
void QuadTreeIter::first(){
    agregar(qt);
    list->first();


}
int QuadTreeIter::size()const{
	return list->size();
}
Rectangle * QuadTreeIter::currentItem()const{
    return list->currentItem()->getRectangle().clone();
}

void QuadTreeIter::agregar(QuadTree * q){
    if(!q->isLeaf()){
     agregar(q->getNO());
     agregar(q->getNE());
     agregar(q->getSO());
     agregar(q->getSE());
    }
    list->append(q);
}
