#include <iostream>
#include <cmath>
using namespace std;

// Abstract Base Class
class Shape {
protected:
    string shapeName;

public:
    Shape(string name) : shapeName(name) {}

    // Pure virtual function
    virtual void calculateArea() = 0;

    // Virtual function
    virtual void display() const {
        cout << "Shape: " << shapeName << endl;
    }

    // Virtual destructor
    virtual ~Shape() {
        cout << "Shape destructor called for " << shapeName << endl;
    }
};

// Derived Class 1: Circle
class Circle : public Shape {
private:
    double radius;
    double area;

public:
    Circle(double r) : Shape("Circle"), radius(r), area(0.0) {}

    void calculateArea() {
        area = 3.141592653589793 * radius * radius;
    }

    void display() const {
        Shape::display();
        cout << "Radius: " << radius << " | Area: " << area << endl;
    }

    ~Circle() {
        cout << "Circle destructor called." << endl;
    }
};

// Derived Class 2: Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;
    double area;

public:
    Rectangle(double l, double w) : Shape("Rectangle"), length(l), width(w), area(0.0) {}

    void calculateArea() {
        area = length * width;
    }

    void display() const {
        Shape::display();
        cout << "Dimensions: " << length << " x " << width << " | Area: " << area << endl;
    }

    ~Rectangle() {
        cout << "Rectangle destructor called." << endl;
    }
};

// Derived Class 3: Triangle
class Triangle : public Shape {
private:
    double base;
    double height;
    double area;

public:
    Triangle(double b, double h) : Shape("Triangle"), base(b), height(h), area(0.0) {}

    void calculateArea() {
        area = 0.5 * base * height;
    }

    void display() const {
        Shape::display();
        cout << "Base: " << base << ", Height: " << height << " | Area: " << area << endl;
    }

    ~Triangle() {
        cout << "Triangle destructor called." << endl;
    }
};

int main() {
    cout << "=== RUNTIME POLYMORPHISM USING VIRTUAL FUNCTIONS ===" << endl << endl;

    // Array of base class pointers pointing to derived objects
    const int count = 3;
    Shape* shapes[count];

    shapes[0] = new Circle(7.0);
    shapes[1] = new Rectangle(10.0, 5.0);
    shapes[2] = new Triangle(8.0, 6.0);

    for (int i = 0; i < count; i++) {
        cout << "--- Processing Object " << (i + 1) << " ---" << endl;
        shapes[i]->calculateArea(); // Dynamic dispatch (late binding)
        shapes[i]->display();
        cout << endl;
    }

    // Clean up memory (virtual destructor ensures correct derived destructors are called)
    cout << "--- Cleaning up dynamically allocated memory ---" << endl;
    for (int i = 0; i < count; i++) {
        delete shapes[i];
    }

    return 0;
}
