/*
 * QuadTree.cpp
 *
 *  Created on: 01-05-2009
 *      Author: Pablo
 */

#include "QuadTree.h"
#include <stdio.h>

QuadTree::QuadTree() {
    NO=0;
    NE=0;
    SO=0;
    SE=0;
    assert(invariante());
}
QuadTree::QuadTree(Rectangle _rectangle) {
    rectangle = _rectangle;
    NO=0;
    NE=0;
    SO=0;
    SE=0;
    assert(invariante());
}

QuadTree::~QuadTree() {

    delete NO;
    delete NE;
    delete SO;
    delete SE;
    NO=0;
    NE=0;
    SO=0;
    SE=0;


}
bool QuadTree::isLeaf()const{
    assert(invariante());
    return NO==0;
}
Rectangle QuadTree::getRectangle() const{
	return rectangle;
}
void QuadTree::divide(const Point p){
    assert(invariante()&&
           p.getX()>rectangle.getSO().getX() &&
           p.getX()<rectangle.getNE().getX() &&
           p.getY()>rectangle.getSO().getY() &&
           p.getY()<rectangle.getNE().getY() );
    if(NO!=0 || NE!=0 || SO!=0 || SE!=0) return;
    SO = new QuadTree(Rectangle(rectangle.getSO(),p));
    NE = new QuadTree(Rectangle(p,rectangle.getNE()));
    NO = new QuadTree(Rectangle(SO->getRectangle().getNO(),NE->getRectangle().getNO()));
    SE = new QuadTree(Rectangle(SO->getRectangle().getSE(),NE->getRectangle().getSE()));
    assert(invariante());
  //  printf("Dividi\n");

}
QuadTree *QuadTree::getNO()const{
    return NO;
}
QuadTree *QuadTree::getNE()const{
    return NE;
}
QuadTree *QuadTree::getSO()const{
    return SO;
}
QuadTree *QuadTree::getSE()const{
    return SE;
}
bool QuadTree::invariante()const{
        // Que si existe un hijo, deben existir todos
        //if(rectangle==0)return false;
	if(NO==0 && NE==0 && SO==0 && SE==0) return true;
	if(NO==0 || NE==0 || SO==0 || SE==0) return false;


	//Que esten contenidos en el padre
        if(!(( rectangle > NO->rectangle  &&
            rectangle > NE->rectangle  &&
            rectangle > SO->rectangle &&
            rectangle > SE->rectangle) )){
            printf("rectangulos fuera\n");
            return false;
        }
	// Esten efectivamente su posicion
        if(!(( rectangle.getNO() == NO->rectangle.getNO() ) &&
            ( rectangle.getNE() == NE->rectangle.getNE() ) &&
            ( rectangle.getSO() == SO->rectangle.getSO() ) &&
            ( rectangle.getSE() == SE->rectangle.getSE() ) )){
                printf("rectangulos en otro lado\n");
                return false;
            }
	//Cubran completamente el rectangulo
        if(!(( NO->rectangle.getSE() == SE->rectangle.getNO() ) &&
            ( NE->rectangle.getSO() == SO->rectangle.getNE() ) &&
            ( NO->rectangle.getSE() == SO->rectangle.getNE() )) ){
            printf("medio no compartido\n");
            return false;
        }
        return true;

}
