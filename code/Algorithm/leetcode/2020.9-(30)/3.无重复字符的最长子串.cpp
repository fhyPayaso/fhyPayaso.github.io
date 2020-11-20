/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (31.85%)
 * Likes:    3997
 * Dislikes: 0
 * Total Accepted:    574K
 * Total Submissions: 1.6M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> m(256, -1);
        int res = 0, left = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            left = max(left, m[c]);
            m[c] = i;
            res = max(res, i - left);
        }
        return res;
    }
};
// @lc code=end
