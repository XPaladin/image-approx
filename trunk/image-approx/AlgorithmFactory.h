#ifndef ALGORITHMFACTORY_H_
#define ALGORITHMFACTORY_H_

#include "Algorithm.h"
#include "QuadTreeAlgorithm.h"
#include "BTreeAlgorithm.h"
class AlgorithmFactory
{

public:
	enum AlgorithmEnum {QUADTREE, BTREE};
	AlgorithmFactory();
	virtual ~AlgorithmFactory();
};

#endif /*ALGORITHMFACTORY_H_*/
