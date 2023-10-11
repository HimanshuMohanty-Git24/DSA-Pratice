//2180. Count Integers With Even Digit Sum
#include<bits/stdc++.h>
using namespace std;
int countEven(int num) {
    int ctr=0;
    for (int i = 1; i <= num; i++)
    {
        int sum=0;
        int temp=i;
        while(temp>0){
            sum=sum+temp%10;
            temp=temp/10;
        }
        if(sum%2==0){
            ctr++;
        }
    }
    return ctr;
}//Time complexity : O(nlogn) Space complexity : O(1)
int main()
{
    int num;
    cin>>num;
    cout<<countEven(num);
   return 0;
}