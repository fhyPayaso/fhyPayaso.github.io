package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/path-sum-iii/
 * <p>
 * 给定一个二叉树的根节点 root，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
 * <p>
 * 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 */
class LC437 {

    public int res = 0;

    public int pathSum(TreeNode root, int targetSum) {

        if (root == null) {
            return 0;
        }

        // 检查经过当前根节点全部路径
        helper(root, targetSum);

        pathSum(root.left, targetSum);
        pathSum(root.right, targetSum);
        return res;
    }

    public void helper(TreeNode node, int curSum) {

        if (node == null) {
            return;
        }

        // 注意可能出现负值的情况, 所以满足之后不能return, 可能出现后续路径和为0的情况
        // 而且单独的一个节点也算一条路径
        if (node.val == curSum) {
            res++;
        }

        helper(node.left, curSum - node.val);
        helper(node.right, curSum - node.val);
    }

}