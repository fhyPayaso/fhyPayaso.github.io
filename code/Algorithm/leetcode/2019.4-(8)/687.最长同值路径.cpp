/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
 *
 * https://leetcode-cn.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (32.95%)
 * Total Accepted:    2.9K
 * Total Submissions: 8.6K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * 给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。
 * 
 * 注意：两个节点之间的路径长度由它们之间的边数表示。
 * 
 * 示例 1:
 * 
 * 输入:
 * 
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 * 
 * 
 * 输出:
 * 
 * 
 * 2
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 
 * 
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 * 
 * 
 * 输出:
 * 
 * 
 * 2
 * 
 * 
 * 注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。
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

    int dfs(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        // 以左孩子值为基准值搜索，获得左子树最大路径
        int left = dfs(root->left);
        // 以右孩子值为基准值搜索，获得右子树最大路径
        int right = dfs(root->right);

        // 若根节点与左孩子值相同，记录以根节点值为基准值的最大路径
        int leftRoot = 0;
        if (root->left != nullptr && root->left->val == root->val)
            leftRoot = left + 1;

        // 若根节点与右孩子值相同，记录以根节点值为基准值的最大路径
        int rightRoot = 0;
        if (root->right != nullptr && root->right->val == root->val)
            rightRoot = right + 1;

        // 若左右子树值不同，必有一个值为0，所以结果就是当前树的最大值
        int curRes = leftRoot + rightRoot;
        // 维护最大值
        if (curRes > res)
            res = curRes;
        // 返回值意义: 以根节点值为基准值的最大路径
        return leftRoot > rightRoot ? leftRoot : rightRoot;
    }

    int longestUnivaluePath(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        dfs(root);
        return res;
    }
};
