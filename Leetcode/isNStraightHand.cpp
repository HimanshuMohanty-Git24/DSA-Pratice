//846. Hand of Straights
#include<bits/stdc++.h>
using namespace std;
bool isNStraightHand(vector<int>& hand, int groupSize) {
    map<int, int> count;
    for(int i: hand)
        count[i]++;
    for(auto it: count)
    {
        if(count[it.first] > 0)
        {
            for(int i = groupSize - 1; i >= 0; i--)
            {
                if(count[it.first + i] < count[it.first])
                    return false;
                count[it.first + i] -= count[it.first];
            }
        }
    }
    return true;
}
int main()
{
    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    int groupSize = 3;
    cout<<isNStraightHand(hand, groupSize);
   return 0;
}