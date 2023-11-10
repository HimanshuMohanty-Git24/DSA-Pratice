//48. Rotate Image
#include<bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    vector<vector<int>> ans( n , vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[j][n-1-i]=matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]=ans[i][j];
        }
    }
}//Time Complexity: O(n^2) Space Complexity: O(n^2)
//Inplace Solution
void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}//Time Complexity: O(n^2) Space Complexity: O(1)
int main()
{
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    cout<<"Before Rotation"<<endl;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix.size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    rotate(matrix);
    cout<<"After Rotation"<<endl;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix.size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
   return 0;
}