package algorithm.leetcode.design_5;

import java.util.Stack;

/**
 * https://leetcode-cn.com/problems/min-stack/
 * <p>
 * push(x) —— 将元素 x 推入栈中。
 * pop()—— 删除栈顶的元素。
 * top()—— 获取栈顶元素。
 * getMin() —— 检索栈中的最小元素。
 */
class LC155 {


    // 定义链表实现栈
    class MinStack {

        // 定义节点保存出现过的最小值
        class Node {
            public int val;
            public int min;
            public Node next;

            public Node(int val) {
                this.val = val;
            }
        }

        public Node head;

        public MinStack() {

        }

        public void push(int x) {

            Node sNode = new Node(x);
            if (head == null) {
                sNode.min = sNode.val;
                head = sNode;
            } else {
                // 插入的时候使用头插法, 模拟栈
                sNode.min = Math.min(sNode.val, head.min);
                sNode.next = head;
                head = sNode;
            }
        }

        // 弹出节点移动head即可
        public void pop() {
            head = head.next;
        }

        public int top() {
            return head.val;
        }

        public int getMin() {
            return head.min;
        }
    }

    /**
     * 用栈实现
     * <p>
     * 常规栈和最小栈保持同步操作, 最小栈保存出现的最小值即可
     */
    class MinStack2 {

        private Stack<Integer> stack;

        private Stack<Integer> minStack;

        public MinStack2() {

            stack = new Stack<>();
            minStack = new Stack<>();
            minStack.push(Integer.MAX_VALUE);
        }

        public void push(int x) {
            stack.push(x);
            // 每次都存当前栈中最小值
            minStack.push(Math.min(x, minStack.peek()));
        }

        public void pop() {

            minStack.pop();
            stack.pop();

        }

        public int top() {
            return stack.peek();
        }

        public int getMin() {
            return minStack.peek();
        }
    }

}