/*
 * QuadTree.cpp
 *
 *  Created on: 01-05-2009
 *      Author: Pablo
 */

#include "QuadTreeAlgorithm.h"
#include "EquiDivisionStrategy.h"
#include "Util.h"

QuadTreeAlgorithm::QuadTreeAlgorithm(Criterio *crit, int w,
                                     int h,int _minSize):Algorithm(crit){
        //assert(_minSize>0&&_maxDif>0&&Algorithm::invariante());

//        preImgFileName=_imageFileName;

    minSize = _minSize;
    qtree = new QuadTree(
                Rectangle(Point(0,0),
                      Point(w,h)));
    divStrat=new EquiDivisionStrategy();
    assert(invariante()&&Algorithm::invariante());

}

QuadTreeAlgorithm::~QuadTreeAlgorithm() {
	delete qtree;
}
bool QuadTreeAlgorithm::invariante()const {
        return(minSize>0 && Algorithm::invariante());

}
QuadTree* QuadTreeAlgorithm::exec(){
    assert(invariante()&&Algorithm::invariante());

    exec(qtree);

    assert(invariante()&&Algorithm::invariante());

    return qtree;

}
void QuadTreeAlgorithm::exec(QuadTree * qdt){
    //        qdt->getPRectangle()->setColor(average(pre,qdt->getRectangle()));

    //printf("depth=%d\n",pre.depth());

    if(qdt->getRectangle().width()<=minSize ||
       qdt->getRectangle().height()<=minSize){
       //     printf("No dividi :(");
    	return;

    }

    assert(qdt->isLeaf());

    bool far=criterio->cumple(qdt->getRectangle());

    if(far){

        Point p=divStrat->divide(qdt->getRectangle());

        qdt->divide(p);
        assert(!qdt->isLeaf());
        assert(qdt->getNO()->isLeaf());

        exec(qdt->getNO());
        exec(qdt->getNE());
        exec(qdt->getSO());
        exec(qdt->getSE());


    }else{
    	//   printf("No dividi :(");
    }

}


