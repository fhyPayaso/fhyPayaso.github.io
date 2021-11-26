package algorithm.leetcode.tree_50;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/
 */
class LC429 {

    class Node {
        public int val;
        public List<Node> children;

        public Node() {
        }

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, List<Node> _children) {
            val = _val;
            children = _children;
        }
    }


    public List<List<Integer>> levelOrder(Node root) {

        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {
            return res;
        }


        LinkedList<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {

            int size = queue.size();
            List<Integer> row = new ArrayList<>();

            for (int i = 0; i < size; i++) {
                Node node = queue.removeFirst();
                if (node != null) {
                    row.add(node.val);
                    queue.addAll(node.children);
                }
            }
            res.add(row);
        }
        return res;
    }
}