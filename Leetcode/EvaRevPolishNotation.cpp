//150. Evaluate Reverse Polish Notation
#include<bits/stdc++.h>
using namespace std;
int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for(int i=0;i<tokens.size();i++)
    {
        if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(tokens[i]=="+")
            {
                s.push(a+b);
            }
            else if(tokens[i]=="-")
            {
                s.push(b-a);
            }
            else if(tokens[i]=="*")
            {
                s.push(a*b);
            }
            else if(tokens[i]=="/")
            {
                s.push(b/a);
            }
        }
        else
        {
            s.push(stoi(tokens[i]));
        }
    }
    return s.top();
}
int main()
{
    int n;
    cin>>n;
    vector<string> tokens(n);
    for(int i=0;i<n;i++)
    {
        cin>>tokens[i];
    }
    cout<<evalRPN(tokens);
   return 0;
}