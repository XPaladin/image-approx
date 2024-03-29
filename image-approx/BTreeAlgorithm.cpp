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
BTreeAlgorithm::BTreeAlgorithm(Criterio *crit,int w,int h,int _minSize):Algorithm(crit){
	minSize=_minSize;
	btree=new BTree(Rectangle(Point(0,0),Point(w,h)));
	divStrat=new EquiDivisionStrategy();
}
BTree* BTreeAlgorithm::exec(){
	assert(invariante()&&Algorithm::invariante());

	exec(btree);

	assert(invariante()&&Algorithm::invariante());

	return btree;
}
bool BTreeAlgorithm::invariante()const{
        //assert(false);//TODO
	return true;

}
void BTreeAlgorithm::exec(BTree *bt){
    bool suficiente_ancho=bt->getRectangle().width()>minSize;
    bool suficiente_alto=bt->getRectangle().height()>minSize;
    if(!suficiente_ancho && !suficiente_alto ){
        //     printf("No dividi :(");
        return;

    }
    assert(suficiente_ancho || suficiente_alto);
    assert(bt->isLeaf());

	    bool far=criterio->cumple(bt->getRectangle());

	    if(far){

	        Point p=divStrat->divide(bt->getRectangle());
	        Rectangle recs[2];

                recs[0]=Rectangle(Point(bt->getRectangle().getSO().getX(),
                                p.getY()),
                                bt->getRectangle().getNE());

                recs[1]=Rectangle(bt->getRectangle().getSO(),Point(p.getX(),
                                bt->getRectangle().getNE().getY()));

	        Rectangle recs2[2];

                recs2[0]=Rectangle(bt->getRectangle().getSO(),Point(
                                bt->getRectangle().getNE().getX(),p.getY()));

                recs2[1]=Rectangle(Point(p.getX(),
                                bt->getRectangle().getSO().getY()),
                                bt->getRectangle().getNE());

                bool horizontal=criterio->betterChoice(recs,recs2,2)==0;
                if(horizontal && !suficiente_alto){
                    horizontal=false;
                    assert(suficiente_ancho);
                }
                else if(!horizontal && !suficiente_ancho){
                    horizontal=true;
                    assert(suficiente_alto);
                }
                bt->divide(p, horizontal);

	        assert(!bt->isLeaf());
	        assert(bt->son(0)->isLeaf());

	        exec(bt->son(0));
	        exec(bt->son(1));


	    }else{
	    	//   printf("No dividi :(");
	    }

}
