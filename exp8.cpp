#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    // Default constructor
    Distance() : feet(0), inches(0) {}

    // Parameterized constructor
    Distance(int f, int i) {
        feet = f + (i / 12);
        inches = i % 12;
        if (inches < 0) {
            inches += 12;
            feet -= 1;
        }
    }

    // Input function
    void input() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
        feet += inches / 12;
        inches = inches % 12;
    }

    // Display function
    void display() const {
        cout << feet << " ft " << inches << " in";
    }

    // 1. Unary Operator Overloading: Prefix ++ (++d)
    Distance operator++() {
        ++inches;
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        }
        return *this;
    }

    // Unary Operator Overloading: Postfix ++ (d++)
    Distance operator++(int) {
        Distance temp = *this;
        inches++;
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        }
        return temp;
    }

    // Unary Operator Overloading: Unary minus (-d)
    Distance operator-() const {
        return Distance(-feet, -inches);
    }

    // 2. Binary Operator Overloading: + (d1 + d2)
    Distance operator+(const Distance &d) const {
        int totalFeet = feet + d.feet;
        int totalInches = inches + d.inches;
        return Distance(totalFeet, totalInches);
    }

    // 3. Relational Operator Overloading: == (d1 == d2)
    bool operator==(const Distance &d) const {
        return (feet == d.feet && inches == d.inches);
    }

    // Relational Operator Overloading: < (d1 < d2)
    bool operator<(const Distance &d) const {
        int totalThisInches = feet * 12 + inches;
        int totalDInches = d.feet * 12 + d.inches;
        return totalThisInches < totalDInches;
    }

    // Relational Operator Overloading: > (d1 > d2)
    bool operator>(const Distance &d) const {
        int totalThisInches = feet * 12 + inches;
        int totalDInches = d.feet * 12 + d.inches;
        return totalThisInches > totalDInches;
    }
};

int main() {
    Distance d1(5, 8), d2(3, 10);

    cout << "=== OPERATOR OVERLOADING DEMONSTRATION ===" << endl;
    cout << "Distance 1: "; d1.display(); cout << endl;
    cout << "Distance 2: "; d2.display(); cout << endl;

    // 1. Binary Operator Overloading (+)
    cout << "\n--- 1. Binary Operator (+) Overloading ---" << endl;
    Distance sum = d1 + d2;
    cout << "d1 + d2 = "; sum.display(); cout << endl;

    // 2. Unary Operator Overloading (++, -)
    cout << "\n--- 2. Unary Operator Overloading ---" << endl;
    cout << "Original d1: "; d1.display(); cout << endl;
    ++d1;
    cout << "After prefix ++d1: "; d1.display(); cout << endl;
    Distance neg = -d1;
    cout << "Unary negation -d1: "; neg.display(); cout << endl;

    // 3. Relational Operator Overloading (==, <, >)
    cout << "\n--- 3. Relational Operator Overloading ---" << endl;
    cout << "Comparing d1 and d2:" << endl;
    if (d1 == d2) {
        cout << "d1 is equal to d2" << endl;
    } else if (d1 < d2) {
        cout << "d1 is less than d2" << endl;
    } else if (d1 > d2) {
        cout << "d1 is greater than d2" << endl;
    }

    return 0;
}
