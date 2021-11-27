package algorithm.leetcode.tree;

import algorithm.config.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
 * <p>
 * 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）
 */
class LC103 {

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {


        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {
            return null;
        }

        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        boolean r2l = true;


        while (!queue.isEmpty()) {

            LinkedList<Integer> row = new LinkedList<>();

            int size = queue.size();

            for (int i = 0; i < size; i++) {
                TreeNode cur = queue.removeFirst();
                if (r2l) {
                    row.add(cur.val);
                } else {
                    row.addFirst(cur.val);
                }

                if (cur.left != null) {
                    queue.add(cur.left);
                }

                if (cur.right != null) {
                    queue.add(cur.right);
                }
            }

            res.add(row);
            r2l = !r2l;
        }
        return res;
    }

}