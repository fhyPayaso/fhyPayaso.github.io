package algorithm.offer.over.dp;

/* ====================================================
#
#   @Author        : fhyPayaso
#   @Email         : 401619823@qq.com
#   @Date          : 2021/3/14 3:12 下午
#   @Description   : 剑指 Offer 14- I. 剪绳子
#   https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
# ====================================================*/
public class Offer14I {

//    public int cuttingRope(int n) {
//      数学方法，尽量拆分成多个3相乘
//        if (n == 1 || n == 2) {
//            return 1;
//        }
//        if (n == 3) {
//            return 2;
//        }
//        int sum = 1;
//        while (n > 4) {
//            sum *= 3;
//            n -= 3;
//        }
//        return sum * n;
//    }

    public int cuttingRope(int n) {

        int[] dp = new int[n + 1];
        dp[1] = 1; // 长度为1不能分割
        dp[2] = 1; // 长度为2 只能1*1

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                // j表示切到第几个位置，
                // j * (i - j) 表示对长度为i的绳子，切一刀 ,左右相乘
                // j * dp[i - j]  表示对长度为i的绳子，先切一刀 , 用左值 * 剩余长度的最优解
                int m = Math.max(j * (i - j), j * dp[i - j]);
                dp[i] = Math.max(dp[i], m);
            }
        }

        return dp[n];
    }
}
