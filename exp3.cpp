#include <iostream>
#include <string>
using namespace std;

// Base class
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

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: Rs. " << amount << ". New Balance: Rs. " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: Rs. " << amount << ". Remaining Balance: Rs. " << balance << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    virtual void display() const {
        cout << "\n--- Account Details ---" << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: Rs. " << balance << endl;
    }

    virtual ~Account() {}
};

// Derived class for Savings Account
class SavingAccount : public Account {
private:
    double interestRate; // Annual interest percentage

public:
    SavingAccount(string name, int accNo, double initBalance, double rate)
        : Account(name, accNo, initBalance), interestRate(rate) {}

    void calculateInterest() {
        double interest = (balance * interestRate) / 100.0;
        balance += interest;
        cout << "Interest of Rs. " << interest << " credited at " << interestRate 
             << "%. Updated Balance: Rs. " << balance << endl;
    }

    void display() const {
        Account::display();
        cout << "Account Type: Savings Account" << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// Derived class for Checking Account
class CheckingAccount : public Account {
private:
    double overdraftLimit;
    double transactionFee;

public:
    CheckingAccount(string name, int accNo, double initBalance, double limit, double fee)
        : Account(name, accNo, initBalance), overdraftLimit(limit), transactionFee(fee) {}

    void withdraw(double amount) {
        double totalDebit = amount + transactionFee;
        if (totalDebit > 0 && (balance + overdraftLimit) >= totalDebit) {
            balance -= totalDebit;
            cout << "Withdrawn: Rs. " << amount << " (Fee: Rs. " << transactionFee << ")" << endl;
            cout << "Remaining Balance: Rs. " << balance << endl;
        } else {
            cout << "Withdrawal exceeds overdraft limit!" << endl;
        }
    }

    void display() const {
        Account::display();
        cout << "Account Type: Checking Account" << endl;
        cout << "Overdraft Limit: Rs. " << overdraftLimit << endl;
        cout << "Transaction Fee per Withdrawal: Rs. " << transactionFee << endl;
    }
};

int main() {
    cout << "=== SAVINGS ACCOUNT DEMO ===" << endl;
    SavingAccount sa("Sanskar Dhat", 1001, 5000.0, 5.0);
    sa.display();
    sa.deposit(1500.0);
    sa.withdraw(2000.0);
    sa.calculateInterest();

    cout << "\n=== CHECKING ACCOUNT DEMO ===" << endl;
    CheckingAccount ca("Sanskar Dhat", 2001, 3000.0, 1000.0, 20.0);
    ca.display();
    ca.deposit(2000.0);
    ca.withdraw(4500.0);
    ca.withdraw(2000.0); // Test overdraft limit breach

    return 0;
}
