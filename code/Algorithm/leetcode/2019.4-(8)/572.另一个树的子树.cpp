/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
 *
 * https://leetcode-cn.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (39.93%)
 * Total Accepted:    3.7K
 * Total Submissions: 9.3K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s
 * 也可以看做它自身的一棵子树。
 * 
 * 示例 1:
 * 给定的树 s:
 * 
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * 
 * 
 * 给定的树 t：
 * 
 * 
 * ⁠  4 
 * ⁠ / \
 * ⁠1   2
 * 
 * 
 * 返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。
 * 
 * 示例 2:
 * 给定的树 s：
 * 
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * ⁠   /
 * ⁠  0
 * 
 * 
 * 给定的树 t：
 * 
 * 
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 * 
 * 
 * 返回 false。
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
    bool isSubtreeWithRoot(TreeNode *s, TreeNode *t)
    {
        if (s == NULL && t == NULL)
            return true;
        if (s == NULL || t == NULL)
            return false;
        if (s->val != t->val)
            return false;
        return isSubtreeWithRoot(s->right, t->right) && isSubtreeWithRoot(s->left, t->left);
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (s == NULL)
            return false;
        return isSubtreeWithRoot(s, t)  // 以当前节点为根节点判断是否包含子树
               || isSubtree(s->left, t) // 若当前节点不包含则分别从左右子节点中寻找
               || isSubtree(s->right, t);
    }
};
    