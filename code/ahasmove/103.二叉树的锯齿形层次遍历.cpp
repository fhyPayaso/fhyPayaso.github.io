/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (54.82%)
 * Likes:    260
 * Dislikes: 0
 * Total Accepted:    69.1K
 * Total Submissions: 125.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层次遍历如下：
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode *> Q;
        Q.push(root);
        bool isLeftToRight = false;
        while (!Q.empty())
        {
            isLeftToRight = !isLeftToRight;

            vector<int> curVec;
            vector<int> temp;
            // 获取当前层节点数量
            int size = Q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *cur = Q.front();
                Q.pop();
                if (isLeftToRight)
                    curVec.push_back(cur->val);
                else
                    temp.push_back(cur->val);

                if (cur->left)
                    Q.push(cur->left);
                if (cur->right)
                    Q.push(cur->right);
            }
            if (!isLeftToRight)
            {
                for (int i = size - 1; i >= 0; i--)
                {
                    curVec.push_back(temp[i]);
                }
            }

            res.push_back(curVec);
        }
        return res;
    }
};
// @lc code=end
