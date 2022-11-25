#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int penalty_8102 = 5.00;

class Account_8102
{

    int balance_8102;

public:
    Account_8102(int money_8102 = 0)
    {
        balance_8102 = money_8102;
    }
    void add_8102(int money_8102)
    {
        balance_8102 = money_8102 + balance_8102;
        cout << balance_8102 << endl;
    }
    void Withdraw(int money_8102)
    {
        if (money_8102 > balance_8102)
            balance_8102 += penalty_8102;
        else
            balance_8102 -= money_8102;
    }
    int GetBalance_8102()
    {
        return balance_8102;
    }
};

Account_8102 a_8102[2];

void deposit_8102(int amount_8102, string account_8102)
{

    if (account_8102 == "S" || account_8102 == "s")
        a_8102[0].add_8102(amount_8102);
    else
        a_8102[1].add_8102(amount_8102);
}

void withdraw_8102(int amount_8102, string account_8102)
{

    if (account_8102 == "S" || account_8102 == "s")
        a_8102[0].Withdraw(amount_8102);
    else
        a_8102[1].Withdraw(amount_8102);
}

void printBalances_8102()
{

    cout << "The current balance_8102 in savings_8102 is: " << a_8102[0].GetBalance_8102() << endl;
    cout << "The current balance_8102 in checking_8102 is: " << a_8102[1].GetBalance_8102() << endl
         << endl;
}

int main()
{
    string accountChoice_8102;
    int selection_8102;
    int transaction_8102 = 0;
    cout << fixed << showpoint << setprecision(2);

    do
    {
        cout << "Sumit Kumar Samal...2128102" << endl;
        cout << "Please make a selection:" << endl;
        cout << "1) Deposit" << endl;
        cout << "2) Withdraw" << endl;
        cout << "3) Print balances" << endl;
        cout << "4) Quit" << endl;
        cin >> selection_8102;

        if (selection_8102 == 1)
        {
            cout << endl
                 << "Please select the account_8102 you would like to perform operations on(S or C):" << endl;
            cin >> accountChoice_8102;
            cout << endl
                 << "Please enter the amount_8102 to be deposited:" << endl;
            cin >> transaction_8102;
            cout << endl;

            deposit_8102(transaction_8102, accountChoice_8102);
        }

        else if (selection_8102 == 2)
        {
            cout << endl
                 << "Please select the account_8102 you would like to perform operations on(S or C):" << endl;
            cin >> accountChoice_8102;
            cout << endl
                 << "Please enter the amount_8102 to be withdrawn:" << endl;
            cin >> transaction_8102;
            cout << endl;

            withdraw_8102(transaction_8102, accountChoice_8102);
        }
        else if (selection_8102 == 3)
            printBalances_8102();
        else
            cout << "Closing program " << endl;
    } while (selection_8102 != 4);

    system("pause");
    return 0;
}