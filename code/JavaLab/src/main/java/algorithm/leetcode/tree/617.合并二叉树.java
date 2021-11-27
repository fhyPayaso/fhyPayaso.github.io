package algorithm.leetcode.tree;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/merge-two-binary-trees/
 * <p>
 * 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
 * <p>
 * 你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为NULL 的节点将直接作为新二叉树的节点
 */
class LC617 {


    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {

        // 有一个为空, 直接将另一个当结果
        if (root1 == null) {
            return root2;
        }

        if (root2 == null) {
            return root1;
        }

        // 合并当前层
        root1.val += root2.val;

        // 如果root2的左或右孩子不为空, 则root1也必须保证不为空
        if (root1.left == null && root2.left != null) {
            root1.left = new TreeNode(0);
        }

        if (root1.right == null && root2.right != null) {
            root1.right = new TreeNode(0);
        }

        mergeTrees(root1.left, root2.left);
        mergeTrees(root1.right, root2.right);

        return root1;
    }

}