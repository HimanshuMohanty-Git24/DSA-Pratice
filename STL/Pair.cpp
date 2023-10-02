#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, int> p ={1,3};
    cout<<p.first<<" "<<p.second<<endl;
    pair<int,pair<int,int>> q ={1,{3,4}};
    cout<<q.first<<" "<<q.second.first<<" "<<q.second.second<<endl;
    pair<int, int> parr[]={{1,2},{2,5},{5,1}};
    cout<<parr[1].second;
    return 0;
}
//What are pairs?
//Ans: Pairs are a simple container defined in <utility> header consisting of two data elements or objects.
//How does Pair work in the background ?
//Ans: Pair is implemented as a structure with two data members, the first one is called first and the second one is called second in which first is the key and second is the value of the Pair, and a constructor to initialize the variables.
//What are the advantages of using pairs?
//Ans: Pairs can be used to return two values from a function in C++.
//What are the disadvantages of using pairs?
//Ans: Pairs can hold only two values at a time.
//What are the applications of pairs?
//Ans: Pairs are used to return two values from a function in C++.
//Where can pair be used in real world software ?
//Ans: Pairs can be used to return two values from a function in C++. eg: In Dijkstra’s shortest path algorithm, we use a min heap to store the vertices. The min heap is based on the distance of each vertex from the source. The distance is used as first item of pair and vertex number is used as second item of pair.