package algorithm.leetcode.linklist;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/partition-list/
 * <p>
 * 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
 * 你应当保留两个分区中每个节点的初始相对位置。
 * <p>
 * in:  [1,4,3,2,5,2], x = 3
 * out: [1,2,2,4,3,5]
 */
class LC86 {

    public ListNode partition(ListNode head, int x) {

        ListNode dump = new ListNode(0);
        dump.next = head;
        ListNode pre1 = dump; // 记录最后一个已经排序完毕的节点
        ListNode pre2 = dump; // 记录当前节点的前一个节点
        ListNode p = head;
        while (p != null) {


            if (p.val < x && pre1.next == p) {
                // 1. 当前节点小于目标值, 但不需要变化位置,正常向下移动即可
                pre1 = p;
                pre2 = p;
                p = p.next;
            } else if (p.val < x) {
                // 2. 当前节点小于目标值, 且需要变化位置

                // 取出当前节点
                ListNode next = p.next;
                pre2.next = next;

                // 将当前节点加入已经排序的节点
                p.next = pre1.next;
                pre1.next = p;
                pre1 = pre1.next;

                p = next;
            } else {
                // 3. 当前节点大于目标值, 记录排序完毕的节点停止移动, 等待新的小值插入
                pre2 = p;
                p = p.next;
            }
        }
        return dump.next;
    }
}