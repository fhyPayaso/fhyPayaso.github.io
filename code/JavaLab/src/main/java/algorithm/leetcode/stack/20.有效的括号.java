package algorithm.leetcode.stack;

import java.util.Stack;

/**
 * https://leetcode-cn.com/problems/valid-parentheses/
 * <p>
 * <p>
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * <p>
 * 有效字符串需满足：
 * <p>
 * 1. 左括号必须用相同类型的右括号闭合
 * 2. 左括号必须以正确的顺序闭合。
 */
class LC20 {

    public boolean isValid(String s) {

        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {

            char c = s.charAt(i);

            if ('{' == c || '[' == c || '(' == c) {
                stack.add(c);
            } else {

                if (stack.isEmpty()) {
                    return false;
                }

                char top = stack.pop();

                if ((c == '}' && top == '{') || (c == ']' && top == '[') || (c == ')' && top == '(')) {
                    continue;
                } else {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }
}