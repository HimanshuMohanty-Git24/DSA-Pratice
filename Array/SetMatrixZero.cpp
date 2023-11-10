//SET XER0 matrix
#include <bits/stdc++.h>
using namespace std;
//Solution 1
void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}


void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}//O(n*m) time and O(1) space

//SOlution 2
vector<vector<int>> zeroMatrix1(vector<vector<int>> &matrix, int n, int m){
    int col[m]={0};
    int row[n]={0};
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
    return matrix;
}//O(n*m) time and O(n+m) space
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();// no of rows
    int m = matrix[0].size();// no of cols
    cout<<"The initial matrix is: \n";
    for (int i = 0; i < n; i++) {
        cout << "[";
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "]" << endl;
    }
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: \n";
    for (int i = 0; i < n; i++) {
        cout << "[";
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
