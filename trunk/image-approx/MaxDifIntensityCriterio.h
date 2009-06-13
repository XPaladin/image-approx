#ifndef MAXDIFINTENSITYCRITERIO_H
#define MAXDIFINTENSITYCRITERIO_H

#include "IntensityCriterio.h"
#include <stdlib.h>
#include <assert.h>

class MaxDifIntensityCriterio : public IntensityCriterio
{
protected:
    int maxDif;
    bool invariante();
    virtual unsigned char diferencia(const Rectangle::Rectangle rec)const;
public:
    MaxDifIntensityCriterio(Image *img, int max_dif);
    virtual bool cumple(const Rectangle::Rectangle rec)const;
};

#endif // MAXDIFINTENSITYCRITERIO_H
