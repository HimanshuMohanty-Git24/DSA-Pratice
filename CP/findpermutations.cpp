#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

void findPermutations()
{
    int n, target;
    cin >> n >> target;
    vector<int> permutation;

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += abs(i - (n - i + 1));
        permutation.push_back(i);
    }

    if (target % 2 == 1 || sum < target)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        int index = 0;
        int remaining = n;
        while (target > (remaining - 1) * 2)
        {
            swap(permutation[index], permutation[n - index - 1]);
            target -= (remaining - 1) * 2;
            remaining -= 2;
            index++;
        }

        target /= 2;
        swap(permutation[index], permutation[index + target]);

        for (const auto &num : permutation)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

signed main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        findPermutations();
    }

    return 0;
}
