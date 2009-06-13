/*
 * QuadTree.h
 *
 *  Created on: 01-05-2009
 *      Author: Pablo
 */

#ifndef QUADTREE_H_
#define QUADTREE_H_

#include "Rectangle.h"
#include <assert.h>
#include "net.h"


class QuadTree: public Net{
protected:
    Rectangle::Rectangle rectangle;
    QuadTree *NO;
    QuadTree *NE;
    QuadTree *SO;
    QuadTree *SE;
    virtual bool invariante()const;
public:
    QuadTree();
    virtual ~QuadTree();
    QuadTree(Rectangle::Rectangle _rect);
    Rectangle::Rectangle getRectangle() const;
   // Rectangle::Rectangle* getPRectangle(){return &rectangle;}
    void divide(const Point P);
    bool isLeaf()const;
    QuadTree *getNO()const;
    QuadTree *getNE()const;
    QuadTree *getSO()const;
    QuadTree *getSE()const;

};

#endif /* QUADTREE_H_ */
