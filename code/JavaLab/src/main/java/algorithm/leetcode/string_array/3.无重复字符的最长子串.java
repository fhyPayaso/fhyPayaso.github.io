package algorithm.leetcode.string_array;

/**
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * <p>
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 */
class LC03 {


    // 经典滑动窗口
    public int lengthOfLongestSubstring(String s) {

        if (s == null || s.length() == 0) {
            return 0;
        }


        int res = 0;
        int left = 0, right = 0;
        int[] hash = new int[256];

        while (right < s.length()) {

            // 滑动窗口加入新字符
            char c = s.charAt(right);
            hash[c]++;

            // 如果该字符已经存在
            while (hash[c] > 1) {
                // 窗口从左侧开始缩小
                hash[s.charAt(left)]--;
                left++;
            }

            // 记录最大滑动窗口长度
            res = Math.max(res, right - left + 1);
            right++;
        }

        return res;
    }

}