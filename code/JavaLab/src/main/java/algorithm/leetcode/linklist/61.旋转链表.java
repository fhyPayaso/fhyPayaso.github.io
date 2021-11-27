package algorithm.leetcode.linklist;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/rotate-list/
 *
 * 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
 */
class LC61 {
    public ListNode rotateRight(ListNode head, int k) {

        if(head == null) {
            return null;
        }

        // 记录长度
        int len = 0;
        ListNode p = head;
        while(p != null) {
            p = p.next;
            len++;
        }
        k %= len;

        if(k == 0 || len == 1) {
            return head;
        }
        k = len - k;

        // 从中间找到要断开的节点
        p = head;
        ListNode pre = null;
        while(k > 0) {
            if(k == 1) {
                pre = p;
            }
            k--;
            p = p.next;
        }

        // 断开节点连接到开头
        while(p.next != null) {
            p = p.next;
        }
        p.next = head;

        ListNode res = pre.next;
        pre.next = null;
        return res;
    }
}
