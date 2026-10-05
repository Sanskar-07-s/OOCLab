#include<iostream>
#include<string>
using namespace std;

class Student {
protected:
    int rollNo;
    string name;

public:
    void getStudent() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
    }

    void displayStudent() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};

class Exam : public Student {
protected:
    float mark1, mark2, mark3;

public:
    void getMarks() {
        cout << "Enter marks for 3 subjects: ";
        cin >> mark1 >> mark2 >> mark3;
    }

    void displayMarks() {
        cout << "Marks: " << mark1 << ", " << mark2 << ", " << mark3 << endl;
    }
};

class Result : public Exam {
private:
    float total;
    float percentage;

public:
    void calculate() {
        total = mark1 + mark2 + mark3;
        percentage = total / 3.0;
    }

    void displayResult() {
        displayStudent();
        displayMarks();
        cout << "Total Marks: " << total << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main() {
    Result r;
    r.getStudent();
    r.getMarks();
    r.calculate();
    cout << "\n--- Student Result ---" << endl;
    r.displayResult();

    return 0;
}
