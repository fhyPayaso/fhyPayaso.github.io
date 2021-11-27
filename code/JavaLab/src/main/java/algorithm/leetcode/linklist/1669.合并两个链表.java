package algorithm.leetcode.linklist;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/merge-in-between-linked-lists/
 * <p>
 * 将一个链表合并到另一个链表中间
 */
class LC1669 {


    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {

        int index = 0;
        ListNode preA = null, nodeB = null; // 记录A的前一个和B的当前一个
        ListNode p = list1;

        while (p != null) {
            // 遇到b直接结束
            if (index == b) {
                nodeB = p;
                break;
            }
            // 记录到a的前一个
            if (index < a)
                preA = p;
            p = p.next;
            index++;
        }

        if (preA == null || nodeB == null) {
            return null;
        }

        // 先连接尾部
        p = list2;
        while (p != null && p.next != null) {
            p = p.next;
        }
        p.next = nodeB.next;
        nodeB.next = null;
        // 后连接头部
        preA.next = list2;

        return list1;
    }

}