package algorithm.leetcode.tree;

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {
    }

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

/**
 * https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/
 * <p>
 * 方法1和116一样层序遍历, 空间复杂度On
 */
class LC117 {


    // 递归方法
    public Node connect(Node root) {

        if (root == null) {
            return root;
        }

        // 左右均不为空, 直接左连右
        if (root.left != null && root.right != null) {
            root.left.next = root.right;
        }


        if (root.left != null && root.right == null) {
            // 左不为空右为空, 向右侧找到第一个可以连接的对象
            root.left.next = getNext(root.next);
        }

        if (root.right != null) {
            // 只要右不为空, 则连接右侧找
            root.right.next = getNext(root.next);
        }

        // 本题的关键，先递归右子树, 这样能保证getNext能一直向右找到尽头
        connect(root.right);
        connect(root.left);

        return root;
    }

    // 给定第i层的节点, 找到第一个不为空的i+1层节点
    public Node getNext(Node node) {
        if (node == null) {
            return null;
        }
        if (node.left != null) {
            return node.left;
        }

        if (node.right != null) {
            return node.right;
        }

        if (node.next != null) {
            return getNext(node.next);
        }
        return null;
    }

}