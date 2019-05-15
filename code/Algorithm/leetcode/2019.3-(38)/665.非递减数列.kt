/*
 * @lc app=leetcode.cn id=665 lang=kotlin
 *
 * [665] 非递减数列
 *
 * https://leetcode-cn.com/problems/non-decreasing-array/description/
 *
 * algorithms
 * Easy (18.68%)
 * Total Accepted:    4.2K
 * Total Submissions: 22.1K
 * Testcase Example:  '[4,2,3]'
 *
 * 给定一个长度为 n 的整数数组，你的任务是判断在最多改变 1 个元素的情况下，该数组能否变成一个非递减数列。
 * 
 * 我们是这样定义一个非递减数列的： 对于数组中所有的 i (1 <= i < n)，满足 array[i] <= array[i + 1]。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [4,2,3]
 * 输出: True
 * 解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [4,2,1]
 * 输出: False
 * 解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
 * 
 * 
 * 说明:  n 的范围为 [1, 10,000]。
 * 
 */
class Solution {
    
    fun checkPossibility(nums: IntArray): Boolean {

        if (nums.size <= 1) return true
        var res = 0

        for (i in 1 until nums.size) {
            if (nums[i - 1] <= nums[i]) continue
            res++ // 每需要修改一次加一
            if (res == 2) return false
            // 保证i之前都是非递减，此时num[i]比前一个数小
            // 可以将num[i]变大，也可以将前一个数变小，但是num[i]变大会影响后面的判断，所以一般将前一个数变小
            // 但是若num[i]<num[i-2],前一个数改小后依然不满足，只能将num[i]变大
            if (i >= 2 && nums[i - 2] > nums[i])
                nums[i] = nums[i - 1]
            else
                nums[i - 1] = nums[i]
        }
        return res <= 1
    }
}


