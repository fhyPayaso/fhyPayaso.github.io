package algorithm.leetcode.tree;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * <p>
 * 给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。
 */
class LC105 {

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return helper(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }


    /**
     * @param preorder 前序遍历顺序
     * @param l1       当前子树前序遍历起点
     * @param r1       当前子树前序遍历终点
     * @param inorder  中序遍历顺序
     * @param l2       当前子树中序遍历起点
     * @param r2       当前子树中序遍历终点
     * @return
     */
    public TreeNode helper(int[] preorder, int l1, int r1, int[] inorder, int l2, int r2) {
        if (l1 > r1) {
            return null;
        }

        // 当前子树跟节点(先序遍历首个节点)
        int rootVal = preorder[l1];
        TreeNode root = new TreeNode(rootVal);
        // 从中序遍历中找到根节点
        int index = l2;
        while (inorder[index] != rootVal)
            index++;
        int diff = index - l2;

        // 根节点左侧为左子树序列，右侧为右子树序列
        root.left = helper(preorder, l1 + 1, l1 + diff, inorder, l2, index - 1);
        root.right = helper(preorder, l1 + diff + 1, r1, inorder, index + 1, r2);
        return root;
    }
}