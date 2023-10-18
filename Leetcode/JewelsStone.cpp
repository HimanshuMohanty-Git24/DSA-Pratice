//771. Jewels and Stones
#include<bits/stdc++.h>
using namespace std;
int numJewelsInStones(string jewels, string stones) {
        int ctr=0;
        for (int i = 0; i < jewels.size(); i++)
        {
            for (int j = 0; j < stones.size(); j++)
            {
                if(jewels[i]==stones[j]){
                    ctr++;
                }
            }
        }
        return ctr;
}
int main()
{
    string jewels, stones;
    cin>>jewels>>stones;
    cout<<numJewelsInStones(jewels, stones);
    return 0;
}