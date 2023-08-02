//1431. Kids With the Greatest Number of Candies
#include<bits/stdc++.h>
using namespace std;
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> res;
    int max = *max_element (candies.begin(), candies.end());
    for (int i = 0; i < candies.size(); i++)
    {
        if(candies[i]+extraCandies>=max){
            res.push_back(true);
        }
        else{
            res.push_back(false);
        }
    }
    return res;
}
int main()
{
    vector<int> candies={4,2,1,1,2};
    int extraCandies=1;
    vector<bool> res=kidsWithCandies(candies,extraCandies);
    for(auto i:res){
        if(i){
            cout<<"true ";
        }
        else{
            cout<<"false ";
        }
    }
    return 0;
}