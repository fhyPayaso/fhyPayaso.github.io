package algorithm.leetcode.string_array.unclass;

/**
 * https://leetcode-cn.com/problems/plus-one/description/
 */
class LC66 {

    public int[] plusOne(int[] digits) {

        int add = 1;
        for (int i = digits.length - 1; i >= 0; i--) {
            digits[i] += add;
            if (digits[i] > 9)
                digits[i] -= 10;
            else
                return digits;
        }
        int[] res = new int[digits.length + 1];
        res[0] = 1;
        return res;
    }

}