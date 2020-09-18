/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (70.91%)
 * Likes:    551
 * Dislikes: 0
 * Total Accepted:    82.1K
 * Total Submissions: 115.5K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为一个单链表。
 * 
 * 
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
 * 
 */

// @lc code=start
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

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
//                                                                                *
// };

// 方法1: 先序遍历将节点放入vector, 重新构建树, 但不满足原地展开

// 方法2:

class Solution
{

    void preorder(TreeNode *node, TreeNode *&last)
    {
        if (node == nullptr)
            return;

        if (node->left == nullptr && node->right == nullptr)
        {
            last = node;
            return;
        }

        TreeNode *left = node->left;
        TreeNode *right = node->right;

        TreeNode *left_last = nullptr;
        TreeNode *right_last = nullptr;

        if (left != nullptr)
        {
            // 左子树不为空, 则先将左子树展开为链表
            preorder(left, left_last);
            // 将左链表放到右子树
            node->left = nullptr;
            node->right = left;
            last = left_last;
        }
        if (right != nullptr)
        {
            preorder(right, right_last);
            if (left_last != nullptr)
                left_last->right = right;
            last = right_last;
        }
    }

public:
    void flatten(TreeNode *root)
    {
        TreeNode *last = nullptr;
        preorder(root, last);
    }
};
// @lc code=end
