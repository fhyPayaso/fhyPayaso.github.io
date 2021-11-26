package algorithm.offer.over.dp;

/* ====================================================
#
#   @Author        : fhyPayaso
#   @Email         : 401619823@qq.com
#   @Date          : 2021/3/14 4:03 下午
#   @Description   : 剑指 Offer 14- II. 剪绳子 II
https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/
# ====================================================*/
public class Offer14II {

    public int cuttingRope(int n) {

        // 最大值需要取模，不能使用动态规划，因为取模后无法判断大小
        // 用数学方法, 将绳子拆分成3尽量多的段, 除非最后一段为4不需要拆成(3+1)
        long mod = 1000000007;

        if (n == 1 || n == 2) {
            return 1;
        } else if (n == 3) {
            return 2;
        }

        long sum = 1;
        while (n > 4) {
            sum *= 3;
            sum %= mod;
            n -= 3;
        }

        return (int) ((sum * n) % mod);
    }
}
