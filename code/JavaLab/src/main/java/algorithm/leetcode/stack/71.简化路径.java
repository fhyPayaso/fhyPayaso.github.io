package algorithm.leetcode.stack;

import java.util.Stack;

/**
 * https://leetcode-cn.com/problems/simplify-path/
 */
class LC71 {

    public static void main(String[] args) {

        LC71 main = new LC71();
        System.out.println(main.simplifyPath("/a/./b/../../c/"));
    }

    public String simplifyPath(String path) {

        Stack<String> stack = new Stack<>();
        String[] list = path.split("/");

        for (int i = 0; i < list.length; i++) {

            String s = list[i];
            if (s.isEmpty() || s.equals(".")) {
                continue;
            }

            if ("..".equals(s)) {
                if (!stack.empty()) {
                    stack.pop();
                }
            } else {
                stack.push(s);
            }
        }

        StringBuilder builder = new StringBuilder();
        while (!stack.empty()) {
            String s = stack.pop();
            builder.insert(0, s);
            builder.insert(0, "/");
        }
        return builder.length() == 0 ? "/" : builder.toString();
    }
}