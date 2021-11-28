package algorithm.leetcode.other;

/**
 * https://leetcode-cn.com/problems/reverse-bits/
 * <p>
 * 颠倒给定的 32 位无符号整数的二进制位
 */
class LC190 {

    public int reverseBits(int n) {


        int i = 32;
        int res = 0;
        while (i > 0) {
            res <<= 1; // 结果左移不断*2
            res += n & 1; // n & 1表示最后一位
            n >>= 1; // 原数向右移动不断/2
            i--;
        }
        return res;
    }

    private static final int M1 = 0x55555555; // 01010101010101010101010101010101
    private static final int M2 = 0x33333333; // 00110011001100110011001100110011
    private static final int M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
    private static final int M8 = 0x00ff00ff; // 00000000111111110000000011111111

    /*

    32位无符号整数，如 1111 1111 1111 1111 1111 1111 1111 1111
    表示成16进制        f    f    f    f    f    f    f   f
    一个16进制的f代表二进制的4位
    ffff ffff右移16位，变成 0000 ffff
    ffff ffff左移16位，变成 ffff 0000
    它们俩相或，就可以完成低16位与高16位的交换

    之后的每次分治，都要先与上一个掩码，再进行交换
     */

    // 分治算法
    public int reverseBits1(int n) {
        n = n >>> 1 & M1 | (n & M1) << 1; // 相邻1~1位置进行交换
        n = n >>> 2 & M2 | (n & M2) << 2; // 相邻2~2位置进行交换
        n = n >>> 4 & M4 | (n & M4) << 4; // 相邻4~4位置进行交换
        n = n >>> 8 & M8 | (n & M8) << 8; // 相邻8~8位置进行交换
        return n >>> 16 | n << 16; // 相邻16~16位置进行交换
    }
}