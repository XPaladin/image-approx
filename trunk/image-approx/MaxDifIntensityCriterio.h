#ifndef MAXDIFINTENSITYCRITERIO_H
#define MAXDIFINTENSITYCRITERIO_H

#include "IntensityCriterio.h"
#include <stdlib.h>
#include <assert.h>

class MaxDifIntensityCriterio : public IntensityCriterio
{
protected:
    int maxDif;
    MaxDifIntensityCriterio();
    bool invariante();
public:
    MaxDifIntensityCriterio(Image *img, int max_dif);
    virtual bool cumple(const Rectangle::Rectangle rec)const;
};

#endif // MAXDIFINTENSITYCRITERIO_H
