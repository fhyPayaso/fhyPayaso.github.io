import kotlin.math.sqrt
/*
 * @lc app=leetcode.cn id=633 lang=kotlin
 *
 * [633] 平方数之和
 *
 * https://leetcode-cn.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Easy (29.50%)
 * Total Accepted:    4.1K
 * Total Submissions: 13.7K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c。
 * 
 * 示例1:
 * 
 * 
 * 输入: 5
 * 输出: True
 * 解释: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 
 * 
 * 示例2:
 * 
 * 
 * 输入: 3
 * 输出: False
 * 
 * 
 */
class Solution {
    fun judgeSquareSum(c: Int): Boolean {
        val l = sqrt(c * 1.0).toInt()
        for (i in 0..l) {
            for (j in i..l) {
                if (i * i + j * j == c) {
                    return true
                }
            }
        }
        return false
    }
}

