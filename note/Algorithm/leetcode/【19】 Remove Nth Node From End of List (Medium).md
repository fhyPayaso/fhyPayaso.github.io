
### 【19】 Remove Nth Node From End of List (Medium)

> 题目大意 

删除链表倒数第N个数，

> 解题思路

两个节点指向头，一个先移动n，两个再同时移动，一个到头，另一个就是第n个节点,问题变成了删除一个已知节点

+ 若该节点不为最后一个节点 ： 将下一个节点复制到当前节点，删除下一个节点

+ 若该节点是最后一个节点 :

    + 同时也是第一个节点 : 返回null
    + 不是第一个节点 : 遍历找到倒数第二个节点，next指向null



这题算是两个题的结合了，不过感觉也不应该算Medium

> AC代码

```
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
```