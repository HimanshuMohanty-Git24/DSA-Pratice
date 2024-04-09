// 2073. Time Needed to Buy Tickets
#include <bits/stdc++.h>
using namespace std;
int timeRequiredToBuy(vector<int> &tickets, int k)
{
    int n = tickets.size();
    queue<int> que;

    for (int i = 0; i < n; i++)
    {
        que.push(i);
    }

    int time = 0;

    while (!que.empty())
    {
        time++;
        int front = que.front();
        que.pop();

        tickets[front]--;

        if (k == front && tickets[front] == 0)
        {
            return time;
        }
        if (tickets[front] != 0)
        {
            que.push(front);
        }
    }

    return time;
}
int main()
{
    vector<int> tickets = {2, 3, 2};
    int k = 2;
    cout << timeRequiredToBuy(tickets, k) << endl;
    return 0;
}