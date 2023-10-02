#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;
    s.push(1);
    s.emplace(2);//Faster than push
    s.push(3);
    s.emplace(4);//Faster than push
    s.push(5);
    s.emplace(6);//Faster than push
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
   return 0;
}
//What is stack?
//Stack is a LIFO data structure.
//What is the time complexity of stack?
//Time complexity of stack is O(1) for insertion and deletion.
//What is the space complexity of stack?
//Space complexity of stack is O(n).
//What is the use of stack?
//Stack is used in DFS(Depth First Search) and backtracking.