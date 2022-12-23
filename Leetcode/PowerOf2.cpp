#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n)
{
    for (int i = 0; i < 32; i++) // As the int ranges from 2^32->-2^32 we find each power of 2 till 2^32
    {
        if (n == pow(2, i)) // if the power matches our input value
        {                   // For other power we can change 2 to any number
            return true;    // we return true
        }
    }
    return false; // else we retuen false
}
int main()
{
    if (isPowerOfTwo(14))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}