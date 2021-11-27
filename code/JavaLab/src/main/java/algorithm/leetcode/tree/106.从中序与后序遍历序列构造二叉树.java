package algorithm.leetcode.tree;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * <p>
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 */
class LC106 {

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return helper(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);
    }

    public TreeNode helper(int[] inorder, int l1, int r1, int[] postorder, int l2, int r2) {

        if (l1 > r1) {
            return null;
        }

        // 找到根节点的值
        int rootVal = postorder[r2];
        TreeNode root = new TreeNode(rootVal);

        // 从中序遍历中找到根节点下标
        int index = l1;
        while (inorder[index] != rootVal)
            index++;
        int diff = index - l1;

        root.left = helper(inorder, l1, index - 1, postorder, l2, l2 + diff - 1);
        root.right = helper(inorder, index + 1, r1, postorder, l2 + diff, r2 - 1);
        return root;
    }

}