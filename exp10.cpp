#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "user_data.txt";
    string userInput;

    cout << "=== FILE HANDLING: WRITE & READ USER INPUT ===" << endl << endl;

    // 1. Writing user input to file
    ofstream outFile(filename.c_str());
    if (!outFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1;
    }

    cout << "Enter text to write to the file (type 'END' on a new line to finish):" << endl;
    while (true) {
        getline(cin, userInput);
        if (userInput == "END") {
            break;
        }
        outFile << userInput << endl;
    }
    outFile.close();
    cout << "\nData successfully written to '" << filename << "'." << endl;

    // 2. Reading content from file
    cout << "\nReading contents back from '" << filename << "':" << endl;
    cout << "----------------------------------------" << endl;

    ifstream inFile(filename.c_str());
    if (!inFile) {
        cerr << "Error: Could not open file for reading!" << endl;
        return 1;
    }

    string line;
    int lineCount = 0;
    while (getline(inFile, line)) {
        lineCount++;
        cout << lineCount << ": " << line << endl;
    }
    inFile.close();

    cout << "----------------------------------------" << endl;
    cout << "Finished reading. Total lines read: " << lineCount << endl;

    return 0;
}
