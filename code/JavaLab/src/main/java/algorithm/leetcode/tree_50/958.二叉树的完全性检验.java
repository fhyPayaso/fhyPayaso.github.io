package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;

import java.util.LinkedList;

/**
 * https://leetcode-cn.com/problems/check-completeness-of-a-binary-tree/
 * <p>
 * <p>
 * 给定一个二叉树，确定它是否是一个完全二叉树。(仅右下方可以缺失节点)
 */
class LC958 {


    public boolean isCompleteTree(TreeNode root) {

        LinkedList<TreeNode> queue = new LinkedList();
        queue.add(root);
        // 完全二叉树的层序遍历, 必然是连续的非空节点
        while (!queue.isEmpty()) {

            TreeNode cur = queue.removeFirst();
            if (cur == null) {
                // 只要出现一个空节点, 则剩余的同层节点必须全为空
                while (!queue.isEmpty()) {
                    TreeNode c = queue.removeFirst();
                    if (c != null) {
                        return false;
                    }
                }
                return true;
            }
            queue.add(cur.left);
            queue.add(cur.right);
        }
        return true;
    }
}