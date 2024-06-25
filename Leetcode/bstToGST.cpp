// 1038. Binary Search Tree to Greater Sum Tree
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
int sum = 0;

void traverse(TreeNode *root)
{
    if (root)
    {
        traverse(root->right);
        sum += root->val;
        root->val = sum;
        traverse(root->left);
    }
}
TreeNode *bstToGst(TreeNode *root)
{
    traverse(root);
    return root;
}
int main()
{
    /*
    Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
    Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
    */
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->left->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(8);
    TreeNode *res = bstToGst(root);

    // Print the output:
    TreeNode *temp = res;
    stack<TreeNode *> s;
    while (temp || !s.empty())
    {
        while (temp)
        {
            s.push(temp);
            temp = temp->right;
        }
        temp = s.top();
        s.pop();
        cout << temp->val << " ";
        temp = temp->left;
    }
    return 0;
}