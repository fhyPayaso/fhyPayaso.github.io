package algorithm.leetcode.bit;

/**
 * https://leetcode-cn.com/problems/number-of-1-bits/description/
 * <p>
 * 编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数
 */
class LC191 {

    /**
     * n&n-1 表示把结果中最低位的1 变 0
     * 如  6(110) & 5(101) = 100 继续 4(100) & 3(010) = 000
     */
    public int hammingWeight(int n) {
        int count = 0;
        while (n != 0) {
            n &= n - 1;
            count++;
        }

        return count;
    }

    // Integer.bitCount()
    public int hammingWeight1(int i) {

        i = i - ((i >>> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
        i = (i + (i >>> 4)) & 0x0f0f0f0f;
        i = i + (i >>> 8);
        i = i + (i >>> 16);
        return i & 0x3f;
    }


}