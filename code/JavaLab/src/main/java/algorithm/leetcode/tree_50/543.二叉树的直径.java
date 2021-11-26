package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/diameter-of-binary-tree/
 * <p>
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
 * <p>
 * 和lc124 最大路径和类似
 */
class LC543 {

    public int res = 0;

    public int diameterOfBinaryTree(TreeNode root) {
        helper(root);
        return res;
    }

    public int helper(TreeNode node) {

        if (node == null) {
            return 0;
        }

        // 左右子树的结果一定是经过左右孩子节点的
        int left = helper(node.left);
        int right = helper(node.right);

        // 左右子树路径相连接, 维护最大值(每个跟节点都有被连通的机会, 但是连通之后只能用于维护最大值, 不能继续向上传递)
        res = Math.max(res, right + left);

        // 保证一定经过当前root节点
        return Math.max(right, left) + 1;
    }

}