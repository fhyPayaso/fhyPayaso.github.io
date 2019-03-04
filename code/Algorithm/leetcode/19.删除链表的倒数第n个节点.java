/*
 * @lc app=leetcode.cn id=19 lang=java
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (32.32%)
 * Total Accepted:    30.7K
 * Total Submissions: 95.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
 * 
 */
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; } }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {

        ListNode t1 = head;
        ListNode t2 = head;

        while (n-- != 0) {
            t1 = t1.next;
        }

        while (t1 != null) {
            t1 = t1.next;
            t2 = t2.next;
        }

        if (t2.next != null) {
            t2.val = t2.next.val;
            t2.next = t2.next.next;
        } else {

            if (t2 == head) {
                return null;
            }
            ListNode t = head;
            while (t != null) {
                if (t.next == t2) {
                    t.next = null;
                    break;
                }
                t = t.next;
            }
        }

        return head;
    }
}
