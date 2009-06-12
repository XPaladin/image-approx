#include "MaxVarIntensityCriterio.h"


bool MaxVarIntensityCriterio::cumple(const Rectangle::Rectangle rec)const{
	assert( rec.getSO().getX()>=0 &&
			rec.getSO().getY()>=0 &&
			rec.getNE().getX()<=img->width() &&
			rec.getNE().getY()<=img->height()
	);
	return varianza(rec)>maxVar;
}
double MaxVarIntensityCriterio::varianza(const Rectangle::Rectangle rec)const{
	double n = 0.0;
	double mean = 0.0;
	double M2 = 0.0;
	double delta;
	unsigned char intensity;
	for(int i=rec.getSO().getX();
	i<rec.getNE().getX();
	i++){
		for(int j=rec.getSO().getY();
		j<rec.getNE().getY();
		j++){
			intensity=img->intensity(i,j);
			n = n + 1;
			delta = intensity - mean;
			mean = mean + delta/n;
			M2 = M2 + delta*(intensity - mean);
		}
	}
	return M2/n;
}
