/*
 * EquiDivisionStrategy.h
 *
 *  Created on: 01-05-2009
 *      Author: Pablo
 */

#ifndef EQUIDIVISIONSTRATEGY_H_
#define EQUIDIVISIONSTRATEGY_H_

#include "DivisionStrategy.h"

class EquiDivisionStrategy: public DivisionStrategy {
public:
	EquiDivisionStrategy();
	virtual ~EquiDivisionStrategy();
	virtual Point divide(const Rectangle::Rectangle r)const;
};

#endif /* EQUIDIVISIONSTRATEGY_H_ */
