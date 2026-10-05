#include<iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle() {
        length = 0;
        width = 0;
        cout << "Default constructor called" << endl;
    }

    Rectangle(double l, double w) {
        length = l;
        width = w;
        cout << "Parameterized constructor called" << endl;
    }

    Rectangle(const Rectangle &r) {
        length = r.length;
        width = r.width;
        cout << "Copy constructor called" << endl;
    }

    ~Rectangle() {
        cout << "Destructor called" << endl;
    }

    double area() {
        return length * width;
    }

    double perimeter() {
        return 2 * (length + width);
    }

    void display() {
        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

int main() {
    Rectangle r1;
    r1.display();

    cout << endl;

    Rectangle r2(10.5, 5.5);
    r2.display();

    cout << endl;

    Rectangle r3 = r2;
    r3.display();

    return 0;
}
