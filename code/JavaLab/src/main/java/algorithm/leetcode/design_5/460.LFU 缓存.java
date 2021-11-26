package algorithm.leetcode.design_5;

import java.util.HashMap;

/**
 * https://leetcode-cn.com/problems/lfu-cache/
 * <p>
 * LFUCache(int capacity) - 用数据结构的容量capacity 初始化对象
 * int get(int key)- 如果键存在于缓存中，则获取键的值，否则返回 -1。
 * void put(int key, int value)- 如果键已存在，则变更其值；
 * 如果键不存在，请插入键值对。当缓存达到其容量时，则应该在插入新项之前，使最不经常使用的项无效。
 * 在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最近最久未使用 的键。
 */
class LC460 {

    public static void main(String[] args) {
        new LC460().start();
    }

//    ["LFUCache","put","put","get","get","get","put","put","get","get","get","get"]
//            [[3],[2,2],[1,1],[2],[1],[2],[3,3],[4,4],[3],[2],[1],[4]]

    //    ["LFUCache","put","put","get","put","get","get","put","get","get","get"]
//            [[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]
    void start() {

//        LC460.LFUCache lFUCache = new LC460.LFUCache(2);
//        lFUCache.put(1, 1); // 缓存是 {1=1(1)}
//        lFUCache.put(2, 2); // 缓存是 {2=2(1), 1=1(1)}
//        System.out.println("1: " + lFUCache.get(1));    // 返回 1 缓存是 {1=1(2), 2=2(1)}
//        lFUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1(2), 3=3(1)}
//        System.out.println("2: " + lFUCache.get(2));    // 返回 -1 (未找到)
//        System.out.println("3: " + lFUCache.get(3));    // 返回 3 缓存是 {3=3(2), 1=1(2)}
//        lFUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {3=3(2), 4=4(1)}
////        lFUCache.log();
//        System.out.println("4: " + lFUCache.get(1));    // 返回 -1 (未找到)
//        System.out.println("5: " + lFUCache.get(3));    // 返回 3 缓存是 {3=3(3), 4=4(1)}
//        System.out.println("6: " + lFUCache.get(4));    // 返回 4 缓存是 {3=3(3), 4=4(2)}
        // 1 -1 3 -1 3 4

        // --------------------------------------------------------------------------------

//        LC460.LFUCache lFUCache = new LC460.LFUCache(3);
//        lFUCache.put(2, 2); // 缓存是 {2=2(1)}
//        lFUCache.put(1, 1); // 缓存是 {1=1(1), 2=2(1)}
//        System.out.println("1: " + lFUCache.get(2));  // 返回 2 缓存是 {2=2(2), 1=1(1)}
//        System.out.println("2: " + lFUCache.get(1));  // 返回 1 缓存是 {1=1(2), 2=2(2)}
//        System.out.println("3: " + lFUCache.get(2));  // 返回 2 缓存是 {2=2(3), 1=1(2)}
//        lFUCache.put(3, 3); // 缓存是 {2=2(3), 1=1(2), 3=3(1)}
//        lFUCache.put(4, 4); // 缓存是 {2=2(3), 1=1(2), 4=4(1)}
//        System.out.println("4: " + lFUCache.get(3));  // 返回 -1
//        System.out.println("5: " + lFUCache.get(2));  // 返回 2 缓存是 {2=2(4), 1=1(2), 4=4(1)}
//        System.out.println("6: " + lFUCache.get(1));  // 返回 1 缓存是 {2=2(4), 1=1(3), 4=4(1)}
//        System.out.println("7: " + lFUCache.get(4));  // 返回 4 缓存是 {2=2(4), 1=1(3), 4=4(2)}
////        lFUCache.log();

        // ------------------------------------------------------
//        ["LFUCache","put","get","put","get","get"]
//[[1],[2,1],[2],[3,2],[2],[3]]


//        LC460.LFUCache lFUCache = new LC460.LFUCache(1);
//        lFUCache.put(2, 1); // 缓存是 {2=1(1)}
//        System.out.println("1: " + lFUCache.get(2));  // 返回 1 缓存是 {2=1(2)}
//        lFUCache.put(3, 2); // 缓存是 {2=1(1)}
//        System.out.println("2: " + lFUCache.get(2));  // 返回 1 缓存是 {2=1(2)}
//        System.out.println("3: " + lFUCache.get(3));  // 返回 1 缓存是 {2=1(2)}
//        lFUCache.log();

    }




    class LFUCache {

        private HashMap<Integer, Node> cache;

        private HashMap<Integer, DoubleLinklist> timesHash;

        private int capacity;

        private int minTimes;

        public LFUCache(int capacity) {
            this.capacity = capacity;
            cache = new HashMap<>();
            timesHash = new HashMap<>();
        }

