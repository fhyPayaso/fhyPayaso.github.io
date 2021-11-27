package algorithm.leetcode.linklist;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/insertion-sort-list/
 * <p>
 * 对链表进行插入排序
 */
class LC147 {

    public static void main(String[] args) {
        ListNode h = new ListNode(4);
        h.next = new ListNode(2);
        h.next.next = new ListNode(1);
        h.next.next.next = new ListNode(3);

        LC147 main = new LC147();
        main.insertionSortList(h);

    }

    public ListNode insertionSortList(ListNode head) {

        ListNode dump = new ListNode(0);
        dump.next = head;

        ListNode pre1 = head;
        ListNode p = head.next;
        while (p != null) {

            // 当前节点作为标志节点
            ListNode q = dump.next;
            ListNode pre2 = dump;
            boolean flag = false;
            // 在开头节点和当前节点之间寻找比当前小的值
            while (q != p) {
                // 找到小于当前值的节点
                if (p.val < q.val) {

                    ListNode next = p.next;
                    pre1.next = next;

                    p.next = pre2.next;
                    pre2.next = p;
                    p = next;
                    flag = true;
                    break;
                }
                pre2 = q;
                q = q.next;
            }
            if (!flag) {
                pre1 = p;
                p = p.next;
            }
        }
        return dump.next;
    }
}