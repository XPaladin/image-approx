#ifndef MAXINTENSITYDIFMINAGAINSTMAX_H_
#define MAXINTENSITYDIFMINAGAINSTMAX_H_

#include "MaxDifIntensityCriterio.h"
#include "PriorityQueue.h"

class MaxDifIntensityIgnoreCriterio : public MaxDifIntensityCriterio
{
protected:
	int excludingPercent;

	virtual unsigned char diferencia(const Rectangle::Rectangle rec)const;
public:

	MaxDifIntensityIgnoreCriterio(Image *image, int max_dif,
			int excluding_percent):MaxDifIntensityCriterio(image,max_dif){

			excludingPercent=excluding_percent;

	    }
	virtual ~MaxDifIntensityIgnoreCriterio(){}

};

#endif /*MAXINTENSITYDIFMINAGAINSTMAX_H_*/
