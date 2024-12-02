/*
Hill Climbing
Hill climbing is a heuristic search used for mathematical optimization problems. It is a variant of the gradient ascent method.
 Starting from a random point, the algorithm takes steps in the direction of increasing elevation or value to find the peak of
 the mountain or the optimal solution to the problem. However, it may settle for a local maximum and not reach the global maximum.
*/
#include<bits/stdc++.h>
using namespace std;

int f(int x){
    return x*x - 4*x + 4;
}

int hillClimbing(int x){
    int dx = 1;
    while(true){
        if(f(x+dx) > f(x)){
            x = x + dx;
        }
        else if(f(x-dx) > f(x)){
            x = x - dx;
        }
        else{
            break;
        }
    }
    return x;
}

int main(){
    int x = 0;
    cout<<"The peak of the mountain is at x = "<<hillClimbing(x)<<endl;
    return 0;
}