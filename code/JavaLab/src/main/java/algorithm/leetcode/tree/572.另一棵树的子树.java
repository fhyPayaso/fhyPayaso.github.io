package algorithm.leetcode.tree;


import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/subtree-of-another-tree/
 * <p>
 * 给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。
 */
class LC572 {

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {

        if (root == null && subRoot == null) {
            return true;
        }

        if (helper(root, subRoot)) {
            return true;
        }

        if (root != null) {
            return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
        }


        return false;
    }

    public boolean helper(TreeNode n1, TreeNode n2) {
        if (n1 == null && n2 == null) {
            return true;
        }

        if (n1 != null && n2 != null) {
            if (n1.val != n2.val) {
                return false;
            }
            return helper(n1.left, n2.left) && helper(n1.right, n2.right);
        }

        return false;
    }

}