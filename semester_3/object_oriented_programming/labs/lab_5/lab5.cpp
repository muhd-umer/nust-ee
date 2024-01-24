#include <iostream>
using namespace std;

class SavingsAccount {
private:
    double savingsBalance;

public:
    static double annualInterestRate;
    static void modifyInterestRate(double);

    void calculateMonthlyInterest(int n)
    {
        double monthlyInterest;
        monthlyInterest = savingsBalance * annualInterestRate / 12;
        savingsBalance += monthlyInterest;

        cout << "Saver " << n << "'s"
             << " Monthly Interest: " << monthlyInterest << endl;
        cout << "\tNew Balance: " << savingsBalance << endl;
    }

    SavingsAccount(double n)
        : savingsBalance(n)
    {
    }
    ~SavingsAccount() { cout << "Destructor was called!" << endl; }
};

double SavingsAccount::annualInterestRate = 0;
void SavingsAccount::modifyInterestRate(double n)
{
    annualInterestRate = n;
}

int main()
{
    SavingsAccount saver1(2000.00), saver2(3000.00);
    SavingsAccount saver3(saver1);

    // FIRST MONTH
    SavingsAccount::modifyInterestRate(0.03);
    cout << "\tCurrent Interest Rate: " << SavingsAccount::annualInterestRate << "\n\n";
    saver1.calculateMonthlyInterest(1);
    saver2.calculateMonthlyInterest(2);
    saver3.calculateMonthlyInterest(3);

    // NEXT MONTH
    cout << endl
         << "\t Next Month's Calculations\n\n";
    SavingsAccount::modifyInterestRate(0.07);
    cout << "\tCurrent Interest Rate: " << SavingsAccount::annualInterestRate << "\n\n";
    saver1.calculateMonthlyInterest(1);
    saver2.calculateMonthlyInterest(2);
    saver3.calculateMonthlyInterest(3);
    cout << "\n\n";

    return 0;
}

