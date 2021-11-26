package algorithm.leetcode.linklist_25;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 */
class LC24 {

    public ListNode swapPairs(ListNode head) {


        ListNode preHead = new ListNode(0);
        preHead.next = head;

        ListNode pre = preHead;
        ListNode cur = head;

        while(cur != null && cur.next != null) {

            ListNode next = cur.next;
            cur.next = next.next;
            next.next = cur;
            pre.next = next;
            pre = cur;
            cur = cur.next;

        }

        return preHead.next;
    }
}