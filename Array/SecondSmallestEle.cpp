//SeconD Largest And Second Smallest Element
#include<bits/stdc++.h>
using namespace std;
int secondlargestNum(vector<int> a,int n){
    int largest = a[0];
    int seclargest = INT_MIN;
    for(int i=1;i<n;i++){
        if(a[i]>largest){
            seclargest=largest;
            largest=a[i];
        }
        else if(a[i]<largest && a[i]>seclargest){
            seclargest=a[i];
        }
    }
    return seclargest;
}
int secondSmallest(vector<int> a,int n){
    int smallest = a[0];
    int secSmallest = INT_MAX;
    for(int i=1;i<n;i++){
        if(a[i]<smallest){
            secSmallest = smallest; 
            smallest=a[i];
        }
        else if(a[i]!= smallest && a[i]<secSmallest){
            secSmallest = a[i];
        }
    }
    return secSmallest;
}
vector<int> getSecondOrderElements(int n, vector<int> a) {
    int seclargest = secondlargestNum(a,n);
    int secsmallest = secondSmallest(a,n);
    return{seclargest,secsmallest};
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> ans = getSecondOrderElements(n,a);
    cout<<ans[0]<<" "<<ans[1]<<endl;
   return 0;
}