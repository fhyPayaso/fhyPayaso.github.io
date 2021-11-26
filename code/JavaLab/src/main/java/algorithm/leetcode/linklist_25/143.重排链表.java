package algorithm.leetcode.linklist_25;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/reorder-list/
 * <p>
 * L0 → L1 → … → Ln - 1 → Ln
 * 转换后
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 */
class LC143 {

    public void reorderList(ListNode head) {

        // 从中间断开
        ListNode p1 = head, p2 = head;
        while (p2.next != null && p2.next.next != null) {
            p1 = p1.next;
            p2 = p2.next.next;
        }
        ListNode cur = p1.next;
        p1.next = null;

        // 后半部分倒序
        ListNode pre = null, next;
        while (cur != null) {
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }

        // 链表合并
        cur = new ListNode(0);
        p1 = head;
        p2 = pre;
        boolean flag = true;
        while (p1 != null || p2 != null) {
            if (flag) {
                cur.next = p1;
                p1 = p1.next;
            } else {
                cur.next = p2;
                p2 = p2.next;
            }
            flag = !flag;
            cur = cur.next;
        }

    }
}