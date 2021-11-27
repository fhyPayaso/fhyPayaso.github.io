package algorithm.leetcode.linklist;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/middle-of-the-linked-list/
 * <p>
 * 快慢指针找链表中间点
 */
class LC876 {
    public ListNode middleNode(ListNode head) {

        ListNode p1 = head;
        ListNode p2 = head;
        while (p2 != null && p2.next != null) {
            p1 = p1.next;
            p2 = p2.next.next;
        }
        return p1;
    }
}