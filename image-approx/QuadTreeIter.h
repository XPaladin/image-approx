#ifndef QUADTREEITER_H
#define QUADTREEITER_H
#include "List.h"
#include "QuadTree.h"
#include "Rectangle.h"
#include "NetIterator.h"

class QuadTreeIter : public NetIterator
{
protected:
    List<QuadTree *> *list;
    QuadTree * qt;
    QuadTreeIter();
    void agregar(QuadTree * quad);
public:
    bool isDone();
    void next();
    void first();
    Rectangle::Rectangle * currentItem()const;
    QuadTreeIter(QuadTree *);
};

#endif // QUADTREEITER_H
