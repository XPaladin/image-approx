#ifndef MAXVARINTENSITYCRITERIO_H_
#define MAXVARINTENSITYCRITERIO_H_

#include "IntensityCriterio.h"

class MaxVarIntensityCriterio : public IntensityCriterio
{
protected:
	MaxVarIntensityCriterio(){}
	int maxVar;
	bool invariante();
	double varianza(const Rectangle::Rectangle r)const;
public:
	MaxVarIntensityCriterio(Image *image, int max_var):IntensityCriterio(img){
		maxVar=max_var;

    }
	virtual ~MaxVarIntensityCriterio(){}
	virtual bool cumple(const Rectangle::Rectangle r)const;

};

#endif /*MAXVARINTENSITYCRITERIO_H_*/
