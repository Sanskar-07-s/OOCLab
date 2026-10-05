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

class Test : virtual public Student {
protected:
    float marks;

public:
    void getMarks() {
        cout << "Enter Academic Marks: ";
        cin >> marks;
    }

    void displayMarks() {
        cout << "Academic Marks: " << marks << endl;
    }
};

class Sports : virtual public Student {
protected:
    float score;

public:
    void getScore() {
        cout << "Enter Sports Score: ";
        cin >> score;
    }

    void displayScore() {
        cout << "Sports Score: " << score << endl;
    }
};

class Result : public Test, public Sports {
private:
    float total;

public:
    void calculate() {
        total = marks + score;
    }

    void displayResult() {
        displayStudent();
        displayMarks();
        displayScore();
        cout << "Total Marks: " << total << endl;
    }
};

int main() {
    Result r;
    r.getStudent();
    r.getMarks();
    r.getScore();
    r.calculate();
    cout << "\n--- Final Result ---" << endl;
    r.displayResult();

    return 0;
}
