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
    virtual void agregar(QuadTree * quad);
public:
	virtual bool isDone();
    virtual void next();
    virtual void first();
    virtual int size()const;
    virtual Rectangle::Rectangle *currentItem()const;
    QuadTreeIter(QuadTree *);
    virtual ~QuadTreeIter();
};

#endif // QUADTREEITER_H
