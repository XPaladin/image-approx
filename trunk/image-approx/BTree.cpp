#include "BTree.h"
#include <stdio.h>

BTree::BTree()
{
    assert(false);
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
    //si uno es nulo, ambos lo son
    if(Next[0]==0)
        return Next[1]==0;
    //ambos hijos esten dentro del padre
    if(
            Next[0]->getRectangle()>rectangle ||
            Next[1]->getRectangle()>rectangle
            ){
        printf("ambos hijos esten dentro del padre\n");
        return false;
    }
    //los hijos esten en el orden adecuado
    if(
            Next[0]->getRectangle().getSO().getX() >
            Next[1]->getRectangle().getSO().getX() ||
            Next[0]->getRectangle().getSO().getY() <
            Next[1]->getRectangle().getSO().getY()
            ){
        printf("los hijos esten en el orden adecuado\n");
        return false;
    }
    //cubran al padre
    if(!(
            //horizontal
            ( Next[0]->getRectangle().getNE()==rectangle.getNE() &&
              Next[1]->getRectangle().getSO()==rectangle.getSO() &&
              Next[0]->getRectangle().getSO() == Next[1]->getRectangle().getNO() &&
              Next[0]->getRectangle().getSE() == Next[1]->getRectangle().getNE() ) ||
            //vertical
            ( Next[0]->getRectangle().getSO()==rectangle.getSO() &&
              Next[1]->getRectangle().getNE()==rectangle.getNE() &&
              Next[0]->getRectangle().getSE() == Next[1]->getRectangle().getSO() &&
              Next[0]->getRectangle().getNE() == Next[1]->getRectangle().getNO()
              )
            )){
        printf("cubran al padre\n");
        return false;
    }

    return true;
}
Rectangle::Rectangle BTree::getRectangle() const{
	return rectangle;
}
void BTree::divide(const Point P,const bool horizontal){
	assert(invariante());
	if(horizontal){
            Next[0]=new BTree(Rectangle(Point(rectangle.getSO().getX(),P.getY()),rectangle.getNE()));
            Next[1]=new BTree(Rectangle(rectangle.getSO(),Point(rectangle.getNE().getX(),P.getY())));

	}
	else{
            Next[0]=new BTree(Rectangle(rectangle.getSO(),Point(P.getX(),rectangle.getNE().getY())));
            Next[1]=new BTree(Rectangle(Point(P.getX(),rectangle.getSO().getY()),rectangle.getNE()));

	}
        assert(invariante());
        assert( !isLeaf());
}
bool BTree::isLeaf()const{
	assert(invariante());
	return Next[0]==0;
}
BTree *BTree::son(int number){
	assert(invariante()&& number>=0 && number<=1);
	return Next[number];
}
