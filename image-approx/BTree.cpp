#include "BTree.h"

BTree::BTree()
{
}

BTree::~BTree()
{
	delete Next[0];
	delete Next[1];

}
BTree::BTree(Rectangle _rectangle) {
    rectangle = _rectangle;
    Next[0]=Next[1]=0;
    assert(invariante());
}
bool BTree::invariante()const{
        //assert(false);//TODO
	return true;
}
Rectangle::Rectangle BTree::getRectangle() const{
	return rectangle;
}
void BTree::divide(const Point P,const bool horizontal){
	assert(invariante());
	if(horizontal){
		Next[0]=new BTree(Rectangle(rectangle.getSO(),Point(rectangle.getNE().getX(),P.getY())));
		Next[1]=new BTree(Rectangle(Point(rectangle.getSO().getX(),P.getY()),rectangle.getNE()));
	}
	else{
		Next[0]=new BTree(Rectangle(rectangle.getSO(),Point(P.getX(),rectangle.getNE().getY())));
		Next[1]=new BTree(Rectangle(Point(P.getX(),rectangle.getSO().getY()),rectangle.getNE()));

	}
	assert(invariante() && !isLeaf());
}
bool BTree::isLeaf()const{
	assert(invariante());
	return Next[0]==0;
}
BTree *BTree::son(int number){
	assert(invariante()&& number>=0 && number<=1);
	return Next[number];
}
