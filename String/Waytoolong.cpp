//Problem:	71A - Way Too Long Words
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> str(n); // Resize the vector to size n
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    for(int i=0;i<n;i++){
        if(str[i].length()>10){
            cout<<str[i][0]<<str[i].length()-2<<str[i][str[i].length()-1]<<endl;
        }
        else{
            cout<<str[i]<<endl;
        }
    }
}