package algorithm.leetcode.math;

/**
 * https://leetcode-cn.com/problems/majority-element/
 * <p>
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于[n/2]的元素。
 * <p>
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 */
class LC169 {

    public int majorityElement(int[] nums) {

        int tag = nums[0];
        int n = 1;

        // 摩尔投票法
        for (int i = 1; i < nums.length; i++) {
            // 以当前出现最多的元素为基准, 新元素与其相同就+1，不同就-1
            if (tag == nums[i]) {
                n++;
            } else {
                n--;
            }
            if (n == 0) {
                tag = nums[i];
                n = 1;
            }
        }
        return tag;
    }

}