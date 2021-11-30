package algorithm.leetcode.math;

/**
 * https://leetcode-cn.com/problems/power-of-four/description/
 *
 * 判断一个数是不是4的幂次方
 */
class LC342 {

    public boolean isPowerOfFour(int n) {
        double diff = Math.log10(n) / Math.log10(4);
        return diff == (int) diff;
    }

}