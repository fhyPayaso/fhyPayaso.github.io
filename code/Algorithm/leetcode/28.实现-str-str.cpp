/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.67%)
 * Likes:    535
 * Dislikes: 0
 * Total Accepted:    217.2K
 * Total Submissions: 547.3K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */

// @lc code=start
#include <string>
using namespace std;

/*

很经典的KMP算法，关键在于求出模式字符串对应的next数组

简单定义next数组即: 截止到上一个字符对应的子串, 该子串前缀后缀长度重合的最大长度

*/
class Solution
{
public:
    // kmp算法求next数组
    void getNextArray(string p, int next[])
    {
        int size = p.size();
        next[0] = -1;
        int k = -1;
        int j = 0;
        while (j < size - 1)
        {
            if (k == -1 || p[j] == p[k])
            {
                j++;
                k++;
                next[j] = k;
            }
            else
            {
                k = next[k];
            }
        }
    }

    int strStr(string haystack, string needle)
    {

        if (needle.size() == 0)
            return 0;

        if (needle.size() > haystack.size())
            return -1;

        int len1 = haystack.size();
        int len2 = needle.size();
        int nextList[len2];

        getNextArray(needle, nextList);
        int i = 0, j = 0;
        while (i < len1 && j < len2)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                // 如果当前字符不匹配,则i保持不动, j退回到上一个可能存在前后缀相同的位置
                // 即next数组对应的值
                j = nextList[j];
            }
        }
        if (j == len2)
            return i - j;
        else
            return -1;
    }
};
// @lc code=end
