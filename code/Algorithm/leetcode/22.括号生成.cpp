/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (76.27%)
 * Likes:    1372
 * Dislikes: 0
 * Total Accepted:    189.9K
 * Total Submissions: 248.6K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：n = 3
 * 输出：[
 * ⁠      "((()))", 012
 * ⁠      "(()())", 013
 * ⁠      "(())()", 014
 * ⁠      "()(())", 023 
 * ⁠      "()()()"  024
 * ⁠    ]
 * 
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:

    vector<string> vec;

    void dfs(string str, int leftNum, int rightNum, int n)
    {

        // 构建过程中,若右括号多 则必然会存在无法被后续匹配的右括号
        if (leftNum > n || rightNum > n || rightNum > leftNum)
            return;

        if (str.size() == 2 * n)
        {
            if (leftNum == rightNum)
                vec.push_back(str);
            return;
        }
        dfs(str + "(", leftNum + 1, rightNum, n);
        dfs(str + ")", leftNum, rightNum + 1, n);
    }

    vector<string> generateParenthesis(int n)
    {

        
        dfs("", 0, 0, n);

        return vec;
    }
};
// @lc code=end
