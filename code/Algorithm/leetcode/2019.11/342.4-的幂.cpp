/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 *
 * https://leetcode-cn.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (46.74%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    15.1K
 * Total Submissions: 32.1K
 * Testcase Example:  '16'
 *
 * 给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 16
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: false
 * 
 * 进阶：
 * 你能不使用循环或者递归来完成本题吗？
 * 
 */

// @lc code=start
#include <cmath>
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        // 若为4的次方,则log前系数必然能化为整数
        double diff = log10(num) / log10(4);
        return (diff - int(diff)) == 0;
    }
};
// @lc code=end
