package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 * <p>
 * 中序遍历二叉树，递归和非递归两种方法
 */
class LC94 {


    // 递归遍历
    public List<Integer> res = new ArrayList<>();

    public List<Integer> inorderTraversal1(TreeNode root) {
        helper(root);
        return res;
    }

    public void helper(TreeNode root) {
        if (root == null) {
            return;
        }
        helper(root.left);
        res.add(root.val);
        helper(root.right);
    }


    /**
     * 非递归遍历
     */
    public List<Integer> inorderTraversal2(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;
        // 如果回到根节点，栈一定是空的，但右子树还没有遍历，所以需要特判
        while (!stack.empty() || cur != null) {
            // 不断把左侧节点压入栈
            while (cur != null) {
                stack.push(cur);
                cur = cur.left;
            }
            // 此时为中间节点
            TreeNode node = stack.pop();
            list.add(node.val);
            // 中间节点此后就没用了，再将右子树进行中序遍历
            cur = node.right;
        }
        return list;
    }

}