#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    string str;

    ofstream fout("sample.txt");
    cout << "Enter text to write to file: ";
    getline(cin, str);
    fout << str;
    fout.close();

    cout << "Data written to file successfully." << endl;

    ifstream fin("sample.txt");
    cout << "Reading from file:" << endl;
    while (getline(fin, str)) {
        cout << str << endl;
    }
    fin.close();

    return 0;
}
