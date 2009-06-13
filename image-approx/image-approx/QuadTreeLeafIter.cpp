#include "QuadTreeLeafIter.h"

QuadTreeLeafIter::QuadTreeLeafIter()
{
    assert(false);

}
void QuadTreeLeafIter::agregar(QuadTree * q){
    if(!q->isLeaf()){
     agregar(q->getNO());
     agregar(q->getNE());
     agregar(q->getSO());
     agregar(q->getSE());
    }else{
        list->append(q);
    }
}

