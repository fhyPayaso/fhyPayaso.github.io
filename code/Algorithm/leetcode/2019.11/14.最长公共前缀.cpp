/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.15%)
 * Likes:    750
 * Dislikes: 0
 * Total Accepted:    142.3K
 * Total Submissions: 404.6K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res = "";

        int index = 0;
        bool jump = false;

        if(strs.size() == 0)
            return res;

        while (true)
        {
            char flag;
            for (int i = 0; i < strs.size(); i++)
            {
                string a = strs[i];
                if (index < a.size())
                {
                    if (i == 0)
                        flag = a.at(index);
                    else
                    {
                        if (flag != a.at(index))
                        {
                            jump = true;
                            break;
                        }
                    }
                }
                else
                {
                    jump = true;
                    break;
                }
                
            }
            if (jump)
                break;
            res += flag;
            index++;
        }

        return res;
    }
};
// @lc code=end
