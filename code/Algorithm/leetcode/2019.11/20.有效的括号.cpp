/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (39.95%)
 * Likes:    1166
 * Dislikes: 0
 * Total Accepted:    150.4K
 * Total Submissions: 376.1K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start
#include <stack>
using namespace std;
class Solution
{
public:
    bool jud(char a, char b)
    {
        if (a == '{' && b == '}')
            return true;
        else if (a == '(' && b == ')')
            return true;
        else if (a == '[' && b == ']')
            return true;
        return false;
    }

    bool isValid(string s)
    {

        stack<char> temp;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (!temp.empty())
            {
                char nc = temp.top();
                if (jud(nc, c))
                    temp.pop();
                else
                    temp.push(c);
            }
            else
            {
                temp.push(c);
            }
                }
        return temp.empty();
    }
};
// @lc code=end
