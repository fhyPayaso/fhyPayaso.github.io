package algorithm.leetcode.tree;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/search-in-a-binary-search-tree/
 * <p>
 * 给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。
 */
class LC700 {

    // 递归方法
    public TreeNode searchBST(TreeNode root, int val) {
        if (root == null || root.val == val) {
            return root;
        }
        return root.val > val ? searchBST(root.left, val) : searchBST(root.right, val);
    }

    // 迭代方法
    public TreeNode searchBST1(TreeNode root, int val) {
        TreeNode curNode = root;
        while (curNode != null) {
            if (curNode.val == val) {
                return curNode;
            }
            curNode = curNode.val > val ? curNode.left : curNode.right;
        }
        return curNode;
    }
}