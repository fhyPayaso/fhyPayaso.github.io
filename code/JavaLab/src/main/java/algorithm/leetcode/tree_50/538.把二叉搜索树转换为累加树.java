package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
 * <p>
 * 把二叉搜索树从后向前进行累加
 */
class LC538 {

    public int sum = 0;

    public TreeNode convertBST(TreeNode root) {
        // 遍历顺序, 右—>中>左, 从后向前进行累加
        helper(root);
        return root;
    }

    public void helper(TreeNode node) {
        if (node == null) {
            return;
        }
        helper(node.right);
        node.val += sum;
        sum = node.val;
        helper(node.left);
    }

}