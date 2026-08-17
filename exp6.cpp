#include <iostream>
#include <string>
using namespace std;

// Base class
class Student {
protected:
    int rollNo;
    string name;

public:
    void getStudentDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
    }

    void putStudentDetails() const {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};

// Intermediate derived class (Single inheritance from Student)
class Exam : public Student {
protected:
    float mark1, mark2, mark3;

public:
    void getMarks() {
        cout << "Enter Marks in Subject 1: ";
        cin >> mark1;
        cout << "Enter Marks in Subject 2: ";
        cin >> mark2;
        cout << "Enter Marks in Subject 3: ";
        cin >> mark3;
    }

    void putMarks() const {
        cout << "Subject 1 Marks: " << mark1 << endl;
        cout << "Subject 2 Marks: " << mark2 << endl;
        cout << "Subject 3 Marks: " << mark3 << endl;
    }
};

// Second level derived class (Multilevel inheritance from Exam)
class Result : public Exam {
private:
    float total;
    float percentage;

public:
    void calculate() {
        total = mark1 + mark2 + mark3;
        percentage = (total / 300.0f) * 100.0f;
    }

    void displayResult() const {
        cout << "\n===============================" << endl;
        cout << "         STUDENT MARKSHEET     " << endl;
        cout << "===============================" << endl;
        putStudentDetails();
        cout << "-------------------------------" << endl;
        putMarks();
        cout << "-------------------------------" << endl;
        cout << "Total Marks: " << total << " / 300" << endl;
        cout << "Percentage:  " << percentage << "%" << endl;
        cout << "Result:      " << (percentage >= 40.0f ? "PASS" : "FAIL") << endl;
        cout << "===============================" << endl;
    }
};

int main() {
    Result r;
    cout << "=== Multilevel Inheritance Demonstration ===" << endl;
    r.getStudentDetails();
    r.getMarks();
    r.calculate();
    r.displayResult();

    return 0;
}
