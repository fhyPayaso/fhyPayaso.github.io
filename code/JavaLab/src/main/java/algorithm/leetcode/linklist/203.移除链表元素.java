package algorithm.leetcode.linklist;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/remove-linked-list-elements/
 * <p>
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 */
class LC203 {


    public ListNode removeElements(ListNode head, int val) {

        ListNode dump = new ListNode(0);
        dump.next = head;
        ListNode pre = dump;
        ListNode p = head;
        while (p != null) {
            if (p.val == val) {
                pre.next = p.next;
            } else {
                pre = p;
            }
            p = p.next;
        }
        return dump.next;
    }
}