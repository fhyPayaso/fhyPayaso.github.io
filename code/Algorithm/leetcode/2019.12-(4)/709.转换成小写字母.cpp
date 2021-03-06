/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 *
 * https://leetcode-cn.com/problems/to-lower-case/description/
 *
 * algorithms
 * Easy (74.78%)
 * Likes:    108
 * Dislikes: 0
 * Total Accepted:    36.5K
 * Total Submissions: 48.6K
 * Testcase Example:  '"Hello"'
 *
 * 实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: "Hello"
 * 输出: "hello"
 * 
 * 示例 2：
 * 
 * 
 * 输入: "here"
 * 输出: "here"
 * 
 * 示例 3：
 * 
 * 
 * 输入: "LOVELY"
 * 输出: "lovely"
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    string toLowerCase(string str)
    {
        string res = "";

        for (int i = 0; i < str.length(); i++)
        {
            char t = str[i];
            if (t >= 'A' && t <= 'Z')
                t = t + 32;
            res += t;
        }

        return res;
    }
};
// @lc code=end
