/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (66.25%)
 * Likes:    266
 * Dislikes: 0
 * Total Accepted:    18.9K
 * Total Submissions: 28.4K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<vector<string>> allRes;

    vector<string> getEmptyMap(int n)
    {
        vector<string> res;
        for (int i = 0; i < n; i++)
        {
            string str = "";
            for (int j = 0; j < n; j++)
                str += '.';
            res.push_back(str);
        }
        return res;
    }

    void dfs(int n, int step, vector<string> map)
    {
        if (step == n)
        {
            allRes.push_back(map);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            bool jd = true;

            for (int j = 0; j < step; j++)
            {
                int diff = step - j;
                if (map[j][i] == 'Q' 
                    || (i + diff < n && map[j][i + diff] == 'Q') 
                    || (i - diff >= 0 && map[j][i - diff] == 'Q'))
                {
                    jd = false;
                    break;
                }
            }

            if (jd)
            {

                map[step][i] = 'Q';
                dfs(n, step + 1, map);
                map[step][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {

        vector<string> map = getEmptyMap(n);
        dfs(n, 0, map);
        return allRes;
    }
};
// @lc code=end
