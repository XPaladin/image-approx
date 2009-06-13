#ifndef MAXINTENSITYDIFMINAGAINSTMAX_H_
#define MAXINTENSITYDIFMINAGAINSTMAX_H_

#include "MaxDifIntensityCriterio.h"
#include "PriorityQueue.h"

class MaxIntensityDifMinAgainstMax : public MaxDifIntensityCriterio
{
protected:
	float excludingPercent;
	MaxIntensityDifMinAgainstMax(){}
	unsigned char diferencia(const Rectangle::Rectangle rec)const;
public:

	MaxIntensityDifMinAgainstMax(Image *image, int max_dif,
			float excluding_percent):MaxDifIntensityCriterio(image,max_dif){

			excludingPercent=excluding_percent;

	    }
	virtual ~MaxIntensityDifMinAgainstMax(){}

};

#endif /*MAXINTENSITYDIFMINAGAINSTMAX_H_*/
