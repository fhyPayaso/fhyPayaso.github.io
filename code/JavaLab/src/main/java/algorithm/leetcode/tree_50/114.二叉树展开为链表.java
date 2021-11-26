package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;


/**
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
 * <p>
 * 给你二叉树的根结点 root ，请你将它展开为一个单链表：
 * <p>
 * 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
 * 展开后的单链表应该与二叉树 先序遍历 顺序相同。
 */
class LC114 {

    // last永远是已经展开链表的头结点
    TreeNode last = null;

    public void flatten(TreeNode root) {
        if (root == null) {
            return;
        }

        // 展开顺序 根节点-> 左子树链表 -> 右子树链表

        // 先将右子树展开
        flatten(root.right);

        // 再将左子树展开, 此时左子树链表 -> 右子树链表已经连接
        flatten(root.left);

        // last为左子树的第一个值
        root.right = last;
        root.left = null; // 左子树置空

        last = root; //
    }
}