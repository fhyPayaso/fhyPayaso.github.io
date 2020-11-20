/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (58.24%)
 * Likes:    663
 * Dislikes: 0
 * Total Accepted:    95.2K
 * Total Submissions: 163.3K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */

#include <cmath>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int minRes = 4;

    void dfs(int num, vector<int> POW2, int count)
    {
        if (num < 0)
            return;

        if (num == 0)
        {
            minRes = min(minRes, count);
            return;
        }

        if (count >= minRes)
            return;

        int len = POW2.size();
        for (int i = len - 1; i > 0; i--)
            dfs(num - POW2[i], POW2, count + 1);
        
    }

    int numSquares(int n)
    {
        int tableSize = sqrt(n);
        vector<int> POW2;

        for (int i = 0; i <= tableSize; i++)
            POW2.push_back(i * i);

        dfs(n, POW2, 0);

        return minRes;
    }
};
// @lc code=end
