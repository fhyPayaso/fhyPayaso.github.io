package algorithm.leetcode.linklist;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/add-two-numbers/
 * <p>
 * 给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
 * <p>
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * <p>
 * 你可以假设除了数字0之外，这两个数都不会以0开头。
 */
class LC02 {

    // 方法1: 不构建新链表
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        if (l1 == null || (l1.val == 0 && l1.next == null)) {
            return l2;
        }

        if (l2 == null || (l2.val == 0 && l2.next == null)) {
            return l1;
        }

        // 求两个链表长度
        int len1 = 0, len2 = 0;
        ListNode p1 = l1, p2 = l2;
        while (p1 != null) {
            p1 = p1.next;
            len1++;
        }
        while (p2 != null) {
            p2 = p2.next;
            len2++;
        }

        // 保证l1 永远是长的
        if (len2 > len1) {
            ListNode temp = l2;
            l2 = l1;
            l1 = temp;
        }
        p1 = l1;
        p2 = l2;


        // 将两者按位相加
        int j = 0;
        ListNode pre = new ListNode(0);
        pre.next = p1;
        while (p1 != null && p2 != null) {
            // 同位相加, 并考虑进位
            p1.val += (p2.val + j);
            if (p1.val >= 10) {
                p1.val -= 10;
                j = 1;
            } else {
                j = 0;
            }
            pre = p1;
            p1 = p1.next;
            p2 = p2.next;
        }

        // 进位存在, 两种情况
        // 1. 两者长度相同, 目前均为null, 需要在结尾加一位
        // 2. l1长度长, 需要在p1位置+1, 并处理下面的进位
        while (j > 0) {

            if (p1 != null) {

                p1.val += j;
                if (p1.val >= 10) {
                    p1.val -= 10;
                    j = 1;
                } else {
                    j = 0;
                }
                pre = p1;
                p1 = p1.next;
            } else {
                pre.next = new ListNode(j);
                j = 0;
            }
        }

        return l1;
    }

    // 方法2: 构建新链表
    public ListNode addTwoNumbers1(ListNode l1, ListNode l2) {

        ListNode dump = new ListNode(0);
        ListNode p = dump;
        int j = 0;
        while (l1 != null || l2 != null || j > 0) {

            int val = j;
            if (l1 != null) {
                val += l1.val;
            }
            if (l2 != null) {
                val += l2.val;
            }

            p.next = new ListNode(val % 10);
            j = val / 10;
            p = p.next;

            if (l1 != null) {
                l1 = l1.next;
            }

            if (l2 != null) {
                l2 = l2.next;
            }
        }
        return dump.next;
    }
}