#include "AlgorithmFactory.h"

AlgorithmFactory* AlgorithmFactory::instance=0;
AlgorithmFactory::AlgorithmFactory()
{
}


AlgorithmFactory::~AlgorithmFactory()
{
}
AlgorithmFactory* AlgorithmFactory::getInstance(){
	if(instance=0)
		instance=new AlgorithmFactory();
	return instance;
}
Algorithm *AlgorithmFactory::createAlgorithm(AlgorithmEnum type,
		Criterio* crit,
    	int w,int h,int minSize){
	switch(type){
	case QUADTREE:
		return new QuadTreeAlgorithm(crit,
    	w, h, minSize);
	case BTREE:
		return new BTreeAlgorithm(crit,
				w, h, minSize);

    default: return new QuadTreeAlgorithm(crit,
        	w, h, minSize);
	}

}
