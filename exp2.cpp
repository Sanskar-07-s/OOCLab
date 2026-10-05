#include<iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }

    Complex add(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    Complex subtract(Complex c) {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }
};

int main() {
    Complex c1, c2, c3;

    cout << "Enter first complex number:" << endl;
    c1.input();

    cout << "Enter second complex number:" << endl;
    c2.input();

    cout << "\nFirst Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    c3 = c1.add(c2);
    cout << "Sum: ";
    c3.display();

    c3 = c1.subtract(c2);
    cout << "Difference: ";
    c3.display();

    return 0;
}
