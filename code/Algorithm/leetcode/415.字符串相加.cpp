/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (48.07%)
 * Likes:    248
 * Dislikes: 0
 * Total Accepted:    74K
 * Total Submissions: 142.8K
 * Testcase Example:  '"0"\n"0"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * num1 和num2 的长度都小于 5100
 * num1 和num2 都只包含数字 0-9
 * num1 和num2 都不包含任何前导零
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
 * 
 * 
 */

// @lc code=start
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {

        string len1, len2;
        if (num1.size() > num2.size())
        {
            len1 = num1;
            len2 = num2;
        }
        else
        {
            len1 = num2;
            len2 = num1;
        }

        int size1 = len1.size();
        int size2 = len2.size();

        int temp = 0;
        for (int i = 0; i < len1.size(); i++)
        {
            int res;
            int c1 = len1[size1 - i - 1] - '0';
            if (size2 - i - 1 >= 0)
            {
                int c2 = len2[size2 - i - 1] - '0';
                res = c1 + c2 + temp;
            }
            else
                res = c1 + temp;

            temp = 0;
            if (res >= 10)
            {
                res -= 10;
                temp = 1;
            }
            len1[size1 - i - 1] = char(res + '0');
        }

        string res = "";
        if (temp == 0)
        {
            res += len1;
        }
        else
        {

            res += "1";
            res += len1;
        }

        return res;
    }
};
// @lc code=end
