#include "MaxDifIntensityCriterio.h"
#include <stdio.h>

MaxDifIntensityCriterio::MaxDifIntensityCriterio(Image *img, int max_dif):IntensityCriterio(img)
{
	assert(max_dif>0);
    maxDif=max_dif;
}
bool MaxDifIntensityCriterio::invariante(){
	return IntensityCriterio::invariante() && maxDif>0;
}
unsigned char MaxDifIntensityCriterio::diferencia(const Rectangle rec)const{
	unsigned char intensity;
	unsigned char max=0;
	unsigned char min=255;
	for(int i=rec.getSO().getX();
	i<rec.getNE().getX();
	i++){
		for(int j=rec.getSO().getY();
		j<rec.getNE().getY();
		j++){
			intensity=img->intensity(i,j);
			if(intensity>max)max=intensity;
			if(intensity<min)min=intensity;
		}
	}
	return max-min;

}
bool MaxDifIntensityCriterio::cumple(const Rectangle rec)const{
	assert( rec.getSO().getX()>=0 &&
			rec.getSO().getY()>=0 &&
			rec.getNE().getX()<=img->width() &&
			rec.getNE().getY()<=img->height()
			);

    return diferencia(rec)>maxDif;

}
int MaxDifIntensityCriterio::betterChoice(
		const Rectangle::Rectangle recs[],
		const Rectangle::Rectangle recs2[],
		int n){
	double minDif, difAct;
	int minIndex=0;
	minDif=diferencia(recs[0])+diferencia(recs2[0]);
	for(int i=1;i<n;i++){
		difAct=diferencia(recs[i])+diferencia(recs2[i]);
		if(difAct<minDif){
			minIndex=i;
			minDif=difAct;
		}
	}
	return minIndex;
}
