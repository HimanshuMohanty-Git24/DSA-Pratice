//502. IPO
#include<bits/stdc++.h>
using namespace std;
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();
    vector<pair<int,int>> vec(n);
    for(int i=0;i<n;i++)
    {
        vec[i] = {capital[i],profits[i]};
    }
    sort(vec.begin(),vec.end());
    int i=0;
    priority_queue<int> pq;

    while(k--){
        while(i<n && vec[i].first<=w)
        {
            pq.push(vec[i].second);
            i++;
        }
        if(pq.empty())
        {
            return w;
        }
        w+=pq.top();
        pq.pop();
    }

    return w;

}
int main()
{
    vector<int> profits = {1,2,3};
    vector<int> capital = {0,1,1};
    int k = 2;
    int w = 0;
    cout<<findMaximizedCapital(k,w,profits,capital);
   return 0;
}