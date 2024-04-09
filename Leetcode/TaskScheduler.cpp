//621. Task Scheduler
#include<bits/stdc++.h>
using namespace std;
int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26,0);
    for(char c:tasks)
        freq[c-'A']++;
    sort(freq.begin(),freq.end());
    int maxFreq = freq[25]-1;//maxFreq-1 is the number of slots required for most frequent task without the last task as it will be added at the end
    int idleSlots = maxFreq*n;//ideal slots frequired by most frequent task
    for(int i=24;i>=0;i--)
        idleSlots -= min(freq[i],maxFreq);
    return idleSlots>0?idleSlots+tasks.size():tasks.size();
}
int main()
{
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout<<leastInterval(tasks,n);
   return 0;
}