package algorithm.leetcode.tree_50;


import algorithm.config.TreeNode;

import java.util.LinkedList;

/**
 * https://leetcode-cn.com/problems/maximum-width-of-binary-tree/
 * <p>
 * 给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。
 * <p>
 * 每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。
 */
class LC662 {

    public int widthOfBinaryTree(TreeNode root) {


        // 层序遍历+ 树状数组的思路

        LinkedList<TreeNode> queue = new LinkedList<>();
        LinkedList<Integer> posList = new LinkedList<>();
        queue.add(root);
        posList.add(1);

        int maxVal = 1;

        while (!queue.isEmpty()) {

            int size = queue.size();
            while (size > 0) {
                TreeNode node = queue.removeFirst();
                int index = posList.removeFirst();

                if (node.left != null) {
                    // 左孩子坐标为当前坐标的2倍
                    queue.add(node.left);
                    posList.add(index * 2);
                }

                if (node.right != null) {
                    // 右孩子坐标为当前坐标的2倍+1
                    queue.add(node.right);
                    posList.add(index * 2 + 1);
                }

                size--;
            }

            if (!posList.isEmpty()) {
                int diff = posList.getLast() - posList.getFirst() + 1;
                maxVal = Math.max(maxVal, diff);
            }
        }


        return maxVal;
    }

}