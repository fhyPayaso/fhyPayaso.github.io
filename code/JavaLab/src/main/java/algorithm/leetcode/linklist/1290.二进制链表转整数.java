package algorithm.leetcode.linklist;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer/
 * <p>
 * 给你一个单链表的引用结点head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。
 * <p>
 * 请你返回该链表所表示数字的 十进制值 。
 */
class LC1290 {

    public int getDecimalValue(ListNode head) {

        if (head.next == null) {
            return head.val;
        }

        int res = 0;
        while (head != null) {
            res = (res << 1) + head.val; // 位运算方法
//            res = res * 2 + head.val; // 常规方法
            head = head.next;
        }

        return res;
    }
}