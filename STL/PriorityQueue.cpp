#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;
    pq.push(1);
    pq.emplace(2);//Faster than push
    pq.push(3);
    pq.emplace(4);//Faster than push
    pq.push(5);
    pq.emplace(6);//Faster than push
    pq.pop();
    cout<<pq.top()<<endl;
    cout<<pq.size()<<endl;
    cout<<pq.empty()<<endl;
   return 0;
}
//What is priority queue?
//Priority queue is a data structure which is similar to queue but in this data structure elements are arranged in decreasing order.    
//What is uses in the background of priority queue?
//Priority queue uses heap data structure in the background. a tree based data structure.
//What is the time complexity of priority queue?
//Time complexity of priority queue is O(logn) for insertion and deletion.
//What is the space complexity of priority queue?
//Space complexity of priority queue is O(n).