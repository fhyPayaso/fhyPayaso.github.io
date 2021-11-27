package algorithm.leetcode.tree;

import java.util.LinkedList;

/**
 * https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
 * <p>
 * 满二叉树,每一层横向连接
 */
class LC116 {

    public Node connect(Node root) {

        return helper1(root);
    }

    // 方法1:层序遍历
    public Node helper1(Node root) {

        if (root == null) {
            return null;
        }

        LinkedList<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {

            int size = queue.size();
            Node pre = null;
            while (size > 0) {

                Node node = queue.removeFirst();

                if (pre != null) {
                    pre.next = node;
                }
                pre = node;

                if (node.left != null)
                    queue.add(node.left);
                if (node.right != null)
                    queue.add(node.right);
                size--;
            }
        }
        return root;
    }

    /////////////////////////////////////////

    // 方法2 递归, 常数空间复杂度
    public Node helper2(Node root) {

        if (root == null || root.left == null || root.right == null) {
            return root;
        }

        // 先把左子树和右子树相连
        root.left.next = root.right;

        // 如果当前层还有下一个节点, 将当前右孩子和下一个节点左孩子相连
        if (root.next != null) {
            root.right.next = root.next.left;
        }

        helper2(root.left);
        helper2(root.right);

        return root;
    }


}