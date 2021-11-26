package algorithm.leetcode.tree_50;


import java.util.List;

/**
 * https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/
 * <p>
 * 给定一个 N 叉树，找到其最大深度。
 * <p>
 * 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
 */
class LC559 {

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

    public int maxDepth(Node root) {

        if (root == null) {
            return 0;
        }

        if (root.children == null || root.children.size() == 0) {
            return 1;
        }

        int maxVal = Integer.MIN_VALUE;
        for (int i = 0; i < root.children.size(); i++) {
            Node p = root.children.get(i);
            int curVal = maxDepth(p);
            if (curVal > maxVal) {
                maxVal = curVal;
            }
        }
        return maxVal + 1;
    }

}