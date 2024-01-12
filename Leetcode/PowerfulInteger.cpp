//100163. Count the Number of Powerful Integers
#include<bits/stdc++.h>
using namespace std;
long long numberOfPowerfulInt(long long L, long long R, int k, string s) {
        typedef long long LL;
        LL rem = 0, mod = 1;
        for(char ch: s) {
            int o = ch - '0';
            if(o > k)
                return 0;
            rem = rem * 10 + o;
            mod *= 10;
        }
        L = L <= rem ? 0 : (L - rem - 1) / mod + 1;
        R = R < rem ? -1 : (R - rem) / mod;
        if(L > R)
            return 0;
        auto calc = [&](LL upp) {
            LL ret = 0;
            string s = to_string(upp);
            int n = s.size();
            vector<LL> pw = {1LL};
            for(int i = 1; i < n; ++i)
                pw.push_back(pw.back() * (k + 1));
            for(int i = 0; i < n; ++i) {
                int d = s[i] - '0';
                ret += (min(d - 1, k) + 1) * pw[n - 1 - i];
                if(d > k)
                    break;
            }
            return ret;
        };
        return calc(R + 1) - calc(L);
}
/*
Logic:
1. Find the upper limit of the number of digits in the powerful integer.
2. Find the lower limit of the number of digits in the powerful integer.
3. Find the number of powerful integers in the range [lower limit, upper limit].
4. Find the number of powerful integers in the range [L, R].
5. Return the answer.
*/
int main()
{
    long long start = 1, finish = 6000;
    int limit = 4;
    string s = "124";
    cout << numberOfPowerfulInt(start, finish, limit, s) << endl;
   return 0;
}