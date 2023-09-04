//1732. Find the Highest Altitude
#include<bits/stdc++.h>
using namespace std;
int largestAltitude(vector<int>& gain) {
    vector<int> res;
    res.push_back(0);
    int sum=0;
    for (int i = 0; i < gain.size(); i++)
    {
        sum=sum+gain[i];
        res.push_back(sum);
    }
    int max = *max_element (res.begin(), res.end());
    return max;
}
int main()
{
    vector<int> gain={-5,1,5,0,-7};
    cout<<largestAltitude(gain);
    return 0;
}