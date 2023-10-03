#include<bits/stdc++.h>
using namespace std;

int sumOfAllDivisors(int n){
    int Resum=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if(i%j==0){
                Resum=Resum+j;
            }
        }
    }
    return Resum;
}

int sumOfAllDivisorsOptimised(int n){
    int ans=0;
    int i=1;
    while(i<=n){
        ans = ans + i*(n/i);
        i++;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int res1 = sumOfAllDivisors(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<"Execution time of sumOfAllDivisors: "<<cpu_time_used<<" seconds"<<endl;

    start = clock();
    int res2 = sumOfAllDivisorsOptimised(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<"Execution time of sumOfAllDivisorsOptimised: "<<cpu_time_used<<" seconds"<<endl;

    cout<<res1<<" "<<res2;
    return 0;
}