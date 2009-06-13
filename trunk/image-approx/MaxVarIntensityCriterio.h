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
		virtual int betterChoice(const Rectangle::Rectangle recs[],
				const Rectangle::Rectangle recs2[], int n);
        MaxVarIntensityCriterio(Image *image, int max_var):IntensityCriterio(image){
		maxVar=max_var;

    }
	virtual ~MaxVarIntensityCriterio(){}
	virtual bool cumple(const Rectangle::Rectangle r)const;

};

#endif /*MAXVARINTENSITYCRITERIO_H_*/
