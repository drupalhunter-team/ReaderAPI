#include <stdio.h>
#include <memory.h>
#include "liblistener.h"

class MyProvider : public IProvider {
public:
	int open(){ printf("open\n");}
	int getData(short *buffer,int *length){ 
	short x[2] = {8,3};
	memcpy(buffer,x,sizeof(short)*2);
	*length = 2;
	
	printf("getData\n");}

};

class Mylistener : public IEventListener {
public:
	int started(){
		printf("started\n");
	}
	
	int done(){
		printf("done\n");
	
	}
	
	int found(){
		printf("found\n");
	
	}


};
int main(){
	MyProvider provider;
	Mylistener listener;
	ReaderService::getInstance().addProvider(&provider);
 	ReaderService::getInstance().addEventListener(&listener);
 	ReaderService::getInstance().init();	
 	ReaderService::getInstance().start();	
}
