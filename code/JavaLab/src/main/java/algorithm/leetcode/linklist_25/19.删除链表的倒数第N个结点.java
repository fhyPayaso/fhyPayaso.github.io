package algorithm.leetcode.linklist_25;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * <p>
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 */
class LC19 {

    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null || head.next == null) {
            return null;
        }

        int nn = n;
        // 先将指针1移动n步
        ListNode p1 = head;
        while (nn > 0) {
            p1 = p1.next;
            nn--;
        }

        // 将指针1 2同时移动, 1到末尾 则2正好到倒数第n个节点
        ListNode dump = new ListNode(0);
        dump.next = head;
        ListNode pre = dump;
        ListNode p2 = head;
        while (p1 != null) {
            p1 = p1.next;
            pre = pre.next;
            p2 = p2.next;
        }

        if (p2 != null) {
            pre.next = p2.next;
        } else {
            pre.next = null;
        }
        return dump.next;
    }
}