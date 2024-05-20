// 506. Relative Ranks
#include <bits/stdc++.h>
using namespace std;
vector<string> findRelativeRanks(vector<int> &score)
{
    vector<string> answer;
    vector<int> temp = score;
    sort(temp.begin(), temp.end(), greater<int>());
    unordered_map<int, string> rank;

    for (int i = 0; i < temp.size(); i++)
    {
        if (i == 0)
        {
            rank[temp[i]] = "Gold Medal";
        }
        else if (i == 1)
        {
            rank[temp[i]] = "Silver Medal";
        }
        else if (i == 2)
        {
            rank[temp[i]] = "Bronze Medal";
        }
        else
        {
            rank[temp[i]] = to_string(i + 1);
        }
    }
    for (int i = 0; i < score.size(); i++)
    {
        answer.push_back(rank[score[i]]);
    }
    return answer;
}
int main()
{
    vector<int> score = {5, 4, 3, 2, 1};
    vector<string> res = findRelativeRanks(score);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}