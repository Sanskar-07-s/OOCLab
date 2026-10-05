#include<iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing generic shape" << endl;
    }

    virtual void area() {
        cout << "Area of generic shape" << endl;
    }

    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    void draw() {
        cout << "Drawing Rectangle" << endl;
    }

    void area() {
        cout << "Area of Rectangle: " << length * width << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    void draw() {
        cout << "Drawing Circle" << endl;
    }

    void area() {
        cout << "Area of Circle: " << 3.14159 * radius * radius << endl;
    }
};

int main() {
    Shape* s1 = new Rectangle(10, 5);
    Shape* s2 = new Circle(7);

    s1->draw();
    s1->area();

    cout << endl;

    s2->draw();
    s2->area();

    delete s1;
    delete s2;

    return 0;
}
