#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    float Speed;
    float Fuel;
    float Max_Fuel ;
    float Passanger ;

    virtual void Drive() {
        cout << "Mobil ini berjalan secepat " << Speed << " km/hour" << endl;
        Fuel -= Speed;
    }
    Car( float speed, float fuel, float max_fuel, float passanger) {
        Speed = speed;
        Fuel = fuel;
        Max_Fuel = max_fuel;
        Passanger = passanger;
    }
    Car() {
        Speed = 10;
        Fuel = 100;
        Max_Fuel = 100;
        Passanger = 4;
    }
};

class SuperCar : public Car {
public:
    float Speed = 100;
    float Fuel = 1000;
    float Max_Fuel = 1000;
    void Drive() override {
        cout << "Bugati ini berjalan secepat " << Speed << " km / hour" << endl;
        Fuel -= Speed;
    }

};

class Pickup : public Car {
public:
    float Capacity = 1;
    float Max_Capacity = 100;
    float Kecepatan = Speed / Capacity;

    Pickup(float speed, float fuel, float max_fuel, float passanger, float capacity, float max_capacity, float kecepatan)
        :Car(speed, fuel, max_fuel, passanger) {
        Capacity = capacity;
        Max_Capacity = max_capacity;
        Kecepatan = kecepatan;
    }
    Pickup() {
       /** Speed = 10;
        Fuel = 100;
        Max_Fuel = 100;
        Passanger = 4;*/
        Capacity = 1;
        Max_Capacity = 100;
        Kecepatan = Speed / Capacity;
    }
    void Angkut(float Capacity) {
        if (Capacity < Max_Capacity) {
            this->Capacity += Capacity;
            cout << "LandRover berjalan dengan kapasitas " << Capacity << "kg" << endl;
        }
        else {
            cout << "LandRover tidak bisa jalan Kapasitas melebihi batas" << endl;
        }
    }
        void Drive() override  {
            cout << "LandRover ini berjalan sejauh " << Kecepatan << " km/hour" << endl;
            Fuel -= Capacity;
        }
};

int main() {
    Car Avanza;
    Avanza.Drive();
    
    SuperCar Bugati;
    Bugati.Drive();

    Pickup LandRover;
    LandRover.Angkut(9);
    LandRover.Drive();

    return 0;

}