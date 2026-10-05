#include<iostream>
#include<cmath>
using namespace std;

double area(double radius) {
    return 3.14159 * radius * radius;
}

double area(double length, double width) {
    return length * width;
}

double area(double base, double height, int type) {
    return 0.5 * base * height;
}

int main() {
    double r = 5.0;
    double l = 10.0, w = 4.0;
    double b = 6.0, h = 8.0;

    cout << "Area of Circle (r=" << r << "): " << area(r) << endl;
    cout << "Area of Rectangle (l=" << l << ", w=" << w << "): " << area(l, w) << endl;
    cout << "Area of Triangle (b=" << b << ", h=" << h << "): " << area(b, h, 1) << endl;

    return 0;
}
