// 2331. Evaluate Boolean Binary Tree
#include <bits/stdc++.h>
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

bool evaluateTree(TreeNode *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return root->val;
    }

    if (root->val == 2)
    {
        return evaluateTree(root->left) | evaluateTree(root->right);
    }

    return evaluateTree(root->left) & evaluateTree(root->right);
}
int main()
{
    // root = [2,1,3,null,null,0,1]
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    cout << evaluateTree(root) << endl;
    return 0;
}