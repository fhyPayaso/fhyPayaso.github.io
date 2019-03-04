/*
 * @lc app=leetcode.cn id=167 lang=java
 *
 * [167] 两数之和 II - 输入有序数组
 *
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (47.18%)
 * Total Accepted:    16.5K
 * Total Submissions: 34.9K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
 * 
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 * 
 * 说明:
 * 
 * 
 * 返回的下标值（index1 和 index2）不是从零开始的。
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 * 
 * 
 * 示例:
 * 
 * 输入: numbers = [2, 7, 11, 15], target = 9
 * 输出: [1,2]
 * 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 * 
 */
class Solution {

    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        // 数组已经排好序，左指针指小值，右指针指大值
        int i = 0, j = nums.length - 1;
        while (i < j) {
            // 获取当前数的和，与目标比较
            int sum = nums[i] + nums[j];
            if (sum == target) {
                res[0] = i + 1;
                res[1] = j + 1;
                break;
            } else if (sum > target) {
                j--; // 当前值大则大数减小
            } else {
                i++; // 当前值小则小数增大
            }
        }
        return res;
    }
}

