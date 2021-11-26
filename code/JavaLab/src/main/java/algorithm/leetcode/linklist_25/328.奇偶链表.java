package algorithm.leetcode.linklist_25;

import algorithm.config.ListNode;

/**
 * https://leetcode-cn.com/problems/odd-even-linked-list/
 * <p>
 * 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
 * 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
 */
class LC328 {

    public ListNode oddEvenList(ListNode head) {

        // 分别创建两个新的辅助节点
        ListNode dump1 = new ListNode(0);
        ListNode dump2 = new ListNode(0);
        ListNode p1 = dump1, p2 = dump2;

        ListNode p = head;
        int l = 1;
        while (p != null) {
            // 分别挑出奇数偶数节点加入两条链表
            ListNode next = p.next;
            if (l % 2 == 1) {
                p1.next = p;
                p1 = p1.next;
            } else {
                p2.next = p;
                p2 = p2.next;
            }
            p.next = null;
            p = next;
            l++;
        }
        // 将奇数节点和偶数节点相连
        p1.next = dump2.next;
        return dump1.next;
    }
}