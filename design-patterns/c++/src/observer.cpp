#include <iostream>
#include <list>

class Observer{
public:
	virtual void update(float temp, float humidity, float pressure)=0;
	virtual ~Observer(){};
};

class Subject{
public:
	virtual void registerObserver(Observer* o)=0;
	virtual void removeObserver(Observer* o)=0;
	virtual void notifyObservers()=0;
};

class DisplayElement{
public:
	virtual void display()=0;
};

class WeatherData: public Subject{
public:
	void registerObserver(Observer* o){_observers.push_back(o);};
	void removeObserver(Observer* o){_observers.remove(o);};
	void notifyObservers(){
		for(auto i = _observers.begin(); i != _observers.end(); ++i)
			(*i)->update(_temperature, _humidity, _pressure);
	};
	void measurementsChanged(){notifyObservers();};
	void setMeasurements(float temperature, float humidity, float pressure){
		_temperature = temperature;
		_humidity = humidity;
		_pressure = pressure;
		measurementsChanged();
	};
private:
	std::list<Observer*> _observers;
	float _temperature;
	float _humidity;
	float _pressure;
};

class CurrentConditionsDisplay: public Observer, public DisplayElement{
public:
	CurrentConditionsDisplay(Subject* weatherData){_weatherData = weatherData; weatherData->registerObserver(this);};
	virtual void update(float temp, float humidity, float pressure){_temperature = temp; _humidity = humidity; display();};
	virtual void display(){std::cout << "Current conditions: " << _temperature << "F and " << _humidity << "% hum" << std::endl;};
private:
	float _temperature;
	float _humidity;
	Subject* _weatherData;
};

//TODO: Change to PULL model
int inner_main(int argc, char * argv[])
{
	std::cout << "observer pattern" << std::endl;

	WeatherData* wd = new WeatherData();
	CurrentConditionsDisplay* currentDisplay = new CurrentConditionsDisplay(wd);
	//StatisticsDisplay* statisticsDisplay = new StatisticsDisplay(wd);
	//ForecastDisplay* forecastDisplay = new ForecastDisplay(wd);

	wd->setMeasurements(80, 65, 30.4f);
	wd->setMeasurements(82, 70, 29.2f);
	wd->setMeasurements(78, 90, 29.2f);

	return 0;
}