package algorithm.leetcode.search;

import java.util.ArrayList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 * <p>
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 有效括号组合需满足：左括号必须以正确的顺序闭合。
 */
class LC22 {

    List<String> res = new ArrayList<>();

    public List<String> generateParenthesis(int n) {
        helper(0, 0, n, "");
        return res;
    }


    /**
     * @param leftNum  左括号数量
     * @param rightNum 右括号数量
     * @param n        要求括号总对数
     */
    public void helper(int leftNum, int rightNum, int n, String str) {

        /**
         * 三种减枝情况
         * 1. 左括号数量大于n
         * 2. 右括号数量大于n
         * 3. 右括号数量大于左括号, 因为右括号无法通过后续添加左括号匹配
         */
        if (leftNum > n || rightNum > n || rightNum > leftNum) {
            return;
        }

        if (leftNum == n && rightNum == n) {
            res.add(str);
            return;
        }

        // 分别添加左右两种括号搜索
        helper(leftNum + 1, rightNum, n, str + "(");
        helper(leftNum, rightNum + 1, n, str + ")");
    }

}
