/*412. Fizz Buzz
 */
#include <bits/stdc++.h>
using namespace std;
vector<string> fizzBuzz(int n)
{
    vector<string> res;
    res.reserve(n); // Preallocate capacity for the vector

    for (int i = 1; i <= n; i++)
    {
        if (i % 15 == 0)
        { // Check for divisibility by 3 and 5
            res.push_back("FizzBuzz");
        }
        else if (i % 3 == 0)
        {
            res.push_back("Fizz");
        }
        else if (i % 5 == 0)
        {
            res.push_back("Buzz");
        }
        else
        {
            res.push_back(to_string(i));
        }
    }

    return res;
}
int main()
{
    int n;
    n = 15;
    vector<string> ans = fizzBuzz(n);
    for (auto &it : ans)
    {
        cout << it << ' ';
    }
    return 0;
}