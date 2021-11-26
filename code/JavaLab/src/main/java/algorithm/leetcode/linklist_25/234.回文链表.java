package algorithm.leetcode.linklist_25;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/palindrome-linked-list/
 * <p>
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 */
class LC234 {


    public boolean isPalindrome(ListNode head) {

        // 特判一下
        if (head == null || head.next == null) {
            return true;
        }
        if (head.next.next == null) {
            return head.val == head.next.val;
        }


        // 快慢指针找到中点p1
        ListNode p1 = head, p2 = head;
        ListNode pre = p1;
        while (p2 != null && p2.next != null) {
            pre = p1;
            p1 = p1.next;
            p2 = p2.next.next;
        }
        // 从中间断开链表
        pre.next = null;
        // 翻转链表
        ListNode head2 = reverse(p1);

        while (head != null && head2 != null) {
            if (head.val != head2.val) {
                return false;
            }
            head = head.next;
            head2 = head2.next;
        }
        return true;
    }

    public ListNode reverse(ListNode head) {

        if (head == null || head.next == null) {
            return null;
        }

        ListNode pre = null;
        ListNode p = head;
        while (p != null) {
            ListNode next = p.next;
            p.next = pre;
            pre = p;
            p = next;
        }
        return pre;
    }
}