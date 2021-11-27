package algorithm.leetcode.linklist;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 *
 * k是一个正整数，它的值小于或等于链表的长度。
 *
 * 如果节点总数不是k的整数倍，那么请将最后剩余的节点保持原有顺序。
 *
 * 进阶：
 *
 * 你可以设计一个只使用常数额外空间的算法来解决此问题吗？
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 *
 */
class LC25 {

    // 分组翻转链表
    public ListNode reverseKGroup(ListNode head, int k) {

        // 先求链表长度
        int len = 0;
        ListNode p = head;
        while (p != null) {
            p = p.next;
            len++;
        }

        ListNode f = new ListNode(0);
        f.next = head;

        ListNode pre = f;
        ListNode cur = head;
        ListNode next;


        // 处理K组
        for (int i = 0; i < len / k; i++) {
            // 每次将下一个节点移动到当前组的最前面
            for (int j = 0; j < k - 1; j++) {
                next = cur.next;
                cur.next = next.next;
                next.next = pre.next;
                pre.next = next;
            }
            pre = cur;
            cur = cur.next;
        }
        return f.next;
    }
}