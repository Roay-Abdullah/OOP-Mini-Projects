#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
class Bank
{
private:
    double balance;
    double interestRate;
    double interest = 0;
    int transaction = 0;
    static int count;

public:
    Bank();
    Bank(double, double);
    void SetInterestRate(double);
    void makeDeposit(double);
    void withdraw(double);
    void calcInterest();
    void IncCount();
    int GetCount() const;
    double getInterestRate() const;
    double getBalance() const;
    double getInterest() const;
    int getTransactions() const;
};
int Bank::count = 0;
Bank::Bank()
{
    balance = 0;
    interestRate = 4.5;
    interest = 0;
    transaction = 0;
}
Bank::Bank(double Balance, double InterestRate)
{
    balance = Balance;
    interestRate = InterestRate;
}
void Bank::SetInterestRate(double InterestRate)
{
    interestRate = InterestRate;
}

void Bank::makeDeposit(double deposit)
{
    balance += deposit;
    cout << "Deposit successful." << endl;
    transaction++;
}
void Bank::withdraw(double withdraw)
{
    if (withdraw <= balance)
    {
        balance -= withdraw;
        cout << "Withdraw successful." << endl;
        transaction++;
    }
    else
    {
        cout << "Withdraw unsuccessful as withdrawal greater than balance." << endl;
    }
}
void Bank::calcInterest()
{
    interest = balance * (interestRate / 100);
    balance += interest;
    cout << "Interest added.";
}
void Bank::IncCount()
{
    count++;
}
int Bank::GetCount() const
{
    return count;
}
double Bank::getInterestRate() const
{
    return interestRate;
}
double Bank::getBalance() const
{
    return balance;
}
double Bank::getInterest() const
{
    return interest;
}
int Bank::getTransactions() const
{
    return transaction;
}
int main()
{
    Bank b;
    char opt;
    double deposit = 0, withdraw = 0;

    do
    {
        system("cls");
        cout << "  Menu   " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "A) Display the account balance" << endl;
        cout << "B) Display the number of transactions" << endl;
        cout << "C) Display interest earned this period" << endl;
        cout << "D) Make a deposit" << endl;
        cout << "E) Make a withdrawal" << endl;
        cout << "F) Add interest for this period" << endl;
        cout << "G) Exit the program" << endl;
        cout << endl;
        cout << "Number of times program has taken choice: " << b.GetCount() << endl;
        cout << "Enter the choice: ";
        cin >> opt;


        switch (opt)
        {
        case 'A':
        case 'a':
            cout << "The current balance is: " << b.getBalance() << endl;
            b.IncCount();
            break;
        case 'B':
        case 'b':
            cout << "Number of transactions: " << b.getTransactions() << endl;
            b.IncCount();
            break;
        case 'C':
        case 'c':
            cout << "Interest earned for this period: " << b.getInterest() << endl;
            b.IncCount();
            break;
        case 'D':
        case 'd':
            cout << "Enter the amount to deposit: ";
            cin >> deposit;
            b.makeDeposit(deposit);
            b.IncCount();
            break;
        case 'E':
        case 'e':
            cout << "Enter the amount to withdraw: ";
            cin >> withdraw;
            b.withdraw(withdraw);
            b.IncCount();
            break;
        case 'F':
        case 'f':
            b.calcInterest();
            b.IncCount();
            break;
        case 'G':
        case 'g':
            cout << "Exiting....." << endl;
            opt = 'g';
            break;
        default:
            cout << "Invalid option." << endl;
        }
        cout << endl;
        system("pause>0");

    } while (opt != 'g' && opt != 'G');


    return 0;
}
