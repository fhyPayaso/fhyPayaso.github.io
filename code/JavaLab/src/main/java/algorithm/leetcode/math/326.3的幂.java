package algorithm.leetcode.math;

/**
 * https://leetcode-cn.com/problems/power-of-three/description/
 * 判断一个数是否是3的幂次方
 */
class LC326 {


    public boolean isPowerOfThree(int n) {
        // 由对数换底公式 log_3(n) = log(n) / log(3), 判断结果是不是整数即可
        double diff = Math.log10(n) / Math.log10(3);
        return diff == (int) diff;
    }
}