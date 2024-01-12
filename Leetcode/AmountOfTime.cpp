//2385. Amount of Time for Binary Tree to Be Infected
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int result = INT_MIN;
int solve(TreeNode* root, int start) {
    if(root == NULL) return 0;
    int left = solve(root->left,start);
    int right = solve(root->right,start);
    int curr = root->val;
    if(curr == start) {
        result = max(left,right);
        return -1;
    }
    else if(left >=0 && right >=0) {
        return max(left,right)+1;
    }
    else{
        int d = abs(left)+abs(right);
        result = max(result,d);

        return min(left,right)-1;
    }

    return 0;
}
int amountOfTime(TreeNode* root, int start) {
    solve(root,start);
    return result;
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout<<amountOfTime(root,4)<<endl;
   return 0;
}