#include <iostream>
#include <cmath>
using namespace std;

// Area of a circle (1 parameter: double)
double area(double radius) {
    return 3.141592653589793 * radius * radius;
}

// Area of a square (1 parameter: int)
int area(int side) {
    return side * side;
}

// Area of a rectangle (2 parameters: double, double)
double area(double length, double width) {
    return length * width;
}

// Area of a right-angled triangle (2 parameters: float, float)
float area(float base, float height) {
    return 0.5f * base * height;
}

// Area of a general triangle using Heron's formula (3 parameters: double, double, double)
double area(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    int choice;
    cout << "=== Area Calculation using Function Overloading ===" << endl;
    cout << "1. Area of Circle" << endl;
    cout << "2. Area of Square" << endl;
    cout << "3. Area of Rectangle" << endl;
    cout << "4. Area of Right-Angled Triangle" << endl;
    cout << "5. Area of Triangle (Heron's Formula)" << endl;
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            double r;
            cout << "Enter radius of circle: ";
            cin >> r;
            cout << "Area of Circle: " << area(r) << endl;
            break;
        }
        case 2: {
            int s;
            cout << "Enter side of square: ";
            cin >> s;
            cout << "Area of Square: " << area(s) << endl;
            break;
        }
        case 3: {
            double l, w;
            cout << "Enter length and width of rectangle: ";
            cin >> l >> w;
            cout << "Area of Rectangle: " << area(l, w) << endl;
            break;
        }
        case 4: {
            float b, h;
            cout << "Enter base and height of right-angled triangle: ";
            cin >> b >> h;
            cout << "Area of Triangle: " << area(b, h) << endl;
            break;
        }
        case 5: {
            double a, b, c;
            cout << "Enter 3 sides of triangle: ";
            cin >> a >> b >> c;
            if (a + b > c && a + c > b && b + c > a) {
                cout << "Area of Triangle: " << area(a, b, c) << endl;
            } else {
                cout << "Invalid sides! Triangle cannot be formed." << endl;
            }
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
