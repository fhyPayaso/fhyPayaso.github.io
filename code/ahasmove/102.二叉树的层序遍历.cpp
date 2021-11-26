/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (63.19%)
 * Likes:    624
 * Dislikes: 0
 * Total Accepted:    190.4K
 * Total Submissions: 300.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
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

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            vector<int> curVec;
            // 获取当前层节点数量
            int size = Q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *cur = Q.front();
                Q.pop();
                curVec.push_back(cur->val);
                if (cur->left)
                    Q.push(cur->left);
                if (cur->right)
                    Q.push(cur->right);
            }
            res.push_back(curVec);
        }
        return res;
    }
};
// @lc code=end
