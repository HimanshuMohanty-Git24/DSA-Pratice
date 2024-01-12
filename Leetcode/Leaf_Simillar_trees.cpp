// 872. Leaf-Similar Trees
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

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    vector<int> v1, v2;
    stack<TreeNode *> s;
    s.push(root1);
    while (!s.empty())
    {
        TreeNode *temp = s.top();
        s.pop();
        if (temp->left == NULL && temp->right == NULL)
            v1.push_back(temp->val);
        if (temp->right)//if right child is present then push it in stack first
            s.push(temp->right);//because we want left child to be pop first
        if (temp->left)//if left child is present then push it in stack
            s.push(temp->left);//because we want left child to be pop first
    }
    s.push(root2);
    while (!s.empty())
    {
        TreeNode *temp = s.top();
        s.pop();
        if (temp->left == NULL && temp->right == NULL)
            v2.push_back(temp->val);
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
    if (v1.size() != v2.size())
        return false;
    for (int i = 0; i < v1.size(); i++)
        if (v1[i] != v2[i])
            return false;
    return true;
}//Time Complexity: O(n) and Space Complexity: O(n)
/*
Logic:
1. Push root1 in stack and pop it and check if it is leaf node then push it in vector v1.
2. Push root2 in stack and pop it and check if it is leaf node then push it in vector v2.
3. If size of v1 and v2 is not equal then return false
4. Else check if v1[i] != v2[i] then return false
5. Else return true
*/
int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(2);

    if (leafSimilar(root1, root2))
        cout << "True";
    else
        cout << "False";
    return 0;
}