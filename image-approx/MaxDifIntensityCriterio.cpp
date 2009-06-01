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
bool MaxDifIntensityCriterio::cumple(const Rectangle::Rectangle rec)const{
	assert( rec.getSO().getX()>=0 &&
			rec.getSO().getY()>=0 &&
			rec.getNE().getX()<=img->width() &&
			rec.getNE().getY()<=img->height()
			);
    char intensity1,intensity2;
    for(int i=rec.getSO().getX();
        i<rec.getNE().getX();
        i++){
    	for(int j=rec.getSO().getY();
    		j<rec.getNE().getY();
    		j++){
            intensity1=img->intensity(i,j);
            for(int ii=rec.getSO().getX();
                ii<rec.getNE().getX();
                ii++){
                for(int jj=rec.getSO().getY();
                    jj<rec.getNE().getY();
                    jj++){
                    intensity2=img->intensity(ii,jj);
                   // float d=distance(rgb1,rgb2);
                   // if(d>0)printf("d=%f\n",d);
                    if(abs(intensity1-intensity2)>maxDif){
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

