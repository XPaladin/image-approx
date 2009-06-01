#ifndef MAXINTENSITYDIFMINAGAINSTMAX_H_
#define MAXINTENSITYDIFMINAGAINSTMAX_H_

#include "IntensityCriterio.h"

class MaxIntensityDifMinAgainstMax : public IntensityCriterio
{
protected:
	int maxDif;
	float excludingPercent;
	MaxIntensityDifMinAgainstMax();
public:

	MaxIntensityDifMinAgainstMax(Image *image, int max_dif, float excluding_percent):IntensityCriterio(img){
			maxDif=max_dif;
			excludingPercent=excluding_percent;

	    }
	virtual ~MaxIntensityDifMinAgainstMax();
	virtual bool cumple(const Rectangle::Rectangle r);
};

#endif /*MAXINTENSITYDIFMINAGAINSTMAX_H_*/
