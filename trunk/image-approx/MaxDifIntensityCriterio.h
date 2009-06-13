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
	virtual int betterChoice(const Rectangle::Rectangle recs[],
			const Rectangle::Rectangle recs2[],int n);
    MaxDifIntensityCriterio(Image *img, int max_dif);
    virtual bool cumple(const Rectangle::Rectangle rec)const;
};

#endif // MAXDIFINTENSITYCRITERIO_H
