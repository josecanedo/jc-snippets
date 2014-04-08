#include <iostream>

class Singleton
{
public:
	virtual ~Singleton(){};
	static Singleton& getInstance(){
		//synchronize here on multithread applications
		static Singleton instance;
		return instance;
	}
private:
	Singleton(){};
	Singleton(Singleton const&);
	void operator=(Singleton const&);
};

int inner_main(int argc, char * argv[])
{
	std::cout << "singleton pattern" << std::endl;
	
	//Singleton* st = new Singleton(); //error
	Singleton& st = Singleton::getInstance(); //ok

	return 0;
}