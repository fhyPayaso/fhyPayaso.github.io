package algorithm.leetcode.tree;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
 * <p>
 * 给定一个二叉树，找出其最小深度。
 * <p>
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 */
class LC111 {

    public int minDepth(TreeNode root) {

        if (root == null) {
            return 0;
        }

        int minLeft = minDepth(root.left);
        int minRight = minDepth(root.right);
        // 高度至少为1的节点才是有效节点
        if (minLeft == 0 || minRight == 0) {
            return minLeft + minRight + 1;
        }
        return Math.min(minLeft, minRight) + 1;
    }

}