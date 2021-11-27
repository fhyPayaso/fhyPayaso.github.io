package algorithm.leetcode.string_array;

import java.util.Arrays;

/**
 * https://leetcode-cn.com/problems/next-permutation/
 * <p>
 * 获取大于当前排列的下一个排列
 */
class LC31 {

    public void nextPermutation(int[] nums) {

        int i = nums.length - 1;

        // 最大情况下是降序排列, 直接重新变成升序即最小
        while (i > 0 && nums[i - 1] >= nums[i])
            i--;
        if (i == 0) {
            Arrays.sort(nums);
            return;
        }

        int j = nums.length - 1;

        // 找到第一个比升序前一个数大的值, 交换后重新排序即可
        while (j > i && nums[i - 1] >= nums[j])
            j--;

        int temp = nums[i - 1];
        nums[i - 1] = nums[j];
        nums[j] = temp;

        Arrays.sort(nums, i, nums.length);
    }
}