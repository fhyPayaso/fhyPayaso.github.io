package algorithm.leetcode.linklist;

import algorithm.config.ListNode;

import java.util.Stack;

/**
 * https://leetcode-cn.com/problems/add-two-numbers-ii/
 * <p>
 * 两数相加, 但是数字为正序, 且不能改变原链表(不能翻转)
 */
class LC445 {

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // 两个栈记录并构建新链表
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();

        while (l1 != null) {
            s1.push(l1.val);
            l1 = l1.next;
        }

        while (l2 != null) {
            s2.push(l2.val);
            l2 = l2.next;
        }

        ListNode dump = new ListNode(0);
        int j = 0;
        while (!s1.empty() || !s2.empty() || j > 0) {

            int val = j;
            if (!s1.empty()) val += s1.pop();
            if (!s2.empty()) val += s2.pop();
            j = val / 10;

            // 注意采用头插法
            ListNode node = new ListNode(val % 10);
            node.next = dump.next;
            dump.next = node;
        }
        return dump.next;
    }
}