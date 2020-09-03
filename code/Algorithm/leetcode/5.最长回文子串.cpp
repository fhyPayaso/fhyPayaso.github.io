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
    string findCurStr(int left, int right, string s)
    {
        int len = s.size();
        int maxlen = 1;
        int start = left;
        while (left >= 0 && right < len)
        {
            if (s[left] == s[right])
            {
                int l = right - left + 1;
                if (l > maxlen)
                {
                    maxlen = l;
                    start = left;
                }
                left--;
                right++;
            }
            else
                break;
        }
        return s.substr(start, maxlen);
    }

    string longestPalindrome(string s)
    {
        int len = s.size();
        string res = "";
        for (int i = 0; i < len; i++)
        {
            string str1 = findCurStr(i, i, s);
            string str2 = findCurStr(i, i + 1, s);
            string str = str1.size() >= str2.size() ? str1 : str2;
            if (str.size() > res.size())
                res = str;
        }
        return res;
    }
};
// @lc code=end

// ********暴力解法 遍历所有子串 O(n3)******//

// string longestPalindrome(string s)
// {
//     int len = s.size();
//     string res = "";
//     for (int i = 0; i < len; i++)
//     {
//         for (int j = i; j < len; j++)
//         {
//             int left = i;
//             int right = j;
//             while (left <= right)
//             {
//                 if (s[left] == s[right])
//                 {
//                     left++;
//                     right--;
//                 }
//                 else
//                     break;
//             }
//             if (left > right)
//             {
//                 int newlen = j - i + 1;
//                 if (newlen > res.size())
//                     res = s.substr(i, newlen);
//             }
//         }
//     }
//     return res;
// }

// ******** 中项展开  O(n3)******//

/*

中项展开时要注意, 不是判断当前下标是否为奇偶

而是当前下标可能是奇数回文串中项, 也可能是是偶数回文数中项

*/

// string findCurStr(int left, int right, string s)
// {
//     int len = s.size();
//     int maxlen = 1;
//     int start = left;
//     while (left >= 0 && right < len)
//     {
//         if (s[left] == s[right])
//         {
//             int l = right - left + 1;
//             if (l > maxlen)
//             {
//                 maxlen = l;
//                 start = left;
//             }
//             left--;
//             right++;
//         }
//         else
//             break;
//     }
//     return s.substr(start, maxlen);
// }

// string longestPalindrome(string s)
// {
//     int len = s.size();
//     string res = "";
//     for (int i = 0; i < len; i++)
//     {
//         string str1 = findCurStr(i, i, s);
//         string str2 = findCurStr(i, i + 1, s);
//         string str = str1.size() >= str2.size() ? str1 : str2;
//         if (str.size() > res.size())
//             res = str;
//     }
//     return res;
// }