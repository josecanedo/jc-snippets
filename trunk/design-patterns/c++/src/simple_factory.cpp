#include <iostream>
#include <string>

class Pizza{
public:
	virtual void prepare()=0;
	virtual void bake()=0;
	virtual void cut()=0;
	virtual void box()=0;
};

class CheesePizza: public Pizza{
public:
	void prepare(){std::cout << "Preparing Cheese Pizza" << std::endl;};
	void bake	(){std::cout << "baking 200C 30Min" << std::endl;};
	void cut	(){std::cout << "8x cutting" << std::endl;};
	void box	(){std::cout << "std boxing" << std::endl;};
};

class PepperoniPizza: public Pizza{
public:
	void prepare(){std::cout << "Preparing Pepperoni Pizza" << std::endl;};
	void bake	(){std::cout << "baking 180C 35Min" << std::endl;};
	void cut	(){std::cout << "sq cutting" << std::endl;};
	void box	(){std::cout << "std boxing" << std::endl;};
};

class VeggiePizza: public Pizza{
public:
	void prepare(){std::cout << "Preparing Veggie Pizza" << std::endl;};
	void bake	(){std::cout << "baking 200C 32Min" << std::endl;};
	void cut	(){std::cout << "4x cutting" << std::endl;};
	void box	(){std::cout << "special boxing" << std::endl;};
};

class SimplePizzaFactory{
public:
	Pizza* createPizza(const std::string& type){
		Pizza* pizza = NULL;
		if(type == "cheese") pizza = new CheesePizza();
		else if(type == "pepperoni") pizza = new PepperoniPizza();
		else if(type == "veggie") pizza = new VeggiePizza();
		return pizza;
	};
};

class PizzaStore{
public:
	PizzaStore(SimplePizzaFactory* factory): factory_(factory){;};
	~PizzaStore(){delete factory_;};
	Pizza* orderPizza(const std::string& type){
		Pizza* pizza = factory_->createPizza(type); //ignore erros
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
		return pizza;
	};
private:
	SimplePizzaFactory* factory_;
};

int inner_main(int argc, char * argv[])
{
	std::cout << "simple inner main" << std::endl;
	SimplePizzaFactory* factory = new SimplePizzaFactory();
	PizzaStore* store = new PizzaStore(factory);

	Pizza* pizza1 = store->orderPizza("cheese");
	Pizza* pizza2 = store->orderPizza("pepperoni");
	Pizza* pizza3 = store->orderPizza("veggie");

	delete pizza1;
	delete pizza2;
	delete pizza3;
	delete store;
	return 0;
}