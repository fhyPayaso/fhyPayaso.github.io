/*
 * @lc app=leetcode.cn id=94 lang=java
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (64.08%)
 * Total Accepted:    20.5K
 * Total Submissions: 32K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
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
