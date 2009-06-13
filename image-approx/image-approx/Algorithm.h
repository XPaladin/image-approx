/*
 * Algoritmo.h
 *
 *  Created on: 01-05-2009
 *      Author: Pablo
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include <assert.h>
#include "net.h"
#include "Criterio.h"

class Algorithm {
protected:
    Criterio *criterio;
    virtual bool invariante()const;
    Algorithm();
public:
    Algorithm(Criterio *crit);
    virtual ~Algorithm();
    virtual Net * exec()=0;

};

#endif /* ALGORITHM_H_ */
