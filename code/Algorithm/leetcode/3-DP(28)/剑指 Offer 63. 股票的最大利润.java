package algorithm.offer.over.dp;

/* ====================================================
#
#   @Author        : fhyPayaso
#   @Email         : 401619823@qq.com
#   @Date          : 2021/3/13 8:27 下午
#   @Description   : 剑指 Offer 63. 股票的最大利润
# https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
# ====================================================*/
public class Offer63 {


    public int maxProfit(int[] prices) {

        if (prices.length == 0) {
            return 0;
        }

        int minVal = Integer.MAX_VALUE;
        int maxRes = Integer.MIN_VALUE;

        for (int i = 0; i < prices.length; i++) {
            int res = Math.max(0, prices[i] - minVal);
            maxRes = Math.max(res, maxRes);
            minVal = Math.min(minVal, prices[i]);
        }

        return maxRes;
    }
}
