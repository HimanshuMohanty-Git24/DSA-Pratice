//826. Most Profit Assigning Work
#include<bits/stdc++.h>
using namespace std;
int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        for(int i=0;i<difficulty.size();i++)
        {
            jobs.push_back({difficulty[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        sort(worker.begin(),worker.end());
        int i=0,j=0,maxProfit=0,result=0;
        while(i<jobs.size() && j<worker.size())
        {
            if(jobs[i].first<=worker[j])
            {
                maxProfit = max(maxProfit,jobs[i].second);
                i++;
            }
            else
            {
                result+=maxProfit;
                j++;
            }
        }
        while(j<worker.size())
        {
            result+=maxProfit;
            j++;
        }
        return result;
}
int main()
{
    vector<int> difficulty = {2,4,6,8,10};
    vector<int> profit = {10,20,30,40,50};
    vector<int> worker = {4,5,6,7};
    cout<<maxProfitAssignment(difficulty,profit,worker);
   return 0;
}