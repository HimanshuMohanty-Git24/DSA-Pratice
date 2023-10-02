#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    q.push(1);
    q.emplace(2);//Faster than push
    q.push(3);
    q.emplace(4);//Faster than push
    q.push(5);
    q.emplace(6);//Faster than push
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
   return 0;
}
//What is queue?
//Queue is a FIFO data structure.
//What is the time complexity of queue?
//Time complexity of queue is O(1) for insertion and deletion.
//What is the space complexity of queue?
//Space complexity of queue is O(n).
//What is the use of queue?
//Queue is used in BFS(Breadth First Search).