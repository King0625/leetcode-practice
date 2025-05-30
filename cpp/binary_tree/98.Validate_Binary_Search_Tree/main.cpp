#include <iostream>
#include <climits>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool solve(TreeNode *root, long max, long min)
{
  if (!root)
    return true;

  if (root->val >= max || root->val <= min)
  {
    return false;
  }
  else
  {
    return solve(root->left, root->val, min) && solve(root->right, max, root->val);
  }
}

bool isValidBST(TreeNode *root)
{
  long max = LONG_MAX;
  long min = LONG_MIN;

  return solve(root, max, min);
}

int main()
{
}