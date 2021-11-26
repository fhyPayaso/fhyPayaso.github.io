package algorithm.leetcode.linklist_25;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/sort-list/
 */
class LC148 {

    /**
     * 链表归并排序思路
     * 1. 将链表从中间断开
     * 2. 分别对左右链表进行排序
     * 3. 将左右排序表后的链表进行合并
     */
    public ListNode sortList(ListNode head) {

        if (head == null || head.next == null) {
            return head;
        }

        ListNode p1 = head, p2 = head;
        // 找到中点并断开
        ListNode pre = p1;
        while (p2 != null && p2.next != null) {
            pre = p1;
            p1 = p1.next;
            p2 = p2.next.next;
        }

        pre.next = null;

        ListNode left = sortList(head);
        ListNode right = sortList(p1);
        return merge(left, right);
    }


    public ListNode merge(ListNode node1, ListNode node2) {
        ListNode dump = new ListNode(0);
        ListNode p = dump;
        while (node1 != null || node2 != null) {

            if (node1 == null) {
                p.next = node2;
                break;
            }
            if (node2 == null) {
                p.next = node1;
                break;
            }

            if (node1.val < node2.val) {
                p.next = node1;
                node1 = node1.next;
            } else {
                p.next = node2;
                node2 = node2.next;
            }
            p = p.next;
        }
        return dump.next;
    }


    //////////////////////////////////////////////////

//    // 快速排序
//    public ListNode sortList1(ListNode head) {
//
//    }
}