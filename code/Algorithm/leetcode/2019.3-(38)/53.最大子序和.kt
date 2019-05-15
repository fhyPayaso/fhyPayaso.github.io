import kotlin.math.max
/*
 * @lc app=leetcode.cn id=53 lang=kotlin
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (42.74%)
 * Total Accepted:    42K
 * Total Submissions: 97.2K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */
class Solution {


fun maxSubArray(nums: IntArray): Int {

    if (nums.size == 1) return nums[0]
    var res = 0
    var max = nums[0]
    for (i in 0 until nums.size) {
        // 累加并维护最大值
        res += nums[i]
        max = max(max, res)
        // 下限为0(不选)
        if (res <= 0) res = 0
    }
    return max
}
}

