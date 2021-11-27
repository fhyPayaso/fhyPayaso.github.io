package algorithm.leetcode.tree;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/validate-binary-search-tree/
 * <p>
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 * <p>
 * 有效 二叉搜索树定义如下：
 * <p>
 * 节点的左子树只包含 小于 当前节点的数。
 * 节点的右子树只包含 大于 当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 */
class LC98 {

    public boolean isValidBST(TreeNode root) {
//        return helper1(root, Long.MIN_VALUE, Long.MAX_VALUE);
        return helper2(root);
    }

    // 方法1 限制边界值
    public boolean helper1(TreeNode root, long minVal, long maxVal) {
        if (root == null) {
            return true;
        }
        if (root.val <= minVal || root.val >= maxVal) {
            return false;
        }
        return helper1(root.left, minVal, root.val) && helper1(root.right, root.val, maxVal);
    }


    public double pre = Integer.MIN_VALUE - 1.0;

    // 方法2 先序遍历保证升序
    public boolean helper2(TreeNode root) {
        if (root == null) {
            return true;
        }

        boolean l = helper2(root.left);
        if (root.val <= pre) {
            return false;
        }
        pre = root.val;

        boolean r = helper2(root.right);
        return l & r;
    }

}