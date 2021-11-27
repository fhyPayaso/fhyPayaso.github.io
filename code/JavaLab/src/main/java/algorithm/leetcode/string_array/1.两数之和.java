package algorithm.leetcode.string_array;

import java.util.HashMap;

/**
 * https://leetcode-cn.com/problems/two-sum/
 */
class LC01 {

    public int[] twoSum(int[] nums, int target) {

        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int n = nums[i];
            if (map.get(target - n) != null) {
                return new int[]{i, map.get(target - n)};
            }
            map.put(n, i);
        }
        return null;
    }
}