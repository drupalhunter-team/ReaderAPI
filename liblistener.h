
class IProvider {
public:
	virtual ~IProvider(){}
	virtual int open() = 0;
	virtual int getData(short *buffer,int *length) = 0;
};


class IEventListener {
public:
	virtual ~IEventListener(){}
	virtual int started() = 0;
	virtual int done() = 0;
	virtual int found() = 0; 
};

class ReaderService {
public:
	static ReaderService& getInstance(){
	
		static ReaderService instance;
		return instance;
	
	}

	int addProvider(IProvider *provider);
	int addEventListener(IEventListener *listener);
	int init();
	int start();
	int stop();

private:
	ReaderService();
	ReaderService(const ReaderService&);
	ReaderService& operator=(const ReaderService&);
	~ReaderService();
	
	class Impl;
	Impl *pImpl;

};


