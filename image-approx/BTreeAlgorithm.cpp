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
	assert(false);//TODO
	return btree;
}
bool BTreeAlgorithm::invariante()const{
	assert(false);//TODO
	return true;

}
void BTreeAlgorithm::exec(BTree *bt){
	assert(false);//TODO

}
