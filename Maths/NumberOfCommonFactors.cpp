//2427. Number of Common Factors
#include<bits/stdc++.h>
using namespace std;
int commonFactors(int a, int b) {
    int cfCounter = 0;
    int n;
    if(a>b){
        n=b;
    }
    else{
        n=a;
    }
    for (int i = 1; i <= n; i++)
    {
        if(a%i==0&&b%i==0){
            cfCounter++;
        }
    }
    return cfCounter;
}//Time Complexity: O(n) Space Complexity: O(1)
//Optimized Approach
int commonFactors2(int a, int b) {
    int cfCounter = 0;
    int n;
    if(a>b){
        n=b;
    }
    else{
        n=a;
    }
    for (int i = 1; i <= sqrt(n); i++)
    {
        if(a%i==0&&b%i==0){
            cfCounter++;
        }
        if(i!=n/i){
            if(a%(n/i)==0&&b%(n/i)==0){
                cfCounter++;
            }
        }
    }
    return cfCounter;
}//Time Complexity: O(sqrt(n)) Space Complexity: O(1)
int main()
{
    int a, b;
    cin >> a >> b;
    cout << commonFactors(a, b);
    cout << commonFactors2(a, b);
   return 0;
}