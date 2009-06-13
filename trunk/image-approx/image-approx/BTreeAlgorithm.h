#ifndef BTREEALGORITHM_H_
#define BTREEALGORITHM_H_

#include "Algorithm.h"
#include "BTree.h"
#include "DivisionStrategy.h"
#include "EquiDivisionStrategy.h"

#include <assert.h>

class BTreeAlgorithm :
		public Algorithm{
protected:
	BTree *btree;
	int minSize;
	DivisionStrategy *divStrat;
    virtual bool invariante()const;
    void exec(BTree *bt);
    BTreeAlgorithm();
public:
        BTreeAlgorithm(Criterio *crit,int w,int h,int _minSize);
	virtual ~BTreeAlgorithm();
	virtual BTree* exec();
};
#endif /*BTREEALGORITHM_H_*/
