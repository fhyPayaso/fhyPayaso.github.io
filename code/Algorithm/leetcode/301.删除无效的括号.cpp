/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 *
 * https://leetcode-cn.com/problems/remove-invalid-parentheses/description/
 *
 * algorithms
 * Hard (48.89%)
 * Likes:    330
 * Dislikes: 0
 * Total Accepted:    17.5K
 * Total Submissions: 35.7K
 * Testcase Example:  '"()())()"'
 *
 * 删除最小数量的无效括号，使得输入的字符串有效，返回所有可能的结果。
 * 
 * 说明: 输入可能包含了除 ( 和 ) 以外的字符。
 * 
 * 示例 1:
 * 
 * 输入: "()())()"
 * 输出: ["()()()", "(())()"]
 * 
 * 
 * 示例 2:
 * 
 * 输入: "(a)())()"
 * 输出: ["(a)()()", "(a())()"]
 * 
 * 
 * 示例 3:
 * 
 * 输入: ")("
 * 输出: [""]
 * 
 */

#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool judge(string s)
    {
        stack<char> stk;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                stk.push(s[i]);
            else if (s[i] == ')')
            {
                if (stk.empty())
                    return false;
                stk.pop();
            }
        }

        return stk.empty();
    }

    vector<string> removeInvalidParentheses(string s)
    {

        queue<string> que;
        unordered_set<string> vist;
        vector<string> res;

        que.push(s);

        while (!que.empty())
        {

            if (!res.empty())
                return res;

            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                string str = que.front();
                if (judge(str))
                    res.push_back(str);
                que.pop();
                for (int j = 0; j < str.size(); j++)
                {
                    if (str[j] != '(' && str[j] != ')')
                        continue;
                    string temp = str;
                    temp.erase(temp.begin() + j);
                    if(vist.count(temp) == 0)
                    {
                        vist.insert(temp);
                        que.push(temp);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
