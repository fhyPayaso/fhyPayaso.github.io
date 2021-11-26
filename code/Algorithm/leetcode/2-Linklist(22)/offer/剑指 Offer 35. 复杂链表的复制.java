package algorithm.offer.over.link;

import java.util.HashMap;
import java.util.Map;

/* ====================================================
#
#   @Author        : fhyPayaso
#   @Email         : 401619823@qq.com
#   @Date          : 2021/3/13 9:47 下午
#   @Description   : 剑指 Offer 35. 复杂链表的复制
#  https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
# ====================================================*/
public class Offer35 {

    class Node {
        int val;
        Node next;
        Node random;

        public Node(int val) {
            this.val = val;
            this.next = null;
            this.random = null;
        }
    }

    // 原地修改
    public Node copyRandomList(Node head) {

        if(head == null) {
            return null;
        }

        // 1. 先在每个节点后面复制一个一样的节点
        Node p = head;

        while (p != null) {
            Node node = new Node(p.val);
            node.next = p.next;
            p.next = node;
            p = p.next.next;
        }

        // 2. 将随机指针进行处理
        p = head;
        while (p != null) {
            if (p.random == null) {
                p.next.random = null;
            } else {
                p.next.random = p.random.next;
            }

            p = p.next.next;
        }

        // 3. 将两个链表进行分离, 不能改变原链表

        Node p1 = head;
        Node p2 = head.next;
        Node res = p2;
        while (p1.next != null && p2.next != null) {

            Node n1 = p1.next.next;
            Node n2 = p2.next.next;

            p1.next = n1;
            p2.next = n2;

            p1 = n1;
            p2 = n2;
        }
        p1.next = null;
        p2.next = null;
        return res;

    }


//    // 简单方法，用hashmap,
//    public Node copyRandomList(Node head) {
//
//        Map<Node, Node> map = new HashMap<>();
//
//        Node p = head;
//        // 先复制值
//        while (p != null) {
//            map.put(p, new Node(p.val));
//            p = p.next;
//        }
//
//        // 复制指针
//        p = head;
//        while (p != null) {
//            map.get(p).next = map.get(p.next);
//            map.get(p).random = map.get(p.random);
//            p = p.next;
//        }
//
//
//        return map.get(head);
//
//    }

}
