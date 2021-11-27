package algorithm.leetcode.tree;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/recover-binary-search-tree/
 * <p>
 * 给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。
 */
class LC99 {

    // 需要被交换的两个节点
    public TreeNode n1 = null, n2 = null;
    // 当前节点的上一个节点
    public TreeNode pre = null;

    public void recoverTree(TreeNode root) {
        // 中序遍历二叉搜索树应该为升序
        helper(root);
        int temp = n1.val;
        n1.val = n2.val;
        n2.val = temp;
    }

    public void helper(TreeNode root) {

        if (root == null) {
            return;
        }

        helper(root.left);

        // 第一次: pre节点 大于 当前节点 说明pre节点需要交换
        // 第二次: pre节点 大于 当前节点 说明当前节点需要交换
        if (pre != null && pre.val > root.val) {
            if (n1 == null) {
                n1 = pre;
            }
            // 有可能两个交换的节点正好挨着
            n2 = root;
        }
        pre = root;
        helper(root.right);
    }
}