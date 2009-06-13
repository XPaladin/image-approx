#include "CriterioFactory.h"

Criterio * CriterioFactory::createCriterio(CriterioEnum type, Image* image,
			int max, int ignore){
	switch(type){
	case MAX_DIF:
		return new MaxDifIntensityCriterio(image, max);
	case MAX_VAR:
		return new MaxVarIntensityCriterio(image, max);
	case MAX_DIF_IGNORE_PERCENT:
		return new MaxDifIntensityIgnoreCriterio(image, max, ignore);
	default:
		return new MaxDifIntensityCriterio(image, max);
	}
}
