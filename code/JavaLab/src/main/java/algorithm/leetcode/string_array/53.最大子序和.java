package algorithm.leetcode.string_array;

/**
 * https://leetcode-cn.com/problems/maximum-subarray/
 * <p>
 * 最大和的连续子数组和
 */
class LC53 {

    public int maxSubArray(int[] nums) {

        if (nums.length == 0) {
            return 0;
        }


        int res = Integer.MIN_VALUE;
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {

            sum += nums[i];

            res = Math.max(sum, res);

            if (sum < 0) {
                sum = 0;
            }
        }

        return res;
    }
}