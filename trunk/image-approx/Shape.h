#ifndef SHAPE_H
#define SHAPE_H

#include "Image.h"

class Shape
{
protected:
	unsigned char rgb[3];
public:
    Shape();
    void setColor(const unsigned char color[3]);
    virtual char *getColorCode()const;
    virtual void draw(Image *img)const=0;
    virtual void fill(Image *img)const=0;
    virtual int width() const=0;
    virtual int height() const=0;
    virtual void calcColor(Image * img)=0;
};

#endif // SHAPE_H
