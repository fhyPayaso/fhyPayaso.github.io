package algorithm.leetcode.string_array;

/**
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 */
class LC209 {

    public int minSubArrayLen(int target, int[] nums) {

        if (nums.length == 0) {
            return 0;
        }

        int left = 0, right = 0;

        int res = Integer.MAX_VALUE;
        int num = nums[0];
        boolean flag = false;


        while (left <= right) {

            int width = right - left + 1;

            if (num == target) {
                // 如果和相等, 右指针向右移动
                flag = true;
                res = Math.min(res, width);
                right++;
                if (right >= nums.length) {
                    break;
                }
                num += nums[right];

            } else if (num > target) {
                // 如果和大于, 左指针向右移动
                flag = true;
                res = Math.min(res, width);
                num -= nums[left];
                left++;
            } else {
                // 如果和小于, 右指针向右移动
                right++;
                if (right >= nums.length) {
                    break;
                }
                num += nums[right];
            }

        }

        return flag ? res : 0;
    }
}