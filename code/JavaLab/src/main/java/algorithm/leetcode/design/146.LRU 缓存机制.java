package algorithm.leetcode.design;

import java.util.HashMap;
import java.util.Map;

/**
 * https://leetcode-cn.com/problems/lru-cache/
 * <p>
 * 实现LRU算法 : 可以自定义双向链表和HashMap 实现一个 LinkedHashMap
 * <p>
 * 1. 入队列
 */
class LC146 {

    public static void main(String[] args) {
        new LC146().start();
    }


    void start() {

        LRUCache lRUCache = new LRUCache(2);
        lRUCache.put(1, 1); // 缓存是 {1=1}
        lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
        System.out.println(lRUCache.get(1));    // 返回 1
        lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
        System.out.println(lRUCache.get(2));    // 返回 -1 (未找到)
        lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
        System.out.println(lRUCache.get(1));    // 返回 -1 (未找到)
        System.out.println(lRUCache.get(3));    // 返回 3
        System.out.println(lRUCache.get(4));    // 返回 4
    }


    class LRUCache {


        class Node {

            public Node(int key, int val) {
                this.key = key;
                this.val = val;
            }

            public int key;

            public int val;

            public Node pre;

            public Node next;
        }


        private int size;


        // 记录key值与node的映射关系
        private Map<Integer, Node> hash;

        // 记录链表头节点
        private Node head;

        // 记录链表尾节点
        private Node end;


        public LRUCache(int capacity) {
            this.size = capacity;
        }

        public void movToHead(Node node) {

            // pre == null 说明本来就是首节点, 无需移动
            if (node.pre != null) {

                // 将前一个节点和后一个节点相链接
                node.pre.next = node.next;
                if (node.next != null) {
                    // 双向链接
                    node.next.pre = node.pre;
                } else {
                    // 如果后一个节点为空, 说明当前为最后一个节点,
                    end = node.pre;
                }
                // 首节点pre必须是null
                node.pre = null;

                // 放在head之前, 更新head即可
                node.next = head;
                head.pre = node;
                head = head.pre;
            }

        }

        public int get(int key) {

            if (hash == null) {
                return -1;
            }

            int res = -1;
            // 如果需要的节点存在, 则每次都需要将链表移动到头部
            Node node = hash.get(key);
            if (node != null) {
                res = node.val;
                movToHead(node);
            }
            return res;
        }


        public void put(int key, int value) {

            // 第一次put 初始化HashMap
            if (hash == null) {
                hash = new HashMap<>();
                head = new Node(key, value);
                end = head; // 此时头尾都指向同一个节点
                hash.put(head.key, head);
                return;
            }

            // 后续put, 先判断key是否存在
            Node node = hash.get(key);
            if (node != null) {
                // 如果已经存在key, 更新value值, 并将当前的key节点移动到开头
                node.val = value;
                movToHead(node);
            } else {
                // 不存在key则需要新建头节点作为头节点
                node = new Node(key, value);
                node.next = head;
                head.pre = node;
                head = head.pre;
                hash.put(key, node);

                // 如果超出体积限制, 移除链表末尾节点
                if (hash.size() > size) {
                    hash.remove(end.key);
                    end = end.pre;
                    end.next = null;
                }
            }
        }
    }

}