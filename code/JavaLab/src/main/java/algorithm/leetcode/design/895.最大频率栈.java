package algorithm.leetcode.design;

import java.util.HashMap;
import java.util.Stack;

/**
 * https://leetcode-cn.com/problems/maximum-frequency-stack/
 * <p>
 * 实现 FreqStack，模拟类似栈的数据结构的操作的一个类。
 * <p>
 * FreqStack有两个函数：
 * <p>
 * push(int x)，将整数x推入栈中。
 * pop()，它移除并返回栈中出现最频繁的元素。如果最频繁的元素不只一个，则移除并返回最接近栈顶的元素。
 */
class LC895 {

    public class FreqStack {

        public HashMap<Integer, Integer> times;

        public HashMap<Integer, Stack<Integer>> stackMap;

        public int maxTimes;

        public FreqStack() {

            times = new HashMap<>();
            stackMap = new HashMap<>();
            maxTimes = 0;
        }

        public void push(int val) {

            int t = times.getOrDefault(val, 0) + 1;
            times.put(val, t);

            if (t > maxTimes) {
                maxTimes = val;
            }

            Stack<Integer> stack = stackMap.get(t);
            if (stack == null) {
                // 当前出现频率对应的栈
                stack = new Stack<>();
                stackMap.put(t, stack);
            }
            stack.push(val);
        }

        public int pop() {

            // 出现次数最多的数字出栈
            int val = stackMap.get(maxTimes).pop();

            times.put(val, times.get(val) - 1);

            if (stackMap.get(maxTimes).size() == 0) {
                maxTimes--;
            }

            return val;
        }
    }
}