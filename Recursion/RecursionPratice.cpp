#include<bits/stdc++.h>
using namespace std;
int ctr=0;
void Name(int n){
    if(ctr==5){
        return;
    }
    cout<<"Himanshu"<<endl;
    ctr++;
    Name(n-1);
}
void numRev(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    numRev(n-1);
}
void num(int n){
    if(n==0){
        return;
    }
    num(n-1);
    cout<<n<<endl;
}
int sum(int n){
    if(n==0){
        return 0;
    }
    return n+sum(n-1);
}
int fact(int n){
    if(n==1){
        return 1;
    }
    return n*fact(n-1);
}
void swap(int *n,int *m){
    int temp = *n;
    *n = *m;
    *m = temp;
}
void reverseArr(int *arr,int l,int h){
    if(l>=h) return;
    swap(arr[l],arr[h]);
    reverseArr(arr,l+1,h-1);
}
bool palindrome(string s){
    if(s.length()==0 || s.length()==1){
        return true;
    }
    if(s[0]==s[s.length()-1]){
        return palindrome(s.substr(1,s.length()-2));
    }
    return false;
}
int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}//Timecomplexity: O(2^n)
int main()
{
    Name(5);
    cout<<endl;
    numRev(10);
    cout<<endl;
    num(10);
    cout<<endl;
    cout<<sum(10);
    cout<<endl;
    cout<<fact(5);
    int arr[] ={1,2,3,4,5,6,7,8,9,10};
    cout<<endl;
    reverseArr(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<palindrome("MADSAM");
    cout<<endl;
    cout<<fibonacci(7);
    cout<<endl;
    return 0;
}
