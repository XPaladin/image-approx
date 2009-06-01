#include "Rectangle.h"
/*
 * DivisionStrategy.h
 *
 *  Created on: 01-05-2009
 *      Author: Pablo
 */

#ifndef DIVISIONSTRATEGY_H_
#define DIVISIONSTRATEGY_H_


class DivisionStrategy {
public:
	DivisionStrategy();
	virtual ~DivisionStrategy();
	//retorna el punto con que se divide el rectangulo en 4 rectangulos
        virtual Point divide(const Rectangle::Rectangle r)const=0;
};

#endif /* DIVISIONSTRATEGY_H_ */
