#include <iostream>

class FlyBehaviour
{
public:
	virtual void fly()=0;
	virtual ~FlyBehaviour(){};
};

class FlyWithWings: public FlyBehaviour
{
public:
	virtual void fly(){
		std::cout << "fly with wings" << std::endl;
	}
};

class FlyNoWay: public FlyBehaviour{
public:
	virtual void fly(){
		std::cout << "can't fly" << std::endl;
	}
};

class FlyRocketPowered: public FlyBehaviour{
public:
	virtual void fly(){
		std::cout << "flying with rocket!" << std::endl;
	}
};


class QuackBehaviour
{
public:
	virtual void quack()=0;
	virtual ~QuackBehaviour(){};
};

class Quack: public QuackBehaviour{
public:
	virtual void quack(){
		std::cout << "quack" << std::endl;
	}
};

class Squeak: public QuackBehaviour{
public:
	virtual void quack(){
		std::cout << "squeak" << std::endl;
	}
};

class Duck{
public:
	void swim(){std::cout << "float" << std::endl;};
	virtual void display()=0;
	void performQuack(){_quackBehaviour->quack();};
	void performFly(){_flyBehaviour->fly();};
	void setFlyBehaviour(FlyBehaviour *flyBehaviour){_flyBehaviour = flyBehaviour;}; //TODO avoid memory leak
	void setQuackBehaviour(QuackBehaviour *quackBehaviour){_quackBehaviour = quackBehaviour;}; //TODO avoid memory leak
	virtual ~Duck(){}; //delete behaviours
private:
	FlyBehaviour *_flyBehaviour;
	QuackBehaviour *_quackBehaviour;
};

class MallardDuck: public Duck{
public:
	MallardDuck(){
		setFlyBehaviour(new FlyWithWings());
		setQuackBehaviour(new Quack());
	};
	virtual void display(){std::cout << "mallard duck" << std::endl;};
};

class RubberDuck: public Duck{
public:
	RubberDuck(){
		setFlyBehaviour(new FlyNoWay());
		setQuackBehaviour(new Squeak());
	};
	virtual void display(){std::cout << "rubber duck" << std::endl;};
};

int inner_main(int argc, char * argv[])
{
	std::cout << "strategy pattern" << std::endl;
	
	Duck *mallard = new MallardDuck();
	mallard->display();
	mallard->performQuack();
	mallard->performFly();

	Duck *rubber = new RubberDuck();
	rubber->display();
	rubber->performFly();
	rubber->setFlyBehaviour(new FlyRocketPowered());
	rubber->performFly();

	return 0;
}