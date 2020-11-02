/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (67.54%)
 * Likes:    701
 * Dislikes: 0
 * Total Accepted:    153.8K
 * Total Submissions: 227.5K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],   145
 * ⁠ [1,5,1],  276
 * ⁠ [4,2,1]   687
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */

#include <vector>
#include <cmath>

using namespace std;

// 125
// 321

// @lc code=start
class Solution
{
public:
    

    int minPathSum(vector<vector<int>> &grid)
    {
        int h = grid.size();
        int w = grid[0].size();

        for (int i = 1; i < h; i++)
            grid[i][0] += grid[i - 1][0];

        for (int i = 1; i < w; i++)
            grid[0][i] += grid[0][i - 1];

        for (int i = 1; i < h; i++)
        {
            for (int j = 1; j < w; j++)
            {
                grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[h-1][w-1];
    }
};
// @lc code=end
