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
int maxDiff;
void maxDiffUtil(TreeNode *root, TreeNode *child)
{
    if (root == NULL || child == NULL)
        return;
    maxDiff = max(maxDiff, abs(root->val - child->val));

    maxDiffUtil(root, child->left);
    maxDiffUtil(root, child->right);
}
void maxDiffFun(TreeNode *root)
{
    if (root == NULL)
        return;
    maxDiffUtil(root, root->left);
    maxDiffUtil(root, root->right);

    maxDiffFun(root->left);
    maxDiffFun(root->right);
}
int maxAncestorDiff1(TreeNode *root)
{
    maxDiff = -1;
    maxDiffFun(root);
    return maxDiff;
}
// Optimal aproach:
int findMaxDiff(TreeNode *root, int minV, int maxV)
{
    if (!root)
        return abs(minV - maxV);

    minV = min(root->val, minV);
    maxV = max(root->val, maxV);

    int l = findMaxDiff(root->left, minV, maxV);
    int r = findMaxDiff(root->right, minV, maxV);

    return max(l, r);
}

int maxAncestorDiff(TreeNode *root)
{
    int minV = root->val;
    int maxV = root->val;

    return findMaxDiff(root, minV, maxV);
}
int main()
{
    // root = [8,3,10,1,6,null,14,null,null,4,7,13]
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(14);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(13);

    cout << maxAncestorDiff(root) << endl;
    return 0;
}