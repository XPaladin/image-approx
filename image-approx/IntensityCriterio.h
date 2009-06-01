#ifndef INTENSITYCRITERIO_H
#define INTENSITYCRITERIO_H

#include "Image.h"
#include "Criterio.h"
class IntensityCriterio : public Criterio
{
protected:
    Image *img;
    IntensityCriterio(){assert(false);};
    virtual bool invariante(){return img!=0;}
public:
    IntensityCriterio(Image *image){
    	assert(img!=0);
        img=image;
    }
    virtual bool cumple(const Rectangle::Rectangle r){assert(false);}


};

#endif // INTENSITYCRITERIO_H
