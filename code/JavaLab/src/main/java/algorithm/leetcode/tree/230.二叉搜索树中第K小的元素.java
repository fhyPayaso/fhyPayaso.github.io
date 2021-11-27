package algorithm.leetcode.tree;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
 * <p>
 * 二叉搜索树中序遍历为递增
 */
class LC230 {

    public int res;
    public int K;

    public int kthSmallest(TreeNode root, int k) {
        K = k;
        helper(root);
        return res;
    }

    public void helper(TreeNode root) {
        if (root == null || K <= 0) {
            return;
        }

        helper(root.left);
        if (--K == 0) {
            res = root.val;
            return;
        }

        helper(root.right);
    }


}