//118. Pascal's Triangle
#include<bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    return (n==1 || n==0) ? 1: n * factorial(n - 1);
}//Time complexity:O(n) Auxiliary Space:O(1)
int elementFind(int r,int c){//Finding the element at rth row and cth column of pascal's triangle
    return factorial(r)/(factorial(c)*factorial(r-c));
}//Time complexity:O(r) Auxiliary Space:O(1)
//Print a Row of Pascal's Triangle
vector<int> RowPrint(int n){
    vector<int> v;
    for(int i=0;i<=n;i++){
        v.push_back(elementFind(n,i));
    }
    return v;
}//Time complexity:O(n^2) Auxiliary Space:O(n)
//Optimised version of above code:
vector<int> RowPrint1(int n){
    vector<int> v;
    int res=1;
    v.push_back(res);
    for(int i=1;i<=n;i++){
        res=res*(n-i+1)/i;
        v.push_back(res);
    }
    return v;
}//Time complexity:O(n) Auxiliary Space:O(n)
//Print the entire Pascal's Triangle
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> v;
    for(int i=1;i<=numRows;i++){
        v.push_back(RowPrint(i));
    }
    return v;
}
int main()
{
    int r=4;
    int c=2;
    cout<<elementFind(r,c)<<endl;
    vector<int> v=RowPrint(4);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
   return 0;
}