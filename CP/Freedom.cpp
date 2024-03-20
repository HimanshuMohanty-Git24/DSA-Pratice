//Freedom
#include <bits/stdc++.h>
using namespace std;
bool isaArithemeticProgression(int a , int b, int c){
    if(a-b==c-b){
        return true;
    }
    else{
        return false;
    }
}
void Freedom(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ctr=0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i; j < n; j++)
        {
            int a,b,c;
            a= arr[i]-arr[j];
            b= arr[i]+arr[j];
            c= arr[j]-arr[i];
            if(isaArithemeticProgression(a,b,c)){
                ctr++;
            }
        }
    }
    cout<<ctr<<endl;
}
int main() {
	int T;
    cin>>T;
    while(T--){
        Freedom();
    }

}
