package algorithm.leetcode.tree;

import algorithm.config.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/symmetric-tree/
 * <p>
 * 判断二叉树是否对称
 */
class LC101 {

    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
//        return check(root.left, root.right);
        return check2(root);
    }

    // 递归方法
    public boolean check(TreeNode n1, TreeNode n2) {

        if (n1 == null && n2 == null) {
            return true;
        }

        if (n1 == null || n2 == null) {
            return false;
        }

        if (n1.val != n2.val) {
            return false;
        }
        return check(n1.right, n2.left) && check(n1.left, n2.right);
    }


    // 非递归方法, bfs判断每一行是否对称
    public boolean check2(TreeNode root) {

        LinkedList<TreeNode> queue = new LinkedList<>();

        queue.add(root);

        while (!queue.isEmpty()) {

            int size = queue.size();
            // 二叉树对称不可能是单数
            if (size > 1 && size % 2 == 1) {
                return false;
            }

            List<TreeNode> list = new ArrayList<>();
            while (size > 0) {
                TreeNode node = queue.removeFirst();
                if (node != null) {
                    queue.add(node.left);
                    queue.add(node.right);
                }
                list.add(node);
                size--;
            }

            if (list.size() == 1) {
                continue;
            }

            for (int i = 0; i < list.size() / 2; i++) {

                TreeNode n1 = list.get(i);
                TreeNode n2 = list.get(list.size() - i - 1);

                if (n1 == null && n2 == null) {
                    continue;
                }

                if (n1 != null && n2 != null && n1.val == n2.val) {
                    continue;
                }
                return false;
            }
        }

        return true;
    }

}