#include "QuadTreeIter.h"


QuadTreeIter::QuadTreeIter()
{
    assert(false);

}
QuadTreeIter::QuadTreeIter(QuadTree *_qt){
    qt=_qt;
    list=new List<QuadTree *>();
}
bool QuadTreeIter::isDone(){
    return list->isDone();
}
void QuadTreeIter::next(){
    list->next();
}
void QuadTreeIter::first(){
    agregar(qt);
    list->first();


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
