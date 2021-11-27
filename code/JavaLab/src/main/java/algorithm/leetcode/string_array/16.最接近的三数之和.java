package algorithm.leetcode.string_array;

import java.util.Arrays;

/**
 * https://leetcode-cn.com/problems/3sum-closest/
 */
class LC16 {

    public int threeSumClosest(int[] nums, int target) {


        Arrays.sort(nums);

        int minDiff = Integer.MAX_VALUE;
        int res = 0;

        for (int i = 0; i < nums.length; i++) {


            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int l = i + 1;
            int r = nums.length - 1;


            while (l < r) {

                int sum = nums[i] + nums[l] + nums[r];
                int diff = Math.abs(target - sum);

                if (res == 0 || diff < minDiff) {
                    minDiff = diff;
                    res = sum;
                }

                if (sum == target) {
                    return 0;
                } else if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }


        }

        return res;
    }
}