//1342. Number of Steps to Reduce a Number to Zero
#include<bits/stdc++.h>
using namespace std;
int numberOfSteps(int num) {
    int ctr=0;
    while (num>0)
    {
        if(num%2==0){
            num=num/2;
            ctr++;
        }
        else{
            num = num-1;
            ctr++;
        }
    }
    return ctr;
}
int main()
{
    int num;
    cin>>num;
    cout<<numberOfSteps(num);
   return 0;
}