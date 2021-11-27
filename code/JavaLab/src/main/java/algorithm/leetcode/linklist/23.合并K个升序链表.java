package algorithm.leetcode.linklist;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/
 */
class LC23 {


    public ListNode mergeKLists(ListNode[] lists) {
        return helper(lists, 0, lists.length - 1);
    }

    public ListNode helper(ListNode[] lists, int left, int right) {

        if (left > right) {
            return null;
        }

        if (left == right) {
            return lists[left];
        }

        if (left + 1 == right) {
            return merge(lists[left], lists[right]);
        }

        int mid = (left + right) / 2;
        // 分别合并左右半部分链表
        ListNode node1 = helper(lists, left, mid);
        ListNode node2 = helper(lists, mid + 1, right);
        return merge(node1, node2);
    }


    public ListNode merge(ListNode p1, ListNode p2) {

        ListNode dump = new ListNode(0);
        ListNode p = dump;

        while (p1 != null || p2 != null) {

            if (p1 == null) {
                p.next = p2;
                break;
            }

            if (p2 == null) {
                p.next = p1;
                break;
            }

            if (p1.val > p2.val) {
                p.next = new ListNode(p1.val);
                p1 = p1.next;
            } else {
                p.next = new ListNode(p2.val);
                p2 = p2.next;
            }
            p = p.next;
        }
        return dump.next;
    }
}