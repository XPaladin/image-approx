#include "BTreeAlgorithm.h"

BTreeAlgorithm::BTreeAlgorithm()
{
	assert(false);
}

BTreeAlgorithm::~BTreeAlgorithm()
{
	delete btree;
	delete divStrat;
}
BTreeAlgorithm::BTreeAlgorithm(Criterio *crit,int h,int w,int _minSize):Algorithm(crit){
	minSize=_minSize;
	btree=new BTree(Rectangle(Point(0,0),Point(h,w)));
	divStrat=new EquiDivisionStrategy();
}
BTree* BTreeAlgorithm::exec(){
	assert(invariante()&&Algorithm::invariante());

	exec(btree);

	assert(invariante()&&Algorithm::invariante());

	return btree;
}
bool BTreeAlgorithm::invariante()const{
	assert(false);//TODO
	return true;

}
void BTreeAlgorithm::exec(BTree *bt){
	 if(bt->getRectangle().width()<=minSize ||
	       bt->getRectangle().height()<=minSize){
	       //     printf("No dividi :(");
	    	return;

	    }

	    assert(bt->isLeaf());

	    bool far=criterio->cumple(bt->getRectangle());

	    if(far){

	        Point p=divStrat->divide(bt->getRectangle());
	        Rectangle recs[2];

	        recs[0]=Rectangle(bt->getRectangle().getSE(),Point(
	        		bt->getRectangle().getNO().getX(),p.getY()));

	        recs[1]=Rectangle(bt->getRectangle().getSE(),Point(p.getY(),
	        		bt->getRectangle().getNO().getY()));

	        Rectangle recs2[2];

	        recs[0]=Rectangle(Point(bt->getRectangle().getSE().getX(),
	        		p.getY()),
	        		bt->getRectangle().getNO());

	        recs[1]=Rectangle(Point(p.getX(),
	        		bt->getRectangle().getSE().getY()),
	        		bt->getRectangle().getNO());

	        bt->divide(p,
	        		criterio->betterChoice(recs,recs2,2)==0);

	        assert(!bt->isLeaf());
	        assert(bt->son(0)->isLeaf());

	        exec(bt->son(0));
	        exec(bt->son(1));


	    }else{
	    	//   printf("No dividi :(");
	    }

}
