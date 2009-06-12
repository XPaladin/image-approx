/*
 * QuadTree.h
 *
 *  Created on: 01-05-2009
 *      Author: Pablo
 */

#ifndef QUADTREEALGORITHM_H_
#define QUADTREEALGORITHM_H_

#include "Algorithm.h"
#include "QuadTree.h"
#include "DivisionStrategy.h"

#include <assert.h>

class QuadTreeAlgorithm: public Algorithm {
protected:
	QuadTree *qtree;
	int minSize;
	DivisionStrategy *divStrat;
    virtual bool invariante()const;
    void exec(QuadTree * qdt);
/*
private:
        QuadTreeAlgorithm();
        */
public:

        QuadTreeAlgorithm(Criterio *crit,int h,int w,int _minSize);
	virtual ~QuadTreeAlgorithm();
        virtual QuadTree* exec();
};

#endif /* QUADTREEALGORITHM_H_ */
