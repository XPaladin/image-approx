#ifndef NETSAVER_H_
#define NETSAVER_H_

#include "NetIterator.h"

class NetSaver
{
protected:
	static NetSaver *instance;
	NetSaver();
public:
	static NetSaver* getInstance();

	virtual bool save(NetIterator * it,Image *img, char filename[]);

	virtual ~NetSaver();
};

#endif /*NETSAVER_H_*/
