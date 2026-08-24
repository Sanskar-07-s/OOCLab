#include <iostream>
#include <string>
using namespace std;

// Base class
class Student {
protected:
    int rollNo;
    string name;

public:
    void getStudent() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
    }

    void displayStudent() const {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Student Name: " << name << endl;
    }
};

// Derived class 1 with virtual inheritance
class AcademicTest : virtual public Student {
protected:
    float mathMarks;
    float scienceMarks;

public:
    void getMarks() {
        cout << "Enter Mathematics marks (out of 100): ";
        cin >> mathMarks;
        cout << "Enter Science marks (out of 100): ";
        cin >> scienceMarks;
    }

    void displayMarks() const {
        cout << "Mathematics: " << mathMarks << "/100" << endl;
        cout << "Science:     " << scienceMarks << "/100" << endl;
    }
};

// Derived class 2 with virtual inheritance
class Sports : virtual public Student {
protected:
    float sportsScore;

public:
    void getSportsScore() {
        cout << "Enter Sports Score (out of 50): ";
        cin >> sportsScore;
    }

    void displaySportsScore() const {
        cout << "Sports Score: " << sportsScore << "/50" << endl;
    }
};

// Hybrid & Multiple inheritance: Result inherits from AcademicTest and Sports
class Result : public AcademicTest, public Sports {
private:
    float totalScore;
    float overallPercentage;

public:
    void compute() {
        totalScore = mathMarks + scienceMarks + sportsScore;
        overallPercentage = (totalScore / 250.0f) * 100.0f;
    }

    void displayReportCard() const {
        cout << "\n==========================================" << endl;
        cout << "  HYBRID & MULTIPLE INHERITANCE REPORT    " << endl;
        cout << "==========================================" << endl;
        displayStudent(); // Accessible without ambiguity due to virtual base class
        cout << "------------------------------------------" << endl;
        displayMarks();
        displaySportsScore();
        cout << "------------------------------------------" << endl;
        cout << "Total Score: " << totalScore << " / 250" << endl;
        cout << "Percentage:  " << overallPercentage << "%" << endl;
        cout << "Grade:       " << (overallPercentage >= 75.0f ? "Distinction" :
                                   overallPercentage >= 60.0f ? "First Class" :
                                   overallPercentage >= 50.0f ? "Second Class" : "Pass Class") << endl;
        cout << "==========================================" << endl;
    }
};

int main() {
    cout << "=== Demonstration of Multiple & Hybrid Inheritance ===" << endl;
    Result res;
    res.getStudent();
    res.getMarks();
    res.getSportsScore();
    res.compute();
    res.displayReportCard();

    return 0;
}
