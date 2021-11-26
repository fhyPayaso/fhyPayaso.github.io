package algorithm.leetcode.design_5;

import java.util.Stack;

/**
 * https://leetcode-cn.com/problems/implement-queue-using-stacks/
 * <p>
 * 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty)
 * <p>
 * 队列是先进先出, 栈是后进先出
 * <p>
 * void push(int x) 将元素 x 推到队列的末尾
 * int pop() 从队列的开头移除并返回元素
 * int peek() 返回队列开头的元素
 * boolean empty() 如果队列为空，返回 true ；否则，返回 false
 */
class LC232 {

    class MyQueue {

        public Stack<Integer> s1 = new Stack<>();
        public Stack<Integer> s2 = new Stack<>();

        public MyQueue() {
        }


        // s1作为存入栈
        public void push(int x) {
            s1.push(x);
        }


        public int pop() {
            // 只要s2为空, s1不为空, 便将s1数据倒入s2
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.pop());
                }
            }
            return s2.pop();
        }

        public int peek() {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.pop());
                }
            }
            return s2.peek();
        }

        // 两个栈都空才为真正的空
        public boolean empty() {
            return s1.empty() && s2.empty();
        }
    }
}