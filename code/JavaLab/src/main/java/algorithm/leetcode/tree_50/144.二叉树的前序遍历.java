package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 * <p>
 * 二叉树先序遍历
 */
class LC144 {

    public List<Integer> mRes = new ArrayList<>();

    // 递归方法
    public List<Integer> preorderTraversal0(TreeNode root) {
        helper(root);
        return mRes;
    }

    public void helper(TreeNode root) {
        if (root == null) {
            return;
        }
        mRes.add(root.val);
        helper(root.left);
        helper(root.right);
    }

    /////////////////////////////////////////////

    // 非递归方法
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        while (!stack.empty()) {
            TreeNode node = stack.pop();
            if (node != null) {
                res.add(node.val); // 先序遍历 先访问根节点
                stack.push(node.right); // 右节点先入栈, 后访问
                stack.push(node.left); // 左节点后入栈, 先访问
            }
        }
        return res;
    }

}