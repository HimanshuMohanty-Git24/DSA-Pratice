//Merge two array in sorted order and unique element
#include<bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    int i=0,j=0;
    while(i<A.size() && j<B.size()){
        if(A[i]<B[j]){
            ans.push_back(A[i]);
            i++;
        }
        else if(A[i]>B[j]){
            ans.push_back(B[j]);
            j++;
        }
        else{
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }
    while(i<A.size()){
        ans.push_back(A[i]);
        i++;
    }
    while(j<B.size()){
        ans.push_back(B[j]);
        j++;
    }
    return ans;
}
int main()
{
    vector<int> A={1,2,3,4,5};
    vector<int> B={2,3,4,5,6};
    vector<int> ans=merge(A,B);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
   return 0;
}