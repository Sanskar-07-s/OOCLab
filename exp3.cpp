#include<iostream>
#include<string>
using namespace std;

class Account {
protected:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    Account(string name, int accNo, double initBalance) {
        accountHolder = name;
        accountNumber = accNo;
        balance = initBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". Remaining Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void display() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingAccount : public Account {
private:
    double interestRate;

public:
    SavingAccount(string name, int accNo, double initBalance, double rate)
        : Account(name, accNo, initBalance) {
        interestRate = rate;
    }

    void calculateInterest() {
        double interest = (balance * interestRate) / 100.0;
        balance += interest;
        cout << "Interest Added: " << interest << ". Updated Balance: " << balance << endl;
    }
};

class CheckingAccount : public Account {
private:
    double fee;

public:
    CheckingAccount(string name, int accNo, double initBalance, double f)
        : Account(name, accNo, initBalance) {
        fee = f;
    }

    void withdraw(double amount) {
        double total = amount + fee;
        if (total <= balance) {
            balance -= total;
            cout << "Withdrawn: " << amount << " (Fee: " << fee << "). Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance including fee!" << endl;
        }
    }
};

int main() {
    SavingAccount sa("Sanskar", 101, 5000, 5);
    sa.display();
    sa.deposit(1000);
    sa.calculateInterest();

    cout << endl;

    CheckingAccount ca("Sanskar", 102, 3000, 20);
    ca.display();
    ca.withdraw(500);

    return 0;
}
