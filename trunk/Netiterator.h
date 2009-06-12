#ifndef NETITERATOR_H
#define NETITERATOR_H

#include "net.h"
#include "Shape.h"

class NetIterator
{
public:
    NetIterator();
    virtual void first()=0;
    virtual void next()=0;
    virtual bool isDone()=0;
    virtual Shape* currentItem()const=0;
};

#endif // NETITERATOR_H
