/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 *
 * https://leetcode-cn.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (39.54%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    21K
 * Total Submissions: 53.1K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，返回 n! 结果尾数中零的数量。
 * 
 * 示例 1:
 * 
 * 输入: 3
 * 输出: 0
 * 解释: 3! = 6, 尾数中没有零。
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: 1
 * 解释: 5! = 120, 尾数中有 1 个零.
 * 
 * 说明: 你算法的时间复杂度应为 O(log n) 。
 * 
 */

// @lc code=start
// zz了一直当nlogn写
class Solution
{
public:
    int trailingZeroes(int n)
    {

        int res = 0;
        while (n)
        {
            n /= 5;
            res += n;
        }
        return res;
    }
};
// @lc code=end
