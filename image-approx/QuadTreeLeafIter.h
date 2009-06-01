#ifndef QUADTREELEAFITER_H
#define QUADTREELEAFITER_H

#include "QuadTreeIter.h"
class QuadTreeLeafIter : public QuadTreeIter
{
protected:
    QuadTreeLeafIter();
    void agregar(QuadTree *q);
public:
    QuadTreeLeafIter(QuadTree *q):QuadTreeIter(q){}
};

#endif // QUADTREELEAFITER_H
