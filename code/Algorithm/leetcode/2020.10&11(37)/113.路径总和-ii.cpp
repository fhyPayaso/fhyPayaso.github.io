/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (61.16%)
 * Likes:    385
 * Dislikes: 0
 * Total Accepted:    103.3K
 * Total Submissions: 168.8K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>

using namespace std;
class Solution
{
public:
    vector<vector<int>> res;

    void helper(TreeNode *node, int sum, vector<int> path)
    {

        if (node == nullptr)
            return;

        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr)
        {
            if (sum == node->val)
            {
                res.push_back(path);
            }
        }

        helper(node->left, sum - node->val, path);
        helper(node->right, sum - node->val, path);
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<int> path;
        helper(root, sum, path);
        return res;
    }
};
// @lc code=end
