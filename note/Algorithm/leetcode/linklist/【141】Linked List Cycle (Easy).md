
### 【141】Linked List Cycle (Easy)

> 题目大意 

判断一个链表是否存在环

> 解题思路

这题写多了也变水题了。。

两个指针，p1每次走一步，p2每次走两步，对于没有环的链表，p2会先到末尾，而有环的有两种情况:

+ 整个链表就是一个环

+ 链表有一个单一入口，最后形成一个环

对于这两种情况，p1和p2最后一定会相遇

> AC代码

```
    public boolean hasCycle(ListNode head) {
        ListNode p1 = head;
        ListNode p2 = head;
        if (head == null || head.next == null) {
            return false;
        }
        while (p2 != null && p2.next != null) {
            p1 = p1.next;
            p2 = p2.next.next;
            if (p1 == p2) {
                return true;
            }
        }

        return false;
    }

```