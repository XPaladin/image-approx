#include "NetSaver.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Rectangle.h"
using namespace std;



NetSaver* NetSaver::instance=0;
NetSaver::NetSaver()
{
}


NetSaver::~NetSaver()
{
}
NetSaver* NetSaver::getInstance(){
	if(instance==0)
		instance=new NetSaver();
	return instance;
}

bool NetSaver::save(NetIterator* it, Image *img, char filename[]){
	//printf("filename:%s\n",filename);
	ofstream myfile (filename);
	if (myfile.is_open())
	{
		it->first();
		myfile << it->size() << endl;
		for(;!it->isDone();it->next()){
			Rectangle::Rectangle * rect=(Rectangle::Rectangle *)it->currentItem();
			rect->calcColor(img);
			myfile <<
			rect->getColorCode()<<
			" ("<< rect->getSO().getX()<<
			","<<rect->getSO().getY()<<")"
			<<
			" ("<< rect->getNE().getX()<<
			","<<rect->getNE().getY()<<")"<<
			endl;
			delete rect;
		}

		myfile.close();
		return true;
	}
	else cerr << "Unable to open file";
	return false;

}
