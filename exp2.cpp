#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Parameterized constructor
    Complex(float r, float i) : real(r), imag(i) {}

    // Input function
    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    // Display function
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }

    // Function to add two complex numbers
    Complex add(const Complex &c) const {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    // Function to subtract two complex numbers
    Complex subtract(const Complex &c) const {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }

    // Function to multiply two complex numbers
    Complex multiply(const Complex &c) const {
        Complex temp;
        temp.real = (real * c.real) - (imag * c.imag);
        temp.imag = (real * c.imag) + (imag * c.real);
        return temp;
    }
};

int main() {
    Complex c1, c2, c3;

    cout << "Enter first complex number:\n";
    c1.input();

    cout << "\nEnter second complex number:\n";
    c2.input();

    cout << "\nFirst Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    c3 = c1.add(c2);
    cout << "\nSum of complex numbers: ";
    c3.display();

    c3 = c1.subtract(c2);
    cout << "Difference of complex numbers: ";
    c3.display();

    c3 = c1.multiply(c2);
    cout << "Product of complex numbers: ";
    c3.display();

    return 0;
}
