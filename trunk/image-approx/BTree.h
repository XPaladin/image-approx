#ifndef BTREE_H_
#define BTREE_H_

#include "Rectangle.h"
#include <assert.h>
#include "net.h"


class BTree : public Net
{
protected:
    Rectangle::Rectangle rectangle;
    BTree *Next[2];
    virtual bool invariante()const;

public:
	BTree();
	virtual ~BTree();
	BTree(Rectangle::Rectangle _rect);
	Rectangle::Rectangle getRectangle() const;
	//Rectangle::Rectangle* getPRectangle(){return &rectangle;}
	void divide(const Point P, const bool horizontal);
	bool isLeaf()const;
	BTree *son(int number);
};

#endif /*BTREE_H_*/
