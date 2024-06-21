//1052. Grumpy Bookstore Owner
#include<bits/stdc++.h>
using namespace std;
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int satisfied = 0;
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0){
                satisfied += customers[i];
            }
        }
        int maxSatisfied = 0;
        int currentSatisfied = 0;
        for(int i = 0; i < minutes; i++){
            if(grumpy[i] == 1){
                currentSatisfied += customers[i];
            }
        }
        maxSatisfied = max(maxSatisfied, currentSatisfied);
        for(int i = minutes; i < n; i++){
            if(grumpy[i] == 1){
                currentSatisfied += customers[i];
            }
            if(grumpy[i - minutes] == 1){
                currentSatisfied -= customers[i - minutes];
            }
            maxSatisfied = max(maxSatisfied, currentSatisfied);
        }
        return satisfied + maxSatisfied;
}
int main()
{
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};
    int minutes = 3;
    cout<<maxSatisfied(customers, grumpy, minutes);
   return 0;
}