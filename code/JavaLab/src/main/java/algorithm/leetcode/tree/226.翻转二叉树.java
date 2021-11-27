package algorithm.leetcode.tree;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/invert-binary-tree/
 * <p>
 * 二叉树翻转
 */
class LC226 {

    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        invertTree(root.left);
        invertTree(root.right);
        return root;
    }
}