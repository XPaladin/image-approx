#ifndef ALGORITHMFACTORY_H_
#define ALGORITHMFACTORY_H_

#include "Algorithm.h"
#include "QuadTreeAlgorithm.h"
#include "BTreeAlgorithm.h"
#include "Criterio.h"
class AlgorithmFactory
{
protected:
	static AlgorithmFactory *instance;
	AlgorithmFactory();
public:
	enum AlgorithmEnum {QUADTREE, BTREE};
	static AlgorithmFactory* getInstance();
	virtual ~AlgorithmFactory();
	virtual Algorithm *createAlgorithm(AlgorithmEnum type,
			Criterio* crit,
    		int w,int h,int minSize);
};

#endif /*ALGORITHMFACTORY_H_*/
