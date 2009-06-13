/*
 * Point.cpp
 *
 *  Created on: 01-05-2009
 *      Author: Pablo
 */

#include "Point.h"

Point::Point() {
	x=0;
	y=0;
	assert(invariante());
}

Point::~Point() {
}

Point::Point(const int _x, const int _y){
	y=_y;
	x=_x;
	assert(invariante());
}
int Point::getX()const{
	assert(invariante());
	return x;
}
int Point::getY()const{
	assert(invariante());
	return y;
}
void Point::setX(const int _x){
	assert(invariante());
	x=_x;
	assert(invariante());
}
void Point::setY(const int _y){
	assert(invariante());
	y=_y;
	assert(invariante());
}
bool Point::operator==(const Point p)const{
	assert(invariante());
	return x==p.x && y==p.y;
}
bool Point::operator!=(const Point p)const{
	assert(invariante());
	return !(*this==p);
}
bool Point::invariante()const{
	return true;
}
Point * Point::clone()const{
    return new Point(x,y);
}
