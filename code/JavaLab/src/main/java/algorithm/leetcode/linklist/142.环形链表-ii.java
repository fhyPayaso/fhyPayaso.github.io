package algorithm.leetcode.linklist;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * <p>
 * 判断链表是否有环, 并找到环的入口
 */
class LC142 {

    /*

     假设当前链表存在环, 非环部分长度为A, 相交点已经走的长度为B, 还未走的长度为C

     则有等式 2 * (A+B) = (A+B) + n * (B + C)
     所以 A+B = n * (B+C)
     所以 A = C + (n-1)*(B+C)
     即指针1从开头走A步
     指针2正好能走C步 + (n-1)圈
     */

    public ListNode detectCycle(ListNode head) {

        ListNode p1 = head;
        ListNode p2 = head;
        if (head == null || head.next == null) {
            return null;
        }
        while (p2 != null && p2.next != null) {
            p1 = p1.next;
            p2 = p2.next.next;
            if (p1 == p2) {
                // 说明有环
                break;
            }
        }

        if (p2 == null || p2.next == null) {
            return null;
        }
        p1 = head;//p2在相遇点不动，p1指向头指针
        while (p1 != p2) {
            // 两者同步移动，再次相遇即为环的入口
            p1 = p1.next;
            p2 = p2.next;
        }
        return p1;
    }

}