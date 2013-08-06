#include "liblistener.h"
#include <stdio.h>

class IProviderRegistory {
public:
	static IProviderRegistory& getInstance()
	{
		static IProviderRegistory instance;
		return instance;
	}
	

	void set(IProvider *provider){ p = provider; }
	IProvider *get() { return p; }
	
private:
	IProviderRegistory() : p(0) {}
	~IProviderRegistory(){
	}
	
	IProvider *p;	
	
};

class IEventListenerRegistory { 
public:
	static IEventListenerRegistory& getInstance()
	{
		static IEventListenerRegistory instance;
		return instance;
	}
	
	void set(IEventListener *listener){ p = listener; }
	IEventListener *get() { return p; }
private:
	IEventListenerRegistory(): p(0) {}
	~IEventListenerRegistory(){}

	IEventListener *p;

};
class ReaderService::Impl {
public:
	Impl(){}
	~Impl(){}
	short data[256];
	int length;
	void init(){
		 IProvider *p =  IProviderRegistory::getInstance().get();
		 if ( 0 != p )
		 {
		 	p->open();
		 }
	}

	void start(){
		
		
		IProvider *p = IProviderRegistory::getInstance().get();
		if ( 0 != p )
		{
			p->getData(data,&length);
		}
		IEventListener *listen = IEventListenerRegistory::getInstance().get();
		if ( 0 == listen )
		{
			return ;
		}	

		listen->started();
			
		for (int i = 0; i < length ; ++i)
		{
			if ( 8 == data[i])
			{
				listen->found();
			}
			
		}
	
		listen->done();	
	}
	
	void stop(){}

};

ReaderService::ReaderService(): pImpl(new ReaderService::Impl()){

}

ReaderService::~ReaderService(){

	delete pImpl;
}



 int ReaderService::addProvider(IProvider *provider){
	IProviderRegistory::getInstance().set(provider); 
	return 0; 
 }

 int ReaderService::addEventListener(IEventListener *listener){
	IEventListenerRegistory::getInstance().set(listener); 
 	return 0;
 }
 
 
 int ReaderService::init(){
 	pImpl->init();
 	return 0;
 } 
 
 int ReaderService::start(){
	pImpl->start();
	return 0; 
 }

 int ReaderService::stop(){
	pImpl->stop();
	return 0; 
 }

