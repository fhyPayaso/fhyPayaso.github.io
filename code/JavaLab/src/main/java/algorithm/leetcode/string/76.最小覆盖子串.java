package algorithm.leetcode.string;

/**
 * https://leetcode-cn.com/problems/minimum-window-substring/
 * <p>
 * 滑动窗口经典题
 */
class LC76 {

    public String minWindow(String s, String t) {


        int[] need = new int[128];
        int[] window = new int[128];
        int len1 = s.length();
        int len2 = t.length();

        // 记录子串字符频率
        for (int i = 0; i < len2; i++) {
            char c = t.charAt(i);
            need[c]++;
        }

        int left = 0, right = 0;
        int count = 0;
        String res = "";
        int minLen = Integer.MAX_VALUE;

        while (right < len1) {

            char sc = s.charAt(right);
            window[sc]++;
            // 当前字符串在子串中出现过, 且窗口中该字符出现次数未超过子串
            if (need[sc] > 0 && need[sc] >= window[sc]) {
                count++; // 匹配数量增加
            }

            // 子串完全被匹配，开始缩小
            while (count == len2) {

                // 更新结果
                int len = right - left + 1;
                if (len < minLen) {
                    minLen = len;
                    res = s.substring(left, right + 1);
                }

                // 移动左边界
                char tc = s.charAt(left);
                if (window[tc] > 0 && window[tc] <= need[tc]) {
                    count--;
                }
                window[tc]--;
                left++;
            }
            right++;
        }
        return res;

    }
}