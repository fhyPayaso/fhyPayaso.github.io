/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (70.78%)
 * Likes:    405
 * Dislikes: 0
 * Total Accepted:    77.6K
 * Total Submissions: 109.7K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

#include <vector>

using namespace std;

class Solution
{
public:
    TreeNode *div(vector<int> &inorder, int l1, int r1, vector<int> &postorder, int l2, int r2)
    {
        if(r2 < l2)
            return nullptr;

        int midVal = postorder[r2];
        int mid = l1;
        while (inorder[mid] != midVal)
            mid++;

        TreeNode *node = new TreeNode(midVal);

        node->left = div(inorder, l1, mid - 1, postorder, l2, l2 + mid - l1 - 1);
        node->right = div(inorder, mid + 1, r1, postorder, l2 + mid - l1, r2-1);

        return node;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        
        return div(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
// @lc code=end
