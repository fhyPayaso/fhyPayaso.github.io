/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (31.56%)
 * Likes:    2597
 * Dislikes: 0
 * Total Accepted:    353.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;
/*

经典DP

*/

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int manLen = 1;
        int len = s.size();
        for (int i = 0; i < len; i++)
        {

            int left, right;
            if (i % 2 == 1)
            {
            }
            else
            {
                /* code */
            }
        }
        // return maxLen;
    }
};
// @lc code=end
