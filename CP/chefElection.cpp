//Election Hopes
#include<bits/stdc++.h>
using namespace std;
bool isChefDominant(int x,int y){
    if(x>=2*y){
        return true;
    }
    return false;
}
int main()
{
    int x,y;
    cin>>x>>y;
    if(isChefDominant(x,y)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
   return 0;
}