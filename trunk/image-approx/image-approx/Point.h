/*
 * Point.h
 *
 *  Created on: 01-05-2009
 *      Author: Pablo
 */

#ifndef POINT_H_
#define POINT_H_

#include <assert.h>

class Point {
protected:
	int x;
	int y;
	virtual bool invariante()const;
public:
	Point();
	virtual ~Point();
	Point(const int _x, const int _y);
	int getX()const;
	int getY()const;
	void setX(const int _x);
	void setY(const int _y);
        Point *clone()const;
	virtual bool operator==(const Point)const;
	virtual bool operator!=(const Point)const;
};

#endif /* POINT_H_ */
