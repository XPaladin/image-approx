#include "MaxDifIntensityIgnoreCriterio.h"


unsigned char MaxDifIntensityIgnoreCriterio::diferencia(const Rectangle::Rectangle rec)const{
	int total= rec.width()*rec.height();
	int excludes=(int)(total*excludingPercent/100.0);
	PriorityQueue minQueue=new PriorityQueue(false);
	PriorityQueue maxQueue=new PriorityQueue(true);
	unsigned char intensity;
	for(int i=rec.getSO().getX();
		i<rec.getNE().getX();
		i++){
			for(int j=rec.getSO().getY();
			j<rec.getNE().getY();
			j++){
				intensity=img->intensity(i,j);
				if(minQueue.size()<=excludes+1){
					minQueue.add(intensity);
				}
				else if(minQueue.getFirst()>intensity){
					minQueue.extract();
					minQueue.add(intensity);
				}
				if(maxQueue.size()<=excludes+1){
					maxQueue.add(intensity);
				}
				else if(maxQueue.getFirst()<intensity){
					maxQueue.extract();
					maxQueue.add(intensity);
				}
			}
	}

	return maxQueue.extract()-minQueue.extract();

}

