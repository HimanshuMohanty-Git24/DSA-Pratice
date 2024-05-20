// 2011. Final Value of Variable After Performing Operations
#include <bits/stdc++.h>
using namespace std;
int finalValueAfterOperations(vector<string> &operations)
{
    int sum = 0;
    for (int i = 0; i < operations.size(); i++)
    {
        for (int j = 0; j < operations[i].length(); j++)
        {
            if (operations[i][j] == '-')
            {
                sum--;
                break;
            }
            else if (operations[i][j] == '+')
            {
                sum++;
                break;
            }
        }
    }
    return sum;
}
int main()
{
    vector<string> operations = {"X++", "++X", "--X", "X--"};
    cout << finalValueAfterOperations(operations) << endl;
    return 0;
}