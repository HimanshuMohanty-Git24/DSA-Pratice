//100095. Last Visited Integers

// Input: words = ["1","2","prev","prev","prev"]
// Output: [2,1,-1]
// Explanation: 
// For "prev" at index = 2, last visited integer will be 2 as here the number of consecutive "prev" strings is 1, and in the array reverse_nums, 2 will be the first element.
// For "prev" at index = 3, last visited integer will be 1 as there are a total of two consecutive "prev" strings including this "prev" which are visited, and 1 is the second last visited integer.
// For "prev" at index = 4, last visited integer will be -1 as there are a total of three consecutive "prev" strings including this "prev" which are visited, but the total number of integers visited is two.
// Constraints:

// 1 <= words.length <= 100
// words[i] == "prev" or 1 <= int(words[i]) <= 100
#include<bits/stdc++.h>
using namespace std;
vector<int> lastVisitedIntegers(vector<string>& words) {
    vector<int> ans;
    stack<int> s;
    int prevCounter=0;
    for(int i=0;i<words.size();i++)
    {
        if(words[i]=="prev")
        {
            if(prevCounter>=s.size())
            {
                ans.push_back(-1);
            }
            else
            {
                if(prevCounter==0)
                {
                    ans.push_back(s.top());
                    prevCounter++;
                }
                else
                {
                    s.pop();
                    ans.push_back(s.top());
                    prevCounter=0;
                }
            }
        }
        else
        {
            s.push(stoi(words[i]));
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;i++)
    {
        cin>>words[i];
    }
    vector<int> ans=lastVisitedIntegers(words);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
   return 0;
}