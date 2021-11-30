package algorithm.leetcode.bit;

/**
 * https://leetcode-cn.com/problems/power-of-two/description/
 * <p>
 * 给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。
 * 如果存在一个整数 x 使得n == 2^x ，则认为 n 是 2 的幂次方。
 * <p>
 * 你能够不使用循环/递归解决此问题吗
 */
class LC231 {

    // 循环做法, 记录1的数量, 并不断右移
    public boolean isPowerOfTwo(int n) {

        if (n < 0) {
            return false;
        }

        int num = 0;
        for (int i = 0; i < 32; i++) {
            num += (n & 1);
            n = n >> 1;
            if (num > 1) {
                return false;
            }
        }
        return num == 1;
    }

    // n = 16    1000
    // n-1 = 15  0111
    public boolean isPowerOfTwo1(int n) {
        if (n < 0) return false;
        return (n & (n - 1)) == 0;
    }

}