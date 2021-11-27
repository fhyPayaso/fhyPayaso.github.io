package algorithm.leetcode.design;

import java.util.ArrayDeque;
import java.util.Queue;

/**
 * https://leetcode-cn.com/problems/implement-stack-using-queues/
 *
 * 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
 *
 * 实现 MyStack 类：
 *
 * void push(int x) 将元素 x 压入栈顶。
 * int pop() 移除并返回栈顶元素。
 * int top() 返回栈顶元素。
 * boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
 */
class LC225 {

    class MyStack {

        public Queue<Integer> queue;

        public MyStack() {
            queue = new ArrayDeque<>();
        }


        // 只要队尾入队, 将前面的数据全重新入队(新入队的元素在队首)
        public void push(int x) {
            queue.add(x);
            int l = queue.size() - 1;
            while (l-- > 0) {
                queue.add(queue.poll());
            }
        }

        public int pop() {
            // 队首元素一直为最新的
            return queue.remove();
        }

        public int top() {
            return queue.peek();
        }

        public boolean empty() {
            return queue.isEmpty();
        }
    }

}