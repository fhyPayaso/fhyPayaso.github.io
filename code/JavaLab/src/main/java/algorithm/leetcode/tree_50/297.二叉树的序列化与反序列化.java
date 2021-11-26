package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;

import java.util.LinkedList;

/**
 * https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/
 */
class Codec {


    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {

        // 层序遍历序列化
        StringBuilder strBuilder = new StringBuilder();
        strBuilder.append('[');
        if (root != null) {
            LinkedList<TreeNode> queue = new LinkedList<>();
            queue.add(root);
            while (!queue.isEmpty()) {
                TreeNode node = queue.removeFirst();
                if (node != null) {
                    strBuilder.append(node.val);
                    queue.add(node.left);
                    queue.add(node.right);
                } else {
                    strBuilder.append("null");
                }

                if (!queue.isEmpty()) {
                    strBuilder.append(',');
                }
            }
        }
        strBuilder.append(']');
        return strBuilder.toString();
    }

    public TreeNode str2Node(String str) {
        if ("null".equals(str)) {
            return null;
        }
        return new TreeNode(Integer.parseInt(str));
    }


    public TreeNode deserialize(String data) {

        if ("".equals(data) || "[]".equals(data)) {
            return null;
        }

        data = data.substring(1, data.length() - 1);
        String[] list = data.split(",");
        int index = 0;
        TreeNode root = str2Node(list[index++]);

        // 反序列化同样用层序遍历
        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {

            TreeNode node = queue.removeFirst();
            node.left = str2Node(list[index++]);
            node.right = str2Node(list[index++]);

            if (node.left != null) {
                queue.add(node.left);
            }

            if (node.right != null) {
                queue.add(node.right);
            }
        }
        return root;
    }
}