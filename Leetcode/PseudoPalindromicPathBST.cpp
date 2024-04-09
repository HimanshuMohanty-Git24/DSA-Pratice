//1457. Pseudo-Palindromic Paths in a Binary Tree
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
int result=0;
void solve(TreeNode* root,vector<int>& count)
{
   if(root==NULL)
   {
      return;
   }
   count[root->val]++;
   if(root->left==NULL && root->right==NULL)//Leaf Node
   {
      int odd=0;
      for(int i=1;i<=9;i++)
      {
         if(count[i]%2!=0)//odd
         {
            odd++;
         }
      }
      if(odd<=1)
      {
         result++;
      }
   }
   solve(root->left,count);
   solve(root->right,count);
   count[root->val]--;//Backtrack resting the count
}

int pseudoPalindromicPaths (TreeNode* root) {
   vector<int> count(10,0);

   solve(root,count);
   return result;
}//Time Complexity: O(N) Space Complexity: O(N)
//using Bit Manipulation
int result1=0;
void solve1(TreeNode* root,int count)
{
   if(root==NULL)
   {
      return;
   }
   count=count^(1<<root->val);
   if(root->left==NULL && root->right==NULL)//Leaf Node
   {
      if((count&(count-1))==0)//check if count is power of 2
      {
         result1++;
      }
   }
   solve1(root->left,count);
   solve1(root->right,count);
}
int pseudoPalindromicPaths1 (TreeNode* root) {
   int count=0;
   solve1(root,count);
   return result1;
}
int main()
{
      TreeNode* root = new TreeNode(2);
      root->left = new TreeNode(3);
      root->right = new TreeNode(1);
      root->left->left = new TreeNode(3);
      root->left->right = new TreeNode(1);
      root->right->right = new TreeNode(1);
      cout<<pseudoPalindromicPaths(root);
   return 0;
}