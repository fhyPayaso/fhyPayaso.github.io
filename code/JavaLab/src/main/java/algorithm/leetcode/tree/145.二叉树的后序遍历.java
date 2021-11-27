package algorithm.leetcode.tree;

import algorithm.config.TreeNode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

class LC145 {

    public List<Integer> mRes = new ArrayList<>();

    // 递归方法
    public List<Integer> postorderTraversal0(TreeNode root) {
        helper(root);
        return mRes;
    }

    public void helper(TreeNode root) {
        if (root == null) {
            return;
        }
        helper(root.left);
        helper(root.right);
        mRes.add(root.val);
    }


    //////////////////////////////////////////

    // 非递归方法
    public List<Integer> postorderTraversal(TreeNode root) {

        List<Integer> list = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);

        while (!stack.empty()) {
            // 永远都把最上层节点的子树遍先历完
            TreeNode node = stack.pop();
            if (node == null) {
                continue;
            }
            list.add(node.val); // 先输出根节点
            stack.push(node.left); // 左孩子先入后遍历
            stack.push(node.right); // 右孩子后入先遍历
        }
        // 此时输出顺序变成了 中-右-左
        // 而后续遍历顺序为 左-右-中 所以把结果倒转即可
        Collections.reverse(list);
        return list;
    }

}