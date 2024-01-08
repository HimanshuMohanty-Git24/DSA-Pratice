//938. Range Sum of BST
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL)
            return 0;
        if(root->val > high){
            return rangeSumBST(root->left,low,high);
        }
        if(root->val < low){
            return rangeSumBST(root->right,low,high);
        }
        else{
            return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
        }
}//Time Complexity: O(N) and Space Complexity: O(N)
int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);
    cout<<rangeSumBST(root,7,15);
   return 0;
}