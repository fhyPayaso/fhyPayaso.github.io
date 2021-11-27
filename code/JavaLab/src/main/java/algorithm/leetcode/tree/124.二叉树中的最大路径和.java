package algorithm.leetcode.tree;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
 * <p>
 * 路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径至少包含一个 节点，且不一定经过根节点。
 * <p>
 * 路径和 是路径中各节点值的总和。
 * <p>
 * 给你一个二叉树的根节点 root ，返回其 最大路径和 。
 */
class LC124 {

    public int res = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        helper(root);
        return res;
    }

    public int helper(TreeNode root) {
        if (root == null) {
            return 0;
        }

        // 分别计算左右子树的最大路径(保证分别左右孩子节点)
        int left = Math.max(0, helper(root.left));
        int right = Math.max(0, helper(root.right));

        // 计算左子树+根节点+右子树的值, 维护一个最大值，即所有根节点都有可能被经过
        res = Math.max(res, left + right + root.val);

        // 这里返回的值的规则是: 必须经过根节点
        return root.val + Math.max(left, right);
    }

}