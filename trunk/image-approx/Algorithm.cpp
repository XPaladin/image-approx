/*
 * Algoritmo.cpp
 *
 *  Created on: 01-05-2009
 *      Author: Pablo
 */

#include "Algorithm.h"

Algorithm::Algorithm() {
	assert(false);

}

Algorithm::~Algorithm() {
	delete criterio;
}
Algorithm::Algorithm(Criterio *crit){
    assert(crit!=0);
    criterio=crit;
}
bool Algorithm::invariante()const{
    return criterio!=0;
}

