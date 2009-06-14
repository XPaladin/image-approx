#include "paintwidget.h"

PaintWidget::PaintWidget(Image *img,  QWidget* parent) : QGLWidget(parent)
{
    iter=0;
    showMalla=true;
    showAprox=false;
    image=img;
    data= QImage(image->width(),image->height(),QImage::Format_RGB32);
    resize(data.size());
}
void PaintWidget::setIterator(NetIterator *_iter){
        iter=_iter;
}

void PaintWidget::paintGL()
{
	Image *img=new Image(image->getImage(),image->width(),image->height());
	if(iter!=0 && (showAprox || showMalla)){
		for(iter->first();!iter->isDone();iter->next()){
			Shape *shape=iter->currentItem();
			if(showAprox){
				shape->calcColor(image);
				shape->fill(img);
			}
                        if(showMalla){
                                unsigned char negro[3]={0,0,0};
                                shape->setColor(negro);
                                shape->draw(img);
                        }
			delete shape;
		}

	}
    //QPainter paint(this);
	for(int i=0;i<img->height();i++){
		for(int j=0;j<img->width();j++){
			data.setPixel( j, i,
					qRgb(  img->getRed(j,i),
						   img->getGreen(j,i),
						   img->getBlue(j,i)));
		}
	}

	gldata = QGLWidget::convertToGLFormat(data);

    glDrawPixels(data.width(), data.height(), GL_RGBA, GL_UNSIGNED_BYTE, gldata.bits());

}
void PaintWidget::resizeGL(int w, int h)
{
    glViewport (0, 0, w, h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w,0,h,-1,1);
    glMatrixMode (GL_MODELVIEW);
}

/*
int main(int argc, char** argv)
{
 if(argc < 2)
   return -1;
 QApplication app(argc, argv);
 PaintWidget pw(argv[1]);
 app.setMainWidget(&pw);
 pw.show();
 return app.exec();
}
*/
