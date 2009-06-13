#ifndef CRITERIOFACTORY_H_
#define CRITERIOFACTORY_H_

#include "Criterio.h"
#include "IntensityCriterio.h"
#include "MaxDifIntensityCriterio.h"
#include "MaxVarIntensityCriterio.h"
#include "MaxDifIntensityIgnoreCriterio.h"

class CriterioFactory
{
protected:
	CriterioFactory(){};
public:
	enum CriterioEnum {MAX_DIF, MAX_DIF_IGNORE_PERCENT, MAX_VAR};

	virtual ~CriterioFactory(){};
	static Criterio * createCriterio(CriterioEnum type, Image* image,
			int max, int ignore);
};

#endif /*CRITERIOFACTORY_H_*/
