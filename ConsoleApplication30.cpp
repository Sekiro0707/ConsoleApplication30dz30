#include <iostream>
#include <string>
using namespace std;


class traspot {
public:
    virtual double clatuma(double dispk) = 0;
    virtual double coutclas(double dispk, double weight) = 0;
    virtual ~traspot() {}
};


class Car : public traspot {
public:
    double speed = 60;
    double claskg = 0.5;

    double clatuma(double dispk) override {
        return dispk / speed;
    }

    double coutclas(double dispk, double weight) override {
        return weight * claskg * dispk;
    }
};


class Bicycle : public traspot {
public:
    double speed = 15;
    double claskg = 0.2;

    double clatuma(double dispk) override {
        return dispk / speed;
    }

    double coutclas(double dispk, double weight) override {
        return weight * claskg * dispk;
    }
};


class Cart : public traspot {
public:
    double speed = 10;
    double claskg = 0.3;

    double clatuma(double dispk) override {
        return dispk / speed;
    }

    double coutclas(double dispk, double weight) override {
        return weight * claskg * dispk;
    }
};

int main() {
    double dispk, weight;
    cout << "Enter the distance to be transported (in km): ";
    cin >> dispk;
    cout << "Enter the weight of the cargo (in kg): ";
    cin >> weight;

    traspot* car = new Car();
    traspot* bicycle = new Bicycle();
    traspot* cart = new Cart();

    cout << "  Time: " << car->clatuma(dispk) << " hours\n";
    cout << "  Cost: " << car->coutclas(dispk, weight) << " UAH\n";
    cout << "  Time: " << bicycle->clatuma(dispk) << " hours\n";
    cout << "  Cost: " << bicycle->coutclas(dispk, weight) << " UAH\n";
    cout << "  Time: " << cart->clatuma(dispk) << " hours\n";
    cout << "  Cost: " << cart->coutclas(dispk, weight) << " UAH\n";

    delete car;
    delete bicycle;
    delete cart;

    return 0;
}
