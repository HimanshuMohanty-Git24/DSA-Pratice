#include<bits/stdc++.h>
using namespace std;
int calcGCD(int n, int m){
   int gcd=1;
   int min;
   if(n<m){
      min=n;
   }
   else{
      min=m;
   }
   for(int i=1;i<=min;i++){
      if(n%i==0&&m%i==0){
         gcd =i;
      }
   }
   return gcd;
}
int main()
{
   int n ,m;
   cin>>n>>m;
   int res= calcGCD(n,m);
   cout<<res<<endl;
   return 0;
}