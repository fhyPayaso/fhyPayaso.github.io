package algorithm.leetcode.tree;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/balanced-binary-tree/
 * <p>
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 */
class LC110 {

    public boolean res = true;

    public boolean isBalanced(TreeNode root) {
        helper(root);
        return res;
    }

    public int helper(TreeNode root) {

        if (root == null) {
            return 0;
        }

        int leftDeep = helper(root.left);
        int rightDeep = helper(root.right);
        if (Math.abs(leftDeep - rightDeep) > 1) {
            res = false;
        }
        return Math.max(leftDeep, rightDeep) + 1;
    }

}