/*
 * @lc app=leetcode.cn id=145 lang=java
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (63.50%)
 * Total Accepted:    10.7K
 * Total Submissions: 16.9K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
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
