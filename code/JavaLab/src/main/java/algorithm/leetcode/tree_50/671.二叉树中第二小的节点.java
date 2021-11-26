package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/
 * <p>
 * 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为2或0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。
 */
class LC671 {

    // 卡边界值。。。
    public long minVal1 = Long.MAX_VALUE;
    public long minVal2 = Long.MAX_VALUE;

    public int findSecondMinimumValue(TreeNode root) {
        if (root == null) {
            return (int) minVal2;
        }

        // 出现比最小值还小的值, 两个都更新
        if (root.val < minVal1) {
            // 第一次不更新次小值
            if (minVal1 != Integer.MAX_VALUE) {
                minVal2 = minVal1;
            }
            minVal1 = root.val;
        }

        // 如果当前值在最小值和次小值之间，只更新次小值
        if (root.val > minVal1 && root.val < minVal2) {
            minVal2 = root.val;
        }

        findSecondMinimumValue(root.left);
        findSecondMinimumValue(root.right);

        return minVal2 == Long.MAX_VALUE ? -1 : (int) minVal2;
    }


}