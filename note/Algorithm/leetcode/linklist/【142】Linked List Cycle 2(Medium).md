
### 【142】Linked List Cycle 2(Medium)

> 题目大意 

判断一个链表是否存在环,如果有的话，返回环的入口节点

> 解题思路

上题的基础上，又要得出入口节点，首先的思路肯定还是快慢指针判断是否有环

下一步的做法是: **p1指针不动，p2指针重新指向头指针，两者每次一步同时移动，再次相遇的节点即为入口节点**

这个结论需要一点推导:

+ 首先设头结点为h，环入口节点为a，初次相遇节点为b

+ 设环的长为r, h到a的距离为ha，a到b的距离为ab,整个链表长度为L

首先考虑第一次相遇的时候

+ p1节点走的距离为ha+ab

+ p2节点走的距离为ha + ab + nr

这里面的n至少为1，ha距离越长1越大，代表p1刚进入环时，p2已经走了n-1圈

因为p2速度为p1两倍，可列方程 : 

```
2(ha + ab) = ha + ab + nr  // p2路程等于p1两倍

ha + ab = nr = (n-1)r + r //提出一个r

ha = (n-1)r + (r - ab)  //其中n>=1, r-a为相遇点b到入口点a的剩余距离

```

若n=1,则p2从头结点开始走到环入口的距离正好等于相遇点p1到入口的剩余距离

若n>1，则p1指针多走n-1圈即可


> AC代码

```
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

```