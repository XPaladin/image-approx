/*
 * Rectangle.h
 *
 *  Created on: 01-05-2009
 *      Author: Pablo
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Point.h"
#include "Shape.h"
#include <assert.h>

class Rectangle :
        public Shape {
protected:
    Point NE;
    Point SO;
    virtual bool invariante()const;
public:
    Rectangle(Point _SO,Point _NE);
    Rectangle();
    virtual ~Rectangle();
    void calcColor(Image * img);
    virtual Rectangle* clone()const;
    int width() const;
    int height() const;
    virtual bool operator==(const Rectangle r) const;
    virtual bool operator!=(const Rectangle r) const;
    virtual bool operator>(const Rectangle r) const;
    virtual bool operator>=(const Rectangle r) const;
    virtual bool operator<(const Rectangle r) const;
    virtual bool operator<=(const Rectangle r) const;
    virtual Point getSO() const;
    virtual Point getNE() const;
    virtual Point getSE() const;
    virtual Point getNO() const;

    virtual void draw(Image *img)const;
    virtual void fill(Image *img)const;
};

#endif /* RECTANGLE_H_ */
