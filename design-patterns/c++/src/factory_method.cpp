#include <iostream>
#include <string>

class Pizza{
public:
	Pizza(const std::string& name){name_ = name;};
	virtual void prepare()=0;
	virtual void bake()=0;
	virtual void cut()=0;
	virtual void box()=0;
	std::string getName(){return name_;};
protected:
	std::string name_;
};
//TODO move the print to base and use variables on instantiation of concrete classes
class NYCheesePizza: public Pizza{
public:
	NYCheesePizza(): Pizza("NY Cheese Pizza"){};
	void prepare(){std::cout << "Preparing NY Cheese Pizza" << std::endl;};
	void bake	(){std::cout << "baking 200C 30Min" << std::endl;};
	void cut	(){std::cout << "8x cutting" << std::endl;};
	void box	(){std::cout << "std boxing" << std::endl;};
};

class NYPepperoniPizza: public Pizza{
public:
	NYPepperoniPizza(): Pizza("NY Pepperoni Pizza"){};
	void prepare(){std::cout << "Preparing NY Pepperoni Pizza" << std::endl;};
	void bake	(){std::cout << "baking 180C 35Min" << std::endl;};
	void cut	(){std::cout << "sq cutting" << std::endl;};
	void box	(){std::cout << "std boxing" << std::endl;};
};

class NYVeggiePizza: public Pizza{
public:
	NYVeggiePizza(): Pizza("NY Veggie Pizza"){};
	void prepare(){std::cout << "Preparing NY Veggie Pizza" << std::endl;};
	void bake	(){std::cout << "baking 200C 32Min" << std::endl;};
	void cut	(){std::cout << "4x cutting" << std::endl;};
	void box	(){std::cout << "special boxing" << std::endl;};
};

class ChicagoCheesePizza: public Pizza{
public:
	ChicagoCheesePizza(): Pizza("Chigaco Cheese Pizza"){};
	void prepare(){std::cout << "Preparing Chigaco Cheese Pizza" << std::endl;};
	void bake	(){std::cout << "baking 200C 30Min" << std::endl;};
	void cut	(){std::cout << "8x cutting" << std::endl;};
	void box	(){std::cout << "std boxing" << std::endl;};
};

class ChicagoPepperoniPizza: public Pizza{
public:
	ChicagoPepperoniPizza(): Pizza("Chicago Pepperoni Pizza"){};
	void prepare(){std::cout << "Preparing Chicago Pepperoni Pizza" << std::endl;};
	void bake	(){std::cout << "baking 180C 35Min" << std::endl;};
	void cut	(){std::cout << "sq cutting" << std::endl;};
	void box	(){std::cout << "std boxing" << std::endl;};
};

class ChicagoVeggiePizza: public Pizza{
public:
	ChicagoVeggiePizza(): Pizza("Chicago Veggie Pizza"){};
	void prepare(){std::cout << "Preparing Chicago Veggie Pizza" << std::endl;};
	void bake	(){std::cout << "baking 200C 32Min" << std::endl;};
	void cut	(){std::cout << "4x cutting" << std::endl;};
	void box	(){std::cout << "special boxing" << std::endl;};
};

class PizzaStore{
public:
	virtual Pizza* createPizza(const std::string& type)=0;
	Pizza* orderPizza(const std::string& type){
		Pizza* pizza = createPizza(type); //ignore errors
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
		return pizza;
	};
};

class NYPizzaStore: public PizzaStore{
public:
	Pizza* createPizza(const std::string& type){
		Pizza* pizza = NULL;
		if(type == "cheese") pizza = new NYCheesePizza();
		else if(type == "pepperoni") pizza = new NYPepperoniPizza();
		else if(type == "veggie") pizza = new NYVeggiePizza();
		return pizza;	
	};
};

class ChicagoPizzaStore: public PizzaStore{
public:
	Pizza* createPizza(const std::string& type){
		Pizza* pizza = NULL;
		if(type == "cheese") pizza = new ChicagoCheesePizza();
		else if(type == "pepperoni") pizza = new ChicagoPepperoniPizza();
		else if(type == "veggie") pizza = new ChicagoVeggiePizza();
		return pizza;	
	};
};

int inner_main(int argc, char * argv[])
{
	std::cout << "simple inner main" << std::endl;
	
	PizzaStore* nyStore = new NYPizzaStore();
    PizzaStore* chicagoStore = new ChicagoPizzaStore();
 
    Pizza* pizza = nyStore->orderPizza("cheese");
    std::cout << "Ethan ordered a " << pizza->getName() << std::endl;
 
    Pizza* pizza2 = chicagoStore->orderPizza("cheese");
    std::cout << "Joel ordered a " << pizza2->getName() << std::endl;

	delete nyStore;
	delete chicagoStore;
	delete pizza;
	delete pizza2;

	return 0;
}