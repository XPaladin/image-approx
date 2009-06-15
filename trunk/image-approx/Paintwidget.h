#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QGLWidget>
#include "QuadTreeLeafIter.h"
#include "Image.h"

class PaintWidget : public QGLWidget
{
	Q_OBJECT
protected:
    bool showMalla;
    bool showAprox;
    NetIterator *iter;
    QImage data, gldata;
    Image * image;
public:
    PaintWidget(Image *img, QWidget* parent = 0);
    void setIterator(NetIterator *_iter);
    void paintGL();
    void resizeGL(int w, int h);
    void malla(){showMalla=!showMalla;}
    void aproximacion(){showAprox=!showAprox;}



};


#endif // PAINTWIDGET_H
