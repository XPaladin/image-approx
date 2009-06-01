/*
 * EquiDivisionStrategy.cpp
 *
 *  Created on: 01-05-2009
 *      Author: Pablo
 */

#include "EquiDivisionStrategy.h"

EquiDivisionStrategy::EquiDivisionStrategy() {


}

EquiDivisionStrategy::~EquiDivisionStrategy() {

}
Point EquiDivisionStrategy::divide(const Rectangle r)const{
        return Point( ( r.getNE().getX()+r.getSO().getX() )/2,
                        (r.getNE().getY()+r.getSO().getY() )/2);

}
