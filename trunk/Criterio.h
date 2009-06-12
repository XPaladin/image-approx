#ifndef CRITERIO_H
#define CRITERIO_H
#include "Rectangle.h"
class Criterio
{
protected:
    Criterio(){assert(false);}
public:
    virtual bool cumple(const Rectangle::Rectangle r)const=0;
    virtual ~Criterio(){};
};

#endif // CRITERIO_H
