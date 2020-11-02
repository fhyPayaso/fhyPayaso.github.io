/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (55.50%)
 * Likes:    961
 * Dislikes: 0
 * Total Accepted:    185.7K
 * Total Submissions: 334.4K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> table;

    vector<string> res;

    void initTable()
    {
        table.push_back("0");
        table.push_back("1");
        table.push_back("abc");  //2
        table.push_back("def");  //3
        table.push_back("ghi");  //4
        table.push_back("jkl");  //5
        table.push_back("mno");  //6
        table.push_back("pqrs"); //7
        table.push_back("tuv");  //8
        table.push_back("wxyz"); //9
    }

    void dfs(string digits, string curStr)
    {
        if (digits.size() == curStr.size())
        {
            res.push_back(curStr);
            return;
        }
        int curLen = curStr.length();
        int index = int(digits[curLen] - '0');
        string temp = table[index];
        for (int i = 0; i < temp.size(); i++)
        {
            char c = temp[i];
            dfs(digits, curStr + c);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return res;

        initTable();
        dfs(digits, "");
        return res;
    }
};
// @lc code=end
