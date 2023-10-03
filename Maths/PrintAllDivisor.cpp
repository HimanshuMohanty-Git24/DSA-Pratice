#include<bits/stdc++.h>
using namespace std;
int sumOfAllDivisors(int n){
	int Resum=0;
    for (int i = 1; i <= n; i++)
    {
        if(n%i==0){
            Resum=Resum+i;
        }
    }
    return Resum;
}
int main()
{
    int n;
    cin>>n;
    cout<<sumOfAllDivisors(n);
    return 0;
}