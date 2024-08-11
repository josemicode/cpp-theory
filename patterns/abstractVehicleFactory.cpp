#include <iostream>

using namespace std;
/*
2. Patrón Fábricas Abstractas
TODO:
Considera la implementación de un sistema de gestión de vehículos. El sistema debe ser capaz
de gestionar diferentes tipos de vehículos, como coches, motocicletas y bicicletas. Cada tipo de
vehículo tiene diferentes atributos y métodos.
En este ejercicio, se le pide que implemente el patrón de diseño Abstract Factory para gestionar
la creación de diferentes tipos de vehículos.
* Cree una interfaz de fábrica abstracta para la creación de vehículos, que pueden ser: autos, motocicletas (eléctricos y a gasolina) así como bicicletas (eléctricas o no).
* Implementa las clases concretas de fábrica para cada tipo de vehículo.
* Escribe un código de prueba que muestre cómo se pueden crear diferentes tipos de vehículos utilizando la fábrica abstracta.

*/

class Vehicle
{
public:
    virtual void drive() const = 0;
};

class Car : public Vehicle
{
public:
    void drive() const override
    {
        cout << "Driving a car, broom broom!" << endl;
    }
};

class Bicycle : public Vehicle
{
public:
    void drive() const override
    {
        cout << "Riding a bicycle, pedal pedal!" << endl;
    }
};

// Concrete class for Motorcycles
class Motorcycle : public Vehicle
{
public:
    void drive() const override
    {
        cout << "Riding a motorcycle, fiaaaumm!" << endl;
    }
};

class VehicleFactory
{
public:
    virtual Vehicle *createVehicle() const = 0;
};

class CarFactory : public VehicleFactory
{
public:
    Vehicle *createVehicle() const override
    {
        return new Car();
    }
};

class MotorcycleFactory : public VehicleFactory
{
public:
    Vehicle *createVehicle() const override
    {
        return new Motorcycle();
    }
};

class BicycleFactory : public VehicleFactory
{
public:
    Vehicle *createVehicle() const override
    {
        return new Bicycle();
    }
};

int main()
{
    // Create Factories
    CarFactory carFactory;
    MotorcycleFactory motorcycleFactory;
    BicycleFactory bicycleFactory;

    // Create Vehicules Using Factories
    Vehicle *car = carFactory.createVehicle();
    Vehicle *motorcycle = motorcycleFactory.createVehicle();
    Vehicle *bicycle = bicycleFactory.createVehicle();

    // Method testing
    car->drive();
    motorcycle->drive();
    bicycle->drive();

    // Free Memory
    delete car;
    delete motorcycle;
    delete bicycle;

    return 0;
}
