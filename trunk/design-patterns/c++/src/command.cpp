#include <iostream>

class Light
{
public:
	Light(): state(false){};
	~Light(){};
	void on(){state = true; std::cout << "Light is On" << std::endl;};
	void off(){state = false; std::cout << "Light is Off" << std::endl;};
private:
	bool state;
};


class Command
{
public:
	Command(){};
	virtual ~Command(){};
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class LightOnCommand: public Command
{
public:
	LightOnCommand(Light* light){_light = light;};
	~LightOnCommand(){};
	void execute(){_light->on();};
	void undo(){_light->off();};
private:
	LightOnCommand(){};
	Light* _light;
};

class SimpleRemoteControl
{
public:
	SimpleRemoteControl(){};
	~SimpleRemoteControl(){};
	void setCommand(Command* command){_slot = command;};
	void buttonWasPressed(){_slot->execute();};
private:
	Command* _slot;
};

int inner_main(int argc, char * argv[])
{
	std::cout << "command pattern" << std::endl;
	
	SimpleRemoteControl* remote = new SimpleRemoteControl();
	Light* light = new Light();
	LightOnCommand* lightOnCommand =  new LightOnCommand(light);

	remote->setCommand(lightOnCommand);
	remote->buttonWasPressed();

	return 0;
}