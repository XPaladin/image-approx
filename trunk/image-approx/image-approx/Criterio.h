#ifndef CRITERIO_H
#define CRITERIO_H
#include "Rectangle.h"
class Criterio
{
protected:
    Criterio(){}
public:
    virtual bool cumple(const Rectangle::Rectangle r)const=0;
    virtual ~Criterio(){};
    virtual int betterChoice(const Rectangle::Rectangle recs[],
    		const Rectangle::Rectangle recs[], int n)=0;
};

#endif // CRITERIO_H
