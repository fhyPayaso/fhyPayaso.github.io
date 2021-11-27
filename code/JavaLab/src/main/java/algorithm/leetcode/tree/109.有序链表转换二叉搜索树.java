package algorithm.leetcode.tree;

import algorithm.config.ListNode;
import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
 * <p>
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 */
class LC109 {


    public TreeNode sortedListToBST(ListNode head) {

        if (head == null) {
            return null;
        }

        if (head.next == null) {
            return new TreeNode(head.val);
        }

        ListNode p1 = head;
        ListNode p2 = head;
        ListNode pre = null;
        // 先找到链表中点p1
        while (p2 != null && p2.next != null) {
            pre = p1;
            p1 = p1.next;
            p2 = p2.next.next;
        }

        // 将p1前后的链表分别断开
        ListNode midHead = p1.next;
        p1.next = null;
        pre.next = null;

        TreeNode node = new TreeNode(p1.val);
        node.left = sortedListToBST(head);
        node.right = sortedListToBST(midHead);
        return node;
    }

}