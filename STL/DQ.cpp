#include<bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);//Faster than push back

    dq.push_front(3);
    dq.emplace_front(4);//Faster than push front

    dq.pop_back();
    dq.pop_front();

    dq.insert(dq.begin()+1,5);//Insert at index 1
    dq.erase(dq.begin()+1);//Erase at index 1

    dq.clear();//Clear the deque

    dq.resize(10);//Size of deque becomes 10

    dq.resize(5);//Size of deque becomes 5
   return 0;
}
//What is deque?
//Deque is a double ended queue.
//What is the difference between deque and vector?
//Deque is a double ended queue and vector is a dynamic array.
//What is the time complexity of deque?
//Time complexity of deque is O(1) for insertion and deletion at the end and O(n) for insertion and deletion at the middle.
//Why deque is faster than vector?
//Deque is faster than vector because it uses dynamic array in the background and it also uses linked list in the background.