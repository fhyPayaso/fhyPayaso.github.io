package algorithm.leetcode.linklist;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/
 * <p>
 * 给你单链表的头指针 head 和两个整数left 和 right ，其中left <= right 。
 * 请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 */
class LC92 {
    public ListNode reverseBetween(ListNode head, int left, int right) {

        if (left == right) {
            return head;
        }

        int pos = 0;

        ListNode h = new ListNode(0);
        h.next = head;
        ListNode p = head;
        ListNode mid = h, midNext; // 从mid之后开始反转
        ListNode curNext;
        ListNode firstMidNext = null;


        while (p != null) {
            pos++;

            if (pos < left) {
                mid = p; // 记录反转前的最后一个节点
                p = p.next;
            } else if (pos == left) {
                firstMidNext = p; // 记录反转范围的第一个节点
                p = p.next;
            } else if (pos <= right) {

                // 头插法不断插到反转前的最后一个节点后面
                curNext = p.next;
                midNext = mid.next;
                mid.next = p;
                p.next = midNext;
                p = curNext;

                if (pos == right) {
                    // 此时反转的第一个节点已经变成最后一个节点, 与后面不需要反转的节点连接即可
                    firstMidNext.next = p;
                }
            } else {
                p = p.next;
            }

        }
        return h.next;
    }
}