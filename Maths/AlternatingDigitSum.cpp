//2544. Alternating Digit Sum
#include<bits/stdc++.h>
using namespace std;
int alternateDigitSum(int n) {
    int count = floor(log10(n) + 1);
    int arr[count];
    for (int i = count-1; i >=0; i--)
    {
        arr[i]=n%10;
        n=n/10;
    }
    int sum=0;
    for (int i = 0; i < count; i++)
    {
        if(i%2==0){
            sum=sum+1*arr[i];
        }
        else{
            sum=sum+(-1*arr[i]);
        }
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    cout<<alternateDigitSum(n);
    return 0;
}