package algorithm.leetcode.string_array;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/3sum/
 */
class LC15 {

    public List<List<Integer>> threeSum(int[] nums) {

        List<List<Integer>> res = new ArrayList<>();

        // 小于3个无解
        if (nums.length < 3) {
            return res;
        }

        // 升序排序关键
        Arrays.sort(nums);

        for (int i = 0; i < nums.length; i++) {

            // 全为正数不可能为和为0
            if (nums[i] > 0) {
                return res;
            }

            // 防止重复
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }


            // 确定一个位置，再对剩余的数组双指针
            int l = i + 1;
            int r = nums.length - 1;

            while (l < r) {

                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {

                    // 可行解
                    List<Integer> three = new ArrayList<>();
                    three.add(nums[i]);
                    three.add(nums[l]);
                    three.add(nums[r]);
                    res.add(three);

                    // 去重
                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }

                    l++;
                    r--;

                } else if (sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }

        }

        return res;
    }
}