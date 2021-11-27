package algorithm.offer.over.link;

import algorithm.config.ListNode;

import java.util.List;

/* ====================================================
#
#   @Author        : fhyPayaso
#   @Email         : 401619823@qq.com
#   @Date          : 2021/3/12 6:00 下午
#   @Description   : 剑指 Offer 18. 删除链表的节点
#  https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
# ====================================================*/
public class Offer18 {

    public ListNode deleteNode(ListNode head, int val) {

        if (head == null || (head.next == null && head.val == val)) {
            return null;
        }

        ListNode node = head;
        ListNode pre = head;
        while (node != null) {

            if (node.val == val) {
                if (node.next != null) {
                    node.val = node.next.val;
                    node.next = node.next.next;
                } else {
                    pre.next = null;
                }
            }
            pre = node;
            node = node.next;
        }

        return head;
    }
}
