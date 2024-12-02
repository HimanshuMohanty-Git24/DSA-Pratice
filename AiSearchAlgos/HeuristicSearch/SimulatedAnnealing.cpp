/*
Simulated Annealing
Inspired by the process of annealing in metallurgy, simulated annealing is a probabilistic technique for approximating the global optimum
of a given function. It allows the algorithm to jump out of any local optimums in search of the global optimum by probabilistically deciding
whether to accept or reject a higher-cost solution during the early phases of the search.
*/
#include<bits/stdc++.h>
using namespace std;

// Function to calculate the value of the objective function
int f(int x){
    return x*x - 4*x + 4;
}

// Function to calculate the acceptance probability
double acceptanceProbability(int delta, double T){
    if(delta < 0){
        return 1.0;
    }
    return exp(-delta/T);
}

// Function to perform simulated annealing
int simulatedAnnealing(int x){
    double T = 1000.0; // Initial temperature
    double alpha = 0.9; // Cooling rate
    while(T > 0.1){
        int xNew = x + (rand()%21 - 10); // Randomly select a new solution
        int delta = f(xNew) - f(x); // Calculate the change in the objective function
        if(acceptanceProbability(delta,T) > (rand()%100)/100.0){ // Accept the new solution with a certain probability
            x = xNew;
        }
        T *= alpha; // Cool down the temperature
    }
    return x;
}

int main(){
    int x = 0;
    cout<<"The peak of the mountain is at x = "<<simulatedAnnealing(x)<<endl;
    return 0;
}