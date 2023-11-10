//54. Spiral Matrix
#include<bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    int left=0,right=m-1;
    int top=0,bottom=n-1;
    vector<int> ans;

    while(top<=bottom&&left<=right){
        //right
        for(int i=left;i<=right;i++)
            ans.push_back(matrix[top][i]);
        top++;
        //down
        for(int i=top;i<=bottom;i++)
            ans.push_back(matrix[i][right]);
        right--;
        //left
        if(top<=bottom){
            for(int i=right;i>=left;i--)
                ans.push_back(matrix[bottom][i]);
            bottom--;
        }
        //up
        if(left<=right){
            for(int i=bottom;i>=top;i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }
    return ans;
}//Time Complexity: O(n*m) Space Complexity: O(1)
int main()
{
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans=spiralOrder(matrix);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
   return 0;
}