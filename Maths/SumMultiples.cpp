//2652. Sum Multiples
#include<bits/stdc++.h>
using namespace std;
int sumOfMultiples(int n) {
    int sum=0;
    for (int i = 1; i <= n; i++)
    {
        if(i%3==0||i%5==0||i%7==0){
            cout<<i<<endl;
            sum=sum+i;
        }
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    cout<<endl;
    cout<<sumOfMultiples(n);
   return 0;
}