/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 *
 * https://leetcode-cn.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (48.54%)
 * Total Accepted:    5.6K
 * Total Submissions: 11.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 计算给定二叉树的所有左叶子之和。
 * 
 * 示例：
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 * 
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    int res = 0;

    void addLeft(TreeNode *root)
    {
        if (root->left == nullptr)
            return;
        if (root->left->left == nullptr && root->left->right == nullptr)
            res += root->left->val;
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        addLeft(root);
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return res;
    }
};
