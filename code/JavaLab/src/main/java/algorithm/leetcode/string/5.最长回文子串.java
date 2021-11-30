package algorithm.leetcode.string;

/**
 * https://leetcode-cn.com/problems/longest-palindromic-substring/
 * <p>
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 */
class LC05 {

    public static void main(String[] args) {
        LC05 main = new LC05();
        System.out.println(main.longestPalindrome("cbbd"));
    }

    public String longestPalindrome(String s) {


        char[] str = s.toCharArray();
        int len = str.length;

        boolean[][] dp = new boolean[len][len];
        int res = 0;
        int left = 0, right = 0;

        // 对于每个长度进行遍历
        for (int l = 0; l < len; l++) {

            // 遍历开始位置, 不相等则计算下一个开始位置
            for (int i = 0; i < len - l; i++) {
                // 计算结束位置
                int j = i + l;

                // 如果相等, 则对应的dp[i][j]向内收缩
                if (s.charAt(i) == s.charAt(j)) {

                    if (l == 0 || l == 1) {
                        dp[i][j] = true;
                    } else {
                        // 从中间开始向外扩展
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    int cur = l + 1;
                    if (dp[i][j] && cur >= res) {
                        res = cur;
                        left = i;
                        right = j;
                    }
                }
            }
        }
        return new String(str, left, right - left + 1);
    }

    // 中心扩展遍历寻找
    public String longestPalindrome1(String s) {
        // 转成char速度更快
        char[] str = s.toCharArray();
        int offset = 0, count = 0;
        for (int i = 0; i < str.length; i++) {
            // 从中心扩展, 分别计算奇数情况和偶数情况

            int len1 = helper(str, i, i);
            if (len1 > count) {
                count = len1;
                offset = i - len1 / 2;
            }

            int len2 = helper(str, i, i + 1);
            if (len2 > count) {
                count = len2;
                offset = i - (len2 / 2 - 1);
            }
        }
        return new String(str, offset, count);
    }


    // 计算回文长度
    public int helper(char[] str, int left, int right) {
        int res = 1;
        while (left >= 0 && right < str.length && str[left] == str[right]) {
            res = Math.max(res, right - left + 1);
            left--;
            right++;
        }
        return res;
    }
}