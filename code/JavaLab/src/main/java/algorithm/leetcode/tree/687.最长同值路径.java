package algorithm.leetcode.tree;


import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/longest-univalue-path/
 * <p>
 * 给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。
 * <p>
 * 注意：两个节点之间的路径长度由它们之间的边数表示。
 */
class LC687 {


    public int res = 0;

    public int longestUnivaluePath(TreeNode root) {
        helper(root);
        return res;
    }

    public int helper(TreeNode root) {

        if (root == null) {
            return 0;
        }

        // 左孩子为值的最大路径长度
        int leftRes = helper(root.left);

        // 右孩子为值的最大路径长度
        int rightRes = helper(root.right);


        // 根节点和左孩子相同
        int leftCur = 0;
        if (root.left != null && root.left.val == root.val) {
            leftCur = leftRes + 1;
        }

        // 根节点和右孩子相同
        int rightCur = 0;
        if (root.right != null && root.right.val == root.val) {
            rightCur = rightRes + 1;
        }

        res = Math.max(res, leftCur + rightCur);
        return Math.max(leftCur, rightCur);

    }

}