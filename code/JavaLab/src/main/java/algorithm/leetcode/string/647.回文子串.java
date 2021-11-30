package algorithm.leetcode.string;

/**
 * https://leetcode-cn.com/problems/palindromic-substrings/
 * <p>
 * 统计字符串中回文串数量
 */
class LC647 {

    public int countSubstrings(String s) {

        // 转成char速度更快
        char[] str = s.toCharArray();
        int res = 0;
        for (int i = 0; i < str.length; i++) {
            // 从中心扩展, 分别计算奇数情况和偶数情况
            res += helper(str, i, i);
            res += helper(str, i, i + 1);
        }
        return res;
    }

    // 计算有多少个回文
    public int helper(char[] str, int left, int right) {
        int res = 0;
        while (left >= 0 && right < str.length && str[left] == str[right]) {
            res++;
            left--;
            right++;
        }
        return res;
    }

}