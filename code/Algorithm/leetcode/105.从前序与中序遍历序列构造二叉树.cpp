/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (68.54%)
 * Likes:    764
 * Dislikes: 0
 * Total Accepted:    129.9K
 * Total Submissions: 189.5K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode *divdeCounter(vector<int> &preorder, int l1, int r1, vector<int> &inorder, int l2, int r2)
    {

        if (r1 < l1)
            return nullptr;

        int midVal = preorder[l1];
        int mid = l2;
        while (midVal != inorder[mid])
            mid++;

        TreeNode *node = new TreeNode(midVal);

        node->left = divdeCounter(preorder, l1 + 1, l1 + mid - l2, inorder, l2, mid - 1);
        node->right = divdeCounter(preorder, l1 + mid - l2 + 1, r1, inorder, mid + 1, r2);
        // 1 3 5 6
        // 3 1 5 6
        return node;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return divdeCounter(preorder, 0, preorder.size() - 1,
                            inorder, 0, inorder.size() - 1);
    }
};
// @lc code=end
