#include<iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    Distance() {
        feet = 0;
        inches = 0;
    }

    Distance(int f, int i) {
        feet = f;
        inches = i;
    }

    void display() {
        cout << feet << " ft " << inches << " in" << endl;
    }

    Distance operator-() {
        return Distance(-feet, -inches);
    }

    Distance operator+(Distance d) {
        int f = feet + d.feet;
        int i = inches + d.inches;
        if (i >= 12) {
            f += i / 12;
            i %= 12;
        }
        return Distance(f, i);
    }

    bool operator==(Distance d) {
        return (feet == d.feet && inches == d.inches);
    }

    bool operator<(Distance d) {
        int t1 = feet * 12 + inches;
        int t2 = d.feet * 12 + d.inches;
        return t1 < t2;
    }
};

int main() {
    Distance d1(5, 8), d2(3, 10);

    cout << "d1: "; d1.display();
    cout << "d2: "; d2.display();

    Distance d3 = d1 + d2;
    cout << "d1 + d2: "; d3.display();

    Distance d4 = -d1;
    cout << "-d1: "; d4.display();

    if (d1 == d2)
        cout << "d1 is equal to d2" << endl;
    else
        cout << "d1 is not equal to d2" << endl;

    if (d2 < d1)
        cout << "d2 is less than d1" << endl;

    return 0;
}
