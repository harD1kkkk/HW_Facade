// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class TV {
public:
    void turnOn() {
        cout << "TV ON" << endl;
    }
    void turnOff() {
        cout << "TV OFF" << endl;
    }
    void setChannel(string channel) {
        cout << "Channel: " << channel << endl;
    }
    void setVolume(int volume) {
        cout << "Volume: " << volume << endl;
    }
};

class AC {
public:
    void turnOn() {
        cout << "AC ON" << endl;
    }
    void turnOff() {
        cout << "AC OFF" << endl;
    }
    void setTemperature(int temp) {
        cout << "Temperature: " << temp << endl;
    }
    void setMode(int mode) {
        if (mode == 1) {
            cout << "You turned on cooling mode" << endl;
        }
        else if (mode == 2) {
            cout << "You turned on warm mode" << endl;
        }
        else {
            cout << "Unknown option" << endl;
        }
    }
    
};

class Lamp {
public:
    void turnOn() {
        cout << "Lamp ON" << endl;
    }
    void turnOff() {
        cout << "Lamp OFF" << endl;
    }
    void setBrightness(int brightness) {
        cout << "Brightness: " << brightness << endl;
    }
    void setColor(string color) {
        cout << "Color: " << color << endl;
    }
};


class HomeFacade {
private:
    TV* tv;
    AC* ac;
    Lamp* lamp;
public:

    HomeFacade(TV* tv, AC* ac, Lamp* lamp) {
        this->tv = tv;
        this->ac = ac;
        this->lamp = lamp;
    }


    void turnOnAll() {
        tv->turnOn();
        ac->turnOn();
        lamp->turnOn();
    }

    void turnOffAll() {
        tv->turnOff();
        ac->turnOff();
        lamp->turnOff();
    }


    void setTV(string channel, int volume) {
        tv->setChannel(channel);
        tv->setVolume(volume);
    }


    void setAC(int temp, int mode) {
        ac->setTemperature(temp);
        ac->setMode(mode);
    }

    void setLamp(int brightness, string color) {
        lamp->setBrightness(brightness);
        lamp->setColor(color);
    }
};

int main() {
  
    TV* tv = new TV();
    AC* ac = new AC();
    Lamp* lamp = new Lamp();

   
    HomeFacade* facade = new HomeFacade(tv, ac, lamp);


    facade->turnOnAll(); 
    cout << endl;
    facade->setTV("1+1", 50);
    facade->setAC(15, 2);
    facade->setLamp(80, "red");
    cout << endl;
    facade->turnOffAll(); 

    delete tv;
    delete ac;
    delete lamp;
    delete facade;
}