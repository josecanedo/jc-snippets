#include <iostream>
#include <string>

//beverage is our abstract component class
class Beverage{
public:
	Beverage():description_("Abstract Blend"){};
	virtual ~Beverage(){};
	virtual std::string getDescription(){return description_;};
	virtual float cost()=0;
protected:
	std::string description_;
};

//four contrete components (coffee types)
class HouseBlend: public Beverage{
public:
	HouseBlend(){description_ = "House Blend";};
	~HouseBlend(){};
	float cost(){return 0.89f;};
};

class DarkRoast: public Beverage{
public:
	DarkRoast(){description_ = "Dark Roast";};
	~DarkRoast(){};
	float cost(){return 1.20f;};
};

class Espresso: public Beverage{
public:
	Espresso(){description_ = "Espresso";};
	~Espresso(){};
	float cost(){return 1.99f;};
};

class Decaf: public Beverage{
public:
	Decaf(){description_ = "Decaf";};
	~Decaf(){};
	float cost(){return 2.00f;};
};

//our abstract decorator
class CondimentDecorator: public Beverage{
public:
	CondimentDecorator(Beverage* beverage){beverage_ = beverage;};
	virtual ~CondimentDecorator(){};
protected:
	Beverage* beverage_;
};

//our decorators
class Milk: public CondimentDecorator{
public:
	Milk(Beverage* beverage): CondimentDecorator(beverage){};
	~Milk(){delete beverage_;};
	float cost(){return 1.00f + beverage_->cost();};
	std::string getDescription(){return beverage_->getDescription() + std::string(", Milk");};
};

class Mocha: public CondimentDecorator{
public:
	Mocha(Beverage* beverage): CondimentDecorator(beverage){};
	~Mocha(){delete beverage_;};
	float cost(){return 0.20f + beverage_->cost();};
	std::string getDescription(){return beverage_->getDescription() + std::string(", Mocha");};
};

class Soy: public CondimentDecorator{
public:
	Soy(Beverage* beverage): CondimentDecorator(beverage){};
	~Soy(){delete beverage_;};
	float cost(){return 0.30f + beverage_->cost();};
	std::string getDescription(){return beverage_->getDescription() + std::string(", Soy");};
};

class Whip: public CondimentDecorator{
public:
	Whip(Beverage* beverage): CondimentDecorator(beverage){};
	~Whip(){delete beverage_;};
	float cost(){return 0.75f + beverage_->cost();};
	std::string getDescription(){return beverage_->getDescription() + std::string(", Whip");};
};

int inner_main(int argc, char * argv[])
{
	std::cout << "Decorator" << std::endl;

	Beverage* bev = new Espresso();
	std::cout << "Desc: " << bev->getDescription() << " Price: " << bev->cost() << std::endl;
	delete bev;

	bev = new DarkRoast();
	bev = new Mocha(bev);
	bev = new Mocha(bev);
	bev = new Whip(bev);
	std::cout << "Desc: " << bev->getDescription() << " Price: " << bev->cost() << std::endl;
	delete bev;

	bev = new HouseBlend();
	bev = new Soy(bev);
	bev = new Mocha(bev);
	bev = new Whip(bev);
	std::cout << "Desc: " << bev->getDescription() << " Price: " << bev->cost() << std::endl;

	return 0;
}