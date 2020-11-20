/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (54.40%)
 * Likes:    464
 * Dislikes: 0
 * Total Accepted:    123.3K
 * Total Submissions: 226.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 * 
 * 输入为 非空 字符串且只包含数字 1 和 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string len1, len2;
        if (a.length() >= b.length())
        {
            len1 = a;
            len2 = b;
        }
        else
        {
            len1 = b;
            len2 = a;
        }

        int flag = 0;
        for (int i = 0; i < len1.length(); i++)
        {
            int index1 = len1.length() - i - 1;
            int index2 = len2.length() - i - 1;

            int c1 = len1[index1] - '0';
            int c2 = 0;
            if (index2 >= 0)
                c2 = len2[index2] - '0';

            int temp = c1 + c2 + flag;
            if (temp >= 2)
            {
                temp -= 2;
                flag = 1;
            }
            else
                flag = 0;

            len1[index1] = char(temp + '0');
        }

        string res;
        if (flag == 1)
            res = '1' + len1;
        else
            res = len1;

        return res;
    }
};
// @lc code=end
