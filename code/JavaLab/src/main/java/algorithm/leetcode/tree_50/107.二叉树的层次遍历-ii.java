package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
 * <p>
 * 从下向上层序遍历, 用LinkedList头插法
 */
class LC107 {

    public List<List<Integer>> levelOrderBottom(TreeNode root) {

        LinkedList<List<Integer>> res = new LinkedList<>();

        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {

            int size = queue.size();
            List<Integer> row = new ArrayList<>();
            for (int i = 0; i < size; i++) {

                TreeNode node = queue.getFirst();
                queue.removeFirst();
                if (node != null) {
                    row.add(node.val);
                    queue.add(node.left);
                    queue.add(node.right);
                }
            }
            if (!row.isEmpty()) {
                res.addFirst(row);
            }

        }

        return res;
    }


}