        public int get(int key) {
            Node node = cache.get(key);
            if (node == null) {
                return -1;
            }
            refreshHash(node);
            return node.val;
        }

        public void put(int key, int value) {

            if (capacity == 0) {
                return;
            }

            Node node = cache.get(key);
            if (node != null) {
                node.val = value;
                refreshHash(node);
            } else {
                // 如果当前已经满了, 需要先移除
                if (cache.size() == capacity) {
                    DoubleLinklist minTimesLink = timesHash.get(minTimes);
                    cache.remove(minTimesLink.last().key);
                    minTimesLink.remove(minTimesLink.last());
                }

                node = new Node(key, value);
                cache.put(key, node);
                DoubleLinklist link = timesHash.get(1); // 新建的出现次数都是1
                if (link == null) {
                    link = new DoubleLinklist();
                    timesHash.put(1, link);
                }
                link.add(node);
                minTimes = 1;
            }

        }

        public void refreshHash(Node node) {
            int time = node.times;
            DoubleLinklist linklist = timesHash.get(time);
            linklist.remove(node);
            if (time == minTimes && linklist.empty()) {
                minTimes += 1;
            }


            node.times++;
            DoubleLinklist curLinklist = timesHash.get(node.times);
            if (curLinklist == null) {
                curLinklist = new DoubleLinklist();
                timesHash.put(node.times, curLinklist);
            }
            curLinklist.add(node);
        }

        class Node {

            public Node() {
            }

            public Node(int key, int val) {
                this.key = key;
                this.val = val;
                this.times = 1;
            }

            public int key;

            public int val;

            public int times;

            public Node next;

            public Node pre;
        }

        class DoubleLinklist {

            public Node head;

            public Node tail;

            public DoubleLinklist() {
                this.head = new Node();
                this.tail = new Node();
                head.next = tail;
                tail.pre = head;
            }

            public void remove(Node node) {
                node.pre.next = node.next;
                node.next.pre = node.pre;
            }

            public void add(Node node) {
                node.next = head.next;
                head.next.pre = node;

                head.next = node;
                node.pre = head;
            }

            public Node last() {
                return tail.pre;
            }

            public boolean empty() {
                return head.next == tail;
            }


        }
    }

    /**
     * O(n)解法 会超时。。。。
     */
    class LFUCache1 {


        class Node {

            public Node(int key, int val) {
                this.key = key;
                this.val = val;
                this.times = 1;
            }

            public int key;

            public int val;

            public int times;

            public Node next;

            public Node pre;
        }

        public HashMap<Integer, Node> hash;

        public int size;

        public Node head;

        public Node end;


        public LFUCache1(int capacity) {
            size = capacity;
        }

        // 将当前节点根据出现频率不断向前移动(次数相等的也向前移动)
        public void adjustLinkList(Node node) {
            if (node.pre == null) {
                return;
            }

            // 向前找到第一个大于当前节点出现次数的节点
            Node p = node;
            while (p.pre != null && node.times >= p.pre.times) {
                p = p.pre;
            }

            // 没向前移动不需要处理
            if (p == node) {
                return;
            }

            // 前面节点和后面节点相连
            node.pre.next = node.next;
            if (node.next == null) {
                end = node.pre;
            } else {
                // 反向连接
                node.next.pre = node.pre;
            }


            if (p.pre == null) {
                // 说明node出现次数最多
                node.pre = null;
                node.next = p;
                p.pre = node;
                head = node;
            } else {
                // 将node放在p前面

                node.pre = p.pre;
                p.pre.next = node;

                p.pre = node;
                node.next = p;
            }

        }

        public int get(int key) {

            if (size == 0 || hash == null) {
                return -1;
            }

            Node node = hash.get(key);
            if (node != null) {
                int val = node.val;
                node.times++;
                adjustLinkList(node);
                return val;
            }
            return -1;
        }

        public void put(int key, int value) {

            if (size == 0) {
                return;
            }

            // 初始化
            if (hash == null) {
                hash = new HashMap<>();
                Node node = new Node(key, value);
                hash.put(key, node);
                head = node;
                end = node;
                return;
            }

            // 查找是否已经存在
            Node node = hash.get(key);
            if (node != null) {
                // 如果key已经存在
                node.val = value;
                node.times++;
                adjustLinkList(node);
            } else {
                // 不存在直接新建, 新节点放在队尾
                node = new Node(key, value);
                hash.put(key, node);
                // 超出容积, 移除最后一个
                if (hash.size() > size) {
                    hash.remove(end.key);
                    end = end.pre;
                    if (end != null) {
                        end.next = null;
                    }
                }

                if (hash.size() == 1) {
                    head = node;
                    end = node;
                    return;
                }

                end.next = node;
                node.pre = end;
                end = end.next;
                adjustLinkList(node);
            }

        }
    }


}