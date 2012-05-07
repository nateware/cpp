
//#include "vehicle.h"
#include <iostream>

class IIgnition {
public:
    virtual ~IIgnition() {}
    virtual void Start() = 0;
    virtual void Stop()  = 0;
    virtual void ShowRunning() = 0;
};

class CVehicle {
public:
    void Describe() {
        printf("Num wheels = %d, num doors = %d\n", m_nWheels, m_nDoors);
    }
protected:
    int m_nWheels;
    int m_nDoors;

};

class CCar : public CVehicle, public IIgnition {
public:
    void Start() {
        m_bRunning = true;
    }
    void Stop() {
        m_bRunning = false;
    }
    void ShowRunning() {
        printf("Running? %d\n", m_bRunning);
    }
    CCar() {
        m_nWheels = 4;
        m_nDoors  = 4;
    }

private:
    bool m_bRunning;

};

int main(int argc, const char* argv)
{
    CCar *car = new CCar();
    car->Describe();
    car->Start();
    car->ShowRunning();
    car->Stop();
    car->ShowRunning();
    delete car;
}
