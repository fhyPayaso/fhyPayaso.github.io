package algorithm.leetcode.math;

/**
 * https://leetcode-cn.com/problems/factorial-trailing-zeroes/description/
 * <p>
 * 给定一个整数 n ，返回 n! 结果中尾随零的数量
 */
class LC172 {

    public int trailingZeroes(int n) {

        // 10 9 8 7 6 5 4 3 2 1(有几个5的倍数)

        int res = 0;
        while (n > 0) {
            n /= 5;
            res += n;
        }
        return res;
    }
}