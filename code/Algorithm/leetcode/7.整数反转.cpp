/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (33.18%)
 * Likes:    1425
 * Dislikes: 0
 * Total Accepted:    212.6K
 * Total Submissions: 640.7K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */

// @lc code=start
#include <string>
#include <cmath>

unsigned int p31 = 01 << 31;

class Solution
{
public:
    // 这题要改函数参数类型为long
    int reverse(long x)
    {
        long long arr[40];
        int len = 0;
        long long res = 0;
        long long temp = abs(x);
        while (temp != 0)
        {
            arr[++len] = temp % 10;
            temp /= 10;
        }
        long long base = 1;
        for (int i = len; i >= 1; i--)
        {
            res += base * arr[i];
            base *= 10;
        }

        if (x >= 0 && res <= p31 - 1)
            return res;
        else if (x < 0 && res <= p31)
            return res * -1;
        else
            return 0;
    }
};
// @lc code=end
