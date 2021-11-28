package algorithm.leetcode.math;

import java.util.Arrays;

/**
 * https://leetcode-cn.com/problems/maximum-product-of-three-numbers/
 * <p>
 * 求数组中最大乘积的三个数
 */
class LC628 {

    /**
     * 三个数相乘三种情况
     * 1. 三个数都是正数 -> 正数 选三个最大的
     * 2. 两个负数一个正数 -> 正数 两个负数选最小的, 正数选最大的
     * 3. 三个数都是负数 -> 负数 , 同样选三个最大的(绝对值最小)
     * 4. 两个正数一个负数 -> 负数, 只可能前两个为正数, 第三个为负数
     */
    public int maximumProduct(int[] nums) {


        Arrays.sort(nums);
        int len = nums.length;

        // 1. 默认情况包括1,3,4
        int res = nums[len - 1] * nums[len - 2] * nums[len - 3];
        if (len == 3) {
            return res;
        }

        // 第二种情况
        if (nums[0] <= 0 && nums[1] <= 0 && nums[len - 1] >= 0) {
            int curRes = nums[0] * nums[1] * nums[len - 1];
            res = Math.max(curRes, res);
        }
        return res;
    }
}