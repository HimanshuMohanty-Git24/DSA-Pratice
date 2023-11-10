//73. Set Matrix Zeroes
#include<bits/stdc++.h>
using namespace std;
void setZeroes1(vector<vector<int>>& matrix) {//O(n*m) time and O(n+m) space
    int n = matrix.size();// no of rows
    int m = matrix[0].size();// no of cols
    vector<int> col(m,0);
    vector<int> row(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                col[j]=1;
                row[i]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(col[j]==1 || row[i]==1){
                matrix[i][j]=0;
            }
        }
    }
}//O(n*m) time and O(n+m) space
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();// no of rows
    int m = matrix[0].size();// no of cols
    int col0=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                if(j!=0){
                    matrix[0][j]=0;
                }
                else{
                    col0=0;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]!=0){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
    if(matrix[0][0]==0){
        for(int j=0;j<m;j++){
            matrix[0][j]=0;
        }
    }
    if(col0==0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }
}//O(n*m) time and O(1) space
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(matrix);
    //Print matrix:
    int n = matrix.size();// no of rows
    int m = matrix[0].size();// no of cols
    cout<<"Final matrix is: \n";
    for (int i = 0; i < n; i++) {
        cout << "[";
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}