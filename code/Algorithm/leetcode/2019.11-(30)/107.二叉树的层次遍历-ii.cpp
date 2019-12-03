/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (62.98%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    31.7K
 * Total Submissions: 50.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
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
#include <queue>
using namespace std;
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        

        if (root == nullptr)
            return res;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            // 保证每次循环队列中都是同一层的节点即可
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                level.push_back(cur->val);

                if (cur->left != nullptr)
                    q.push(cur->left);
                if (cur->right != nullptr)
                    q.push(cur->right);
            }
            res.push_back(level);
        }
        
        vector<vector<int>> res1;
        while (!res.empty())
        {
            vector<int> t = res.back();
            if (!t.empty())
                res1.push_back(t);
            res.pop_back();
        }
        return res1;
    }
};
// @lc code=end
