package algorithm.leetcode.linklist;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
 * <p>
 * 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中没有重复出现的数字。
 * 返回同样按升序排列的结果链表。
 */
class LC82 {

    public ListNode deleteDuplicates(ListNode head) {

        if (head == null) {
            return null;
        }

        ListNode headPre = new ListNode(0);
        headPre.next = head;

        ListNode pre = headPre;
        ListNode cur = head;

        while (cur != null && cur.next != null) {

            boolean flag = false;
            while (cur.next != null && cur.val == cur.next.val) {
                cur.next = cur.next.next;
                flag = true;
            }

            if (flag) {
                // 直接舍弃当前节点
                cur = cur.next;
                pre.next = cur;
            } else {
                pre = cur;
                cur = cur.next;
            }
        }
        return headPre.next;
    }
}