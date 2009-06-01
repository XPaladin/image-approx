#ifndef MAXVARINTENSITYCRITERIO_H_
#define MAXVARINTENSITYCRITERIO_H_

#include "IntensityCriterio.h"

class MaxVarIntensityCriterio : public IntensityCriterio
{
protected:
	float maxVar;
	MaxVarIntensityCriterio();
public:

	MaxVarIntensityCriterio(Image *image, float max_var):IntensityCriterio(img){
		maxVar=max_var;

    }
	virtual ~MaxVarIntensityCriterio();
	virtual bool cumple(const Rectangle::Rectangle r);

};

#endif /*MAXVARINTENSITYCRITERIO_H_*/
