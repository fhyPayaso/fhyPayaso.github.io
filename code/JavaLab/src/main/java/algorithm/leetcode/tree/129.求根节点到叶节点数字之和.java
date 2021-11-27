package algorithm.leetcode.tree;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
 * <p>
 * 给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
 * 每条从根节点到叶节点的路径都代表一个数字：
 * <p>
 * 例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
 * 计算从根节点到叶节点生成的 所有数字之和 。
 * <p>
 * 叶节点 是指没有子节点的节点。
 */
class LC129 {

    public int res = 0;

    public int sumNumbers(TreeNode root) {

        if (root == null) {
            return 0;
        }
        helper(root, 0);
        return res;
    }

    public void helper(TreeNode root, int curNum) {

        if (root == null) {
            return;
        }

        int n = curNum * 10 + root.val;
        if (root.left == null && root.right == null) {
            res += n;
            return;
        }
        helper(root.left, n);
        helper(root.right, n);

    }
}