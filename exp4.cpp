#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Default constructor
    Rectangle() {
        length = 0.0;
        width = 0.0;
        cout << "Default constructor called." << endl;
    }

    // Parameterized constructor
    Rectangle(double l, double w) {
        length = l;
        width = w;
        cout << "Parameterized constructor called with length = " << length 
             << ", width = " << width << endl;
    }

    // Copy constructor
    Rectangle(const Rectangle &rect) {
        length = rect.length;
        width = rect.width;
        cout << "Copy constructor called to create duplicate rectangle." << endl;
    }

    // Destructor
    ~Rectangle() {
        cout << "Destructor called for Rectangle with dimensions (" 
             << length << " x " << width << ")" << endl;
    }

    // Member function to calculate area
    double area() const {
        return length * width;
    }

    // Member function to calculate perimeter
    double perimeter() const {
        return 2 * (length + width);
    }

    // Member function to display rectangle details
    void display() const {
        cout << "Dimensions: " << length << " x " << width 
             << " | Area: " << area() 
             << " | Perimeter: " << perimeter() << endl;
    }
};

int main() {
    cout << "--- Creating r1 using Default Constructor ---" << endl;
    Rectangle r1;
    r1.display();

    cout << "\n--- Creating r2 using Parameterized Constructor ---" << endl;
    Rectangle r2(12.5, 4.0);
    r2.display();

    cout << "\n--- Creating r3 using Copy Constructor (copy of r2) ---" << endl;
    Rectangle r3 = r2;
    r3.display();

    cout << "\n--- Block scope demonstration for Destructor ---" << endl;
    {
        Rectangle tempRect(7.0, 3.5);
        tempRect.display();
        cout << "Exiting inner block..." << endl;
    }

    cout << "\nReturning from main..." << endl;
    return 0;
}
