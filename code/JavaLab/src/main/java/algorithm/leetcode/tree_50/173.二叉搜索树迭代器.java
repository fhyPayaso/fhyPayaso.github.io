package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;

import java.util.Stack;


/**
 * https://leetcode-cn.com/problems/binary-search-tree-iterator/
 * <p>
 * 思路和非递归中序遍历二叉树相同, 注意题干要求空间复杂度为O(h), h为二叉树的高度
 */
class BSTIterator {


    private Stack<TreeNode> stack = new Stack<>();

    private TreeNode curNode;


    public BSTIterator(TreeNode root) {

        curNode = root;
        // 左孩子全部入栈
        while (curNode != null) {
            stack.push(curNode);
            curNode = curNode.left;
        }
    }

    public int next() {

        // 栈顶元素永远是需要访问的

        TreeNode node = stack.pop();
        curNode = node.right;
        while (curNode != null) {
            stack.push(curNode);
            curNode = curNode.left;
        }

        return node.val;
    }

    public boolean hasNext() {
        return !stack.empty();
    }
}