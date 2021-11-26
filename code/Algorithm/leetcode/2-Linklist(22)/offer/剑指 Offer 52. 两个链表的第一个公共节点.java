package algorithm.offer.over.link;

import algorithm.config.ListNode;

/* ====================================================
#
#   @Author        : fhyPayaso
#   @Email         : 401619823@qq.com
#   @Date          : 2021/3/12 8:42 下午
#   @Description   : 剑指 Offer 52. 两个链表的第一个公共节点
# https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
# ====================================================*/
public class Offer52 {

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        /**
         * 假设两个链表有交点
         *
         * 设两个链表重合长度为c
         * 两个链表的长度分别为 a + c , b + c
         *
         * 则有 a+c+b = b+c+a
         *
         * 说明两个链表遍历完自身后， 再去遍历对方的多于长度, 则两个指针一定会相交
         *
         * 若两个指针没有交点，说明c = 0， 同样成立
         *
         *
         *
         *
         */


        ListNode h1 = headA;
        ListNode h2 = headB;

        while (h1 != h2) {
            h1 = h1 == null ? headB : h1.next;
            h2 = h2 == null ? headA : h2.next;
        }
        return h1;
    }

}
