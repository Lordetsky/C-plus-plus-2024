#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

const double KNOT_MULTIPLIER = 1.852;


class Vehicle
{
public:
    Vehicle(std::string  name, double load): _name(std::move(name)), _load(load) {}

    virtual std::string getInfo() const {
        return "name: " + _name + ", load: " + std::to_string(_load);
    }

    virtual double getLoad() const
    {
        return _load;
    }

    void setLoad(double load)
    {
        _load = load;
    }

    std::string getName() const
    {

        return _name;
    }

    virtual std::string getType() const {
        return "Landcraft";
    }

    virtual double getSpeed() const = 0;

private:
    std::string _name;
    double _load;

protected:

    double getterLoad() const
    {
        return _load;
    }
};

class Car : public Vehicle
{
public:
    Car(const std::string& name, double load, double meanSpeed=90): Vehicle(name, load), _meanSpeed(meanSpeed) {}

    std::string getInfo() const override{
        return "name: " + getName() + ", load: " + std::to_string(getLoad()) + ", speed: " + std::to_string(_meanSpeed);
    }

    double getMeanSpeed() const {
        return _meanSpeed;
    }

    double getSpeed() const override{
        return _meanSpeed;
    }

private:
    double _meanSpeed;
};

class Truck : public Car
{

public:
    Truck(const std::string& name, double load, double meanSpeed=60, double extraCargo=0): Car(name, load, meanSpeed), _extraCargo(extraCargo) {}

    double getLoad() const override {
        return getterLoad() + _extraCargo;
    }

    std::string getInfo() const override{
        return "name: " + getName() + ", load: " + std::to_string(getLoad()) + ", speed: " + std::to_string(getMeanSpeed());
    }

private:
    double _extraCargo;
};

class Boat : public Vehicle
{
public:
    Boat(const std::string& name, double load, double meanKnotSpeed=30): Vehicle(name, load), _meanKnotSpeed(meanKnotSpeed) {}

    std::string getInfo() const override{
        return "name: " + getName() + ", load: " + std::to_string(getLoad()) + ", knotSpeed: " + std::to_string(_meanKnotSpeed);
    }

    double getKnotSpeed() const{
        return _meanKnotSpeed;
    }

    static double knot2Speed(double knotSpeed){
        return knotSpeed * KNOT_MULTIPLIER;
    }

    std::string getType() const override {
        return "Seacraft";
    }

    double getSpeed() const override {
        return knot2Speed(_meanKnotSpeed);
    }

private:
    double _meanKnotSpeed;
};

class Warehouse
{
public:
    void addVehicle(Vehicle* vehicle){
        _vehicles.push_back(vehicle);
    }
    double getTotalLoad() const {
        double load = 0;
        for (const auto& el: _vehicles) {
            load += el->getLoad();
        }

        return load;
    }

    std::vector<Vehicle*> getArr() const {
        return _vehicles;
    }

    Vehicle* operator[](size_t index) const{
        if(index >= (_vehicles.size()))
        {
            throw std::out_of_range(std::to_string(index) + " is a wrong index");
        }
        return _vehicles[index];

    }
private:
    std::vector<Vehicle*> _vehicles;
};

bool sortir(Vehicle* el1, Vehicle* el2) {
    if (el1->getLoad() != el2->getLoad()) return el1->getLoad() > el2->getLoad();
    if (el1->getSpeed() != el2->getSpeed()) return el1->getSpeed() > el2->getSpeed();

    return el1->getName() < el2->getName();
}

std::ostream& operator << (std::ostream& os, const Warehouse& warehouse)
{
    std::vector<Vehicle*> buf = warehouse.getArr();

    std::sort(buf.begin(), buf.end(), sortir);

    for (const auto el: buf){
        os << el->getInfo() << '\n';
    }

    return os;
}

#endif// __VEHICLE_H__
