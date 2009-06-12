#ifndef MAXVARINTENSITYCRITERIO_H_
#define MAXVARINTENSITYCRITERIO_H_

#include "IntensityCriterio.h"

class MaxVarIntensityCriterio : public IntensityCriterio
{
protected:
	float maxVar;
	MaxVarIntensityCriterio(){};
	bool invariante();
	double varianza(const Rectangle::Rectangle r)const;
public:
	MaxVarIntensityCriterio(Image *image, float max_var):IntensityCriterio(img){
		maxVar=max_var;

    }
	virtual ~MaxVarIntensityCriterio(){};
	virtual bool cumple(const Rectangle::Rectangle r)const;

};

#endif /*MAXVARINTENSITYCRITERIO_H_*/
