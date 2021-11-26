package algorithm.leetcode.linklist_25;


/**
 * https://leetcode-cn.com/problems/copy-list-with-random-pointer/
 * <p>
 * 给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
 * <p>
 * 构造这个链表的深拷贝。深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
 * 新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
 * 复制链表中的指针都不应指向原链表中的节点
 */
class LC138 {

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

    public Node copyRandomList(Node head) {

        // 1. 在每个节点后面复制一个相同的新节点
        Node p = head;
        while (p != null) {
            Node node = new Node(p.val);
            Node next = p.next;
            node.next = next;
            p.next = node;
            p = next;
        }

        // 2. 复制随机指针指向
        p = head;
        while (p != null) {
            if(p.random != null) {
                p.next.random = p.random.next;
            }

            p = p.next.next;
        }

        // 3. 链表分离
        Node dump = new Node(0);
        Node q = dump;
        p = head;
        while (p != null) {
            q.next = p.next;
            q = q.next;

            p.next = p.next.next;
            p = p.next;
        }
        return dump.next;
    }
}