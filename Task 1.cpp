#include <iostream>
#include <cmath>

using namespace std;
const double pi = 3.1416;
class Shape {
public:
    virtual double area() const = 0; 
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return  pi* radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override {
        return length * width;
    }
};

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    cout << "Circle Area: " << circle.area() << endl;
    cout << "Rectangle Area: " << rectangle.area() << endl;

    return 0;
}