package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/house-robber-iii/
 * <p>
 * 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。
 * 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
 * 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
 * <p>
 * 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
 */
class LC337 {

    public int rob(TreeNode root) {
        int[] val = new int[2];
        helper(root, val);
        return Math.max(val[0], val[1]);
    }

    // 递归遍历时记录两个值，分别为带有根节点的最大值，和不带根节点的最大值
    public void helper(TreeNode root, int[] val) {

        if (root == null) {
            val[0] = 0;
            val[1] = 0;
            return;
        }

        int[] leftVal = new int[2];
        helper(root.left, leftVal);

        int[] rightVal = new int[2];
        helper(root.right, rightVal);

        // 两种情况

        // 带根节点, 不带两个子节点
        val[0] = root.val + leftVal[1] + rightVal[1];
        // 不带根节点, 左右子树分别取最大即可
        val[1] = Math.max(leftVal[0], leftVal[1]) + Math.max(rightVal[0], rightVal[1]);
    }

}