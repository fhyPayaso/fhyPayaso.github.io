package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 */
class LC235 {

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return null;
        }

        if (root.val > p.val && root.val > q.val) {
            // 两个都比根节点小, 说明在左子树
            return lowestCommonAncestor(root.left, p, q);
        } else if (root.val < p.val && root.val < q.val) {
            // 两个都比根节点大, 说明在右子树
            return lowestCommonAncestor(root.right, p, q);
        }
        // 一大一小则结果为当前节点
        return root;
    }
}