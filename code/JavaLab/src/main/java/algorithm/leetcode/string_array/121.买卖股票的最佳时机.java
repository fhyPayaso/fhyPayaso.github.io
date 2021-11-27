package algorithm.leetcode.string_array;

/**
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 */
class LC121 {

    // 贪心
    public int maxProfit(int[] prices) {
        if (prices.length == 0) {
            return 0;
        }

        int minVal = prices[0];
        int res = 0;

        for (int i = 0; i < prices.length; i++) {

            res = Math.max(res, prices[i] - minVal);

            if (prices[i] < minVal) {
                minVal = prices[i];
            }
        }

        return res;
    }
}