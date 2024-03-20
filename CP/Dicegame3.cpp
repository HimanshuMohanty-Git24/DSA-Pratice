//Dice Game 3
#include<bits/stdc++.h>
using namespace std;
void findmax(){
    int n;
    cin>>n;
    int ans;
    if(n%2==0){
        ans = (n/2*1)+n*6;
    }
    else{
        ans = (n/2*1)+2*((n/2)*6)+6;
    }
    cout<<ans<<endl;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        findmax();
    }
   return 0;
}