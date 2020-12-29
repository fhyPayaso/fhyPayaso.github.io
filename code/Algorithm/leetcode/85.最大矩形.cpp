/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (48.71%)
 * Likes:    670
 * Dislikes: 0
 * Total Accepted:    48.4K
 * Total Submissions: 99.3K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：6
 * 解释：最大矩形如上图所示。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = []
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [["0"]]
 * 输出：0
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：matrix = [["1"]]
 * 输出：1
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：matrix = [["0","0"]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * rows == matrix.length
 * cols == matrix.length
 * 0 
 * matrix[i][j] 为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start

#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0)
            return 0;

        int h = matrix.size();
        int w = matrix[0].size();

        // 可以转化为柱状图中最大矩形来做
        // 对每一行以及上面部分都转化成一个柱状图
        int res = 0;
        vector<vector<int>> his(h + 1, vector<int>(w, 0));

        for (int i = 1; i <= h; i++)
        {
            vector<char> row = matrix[i - 1];
            for (int j = 0; j < w; j++)
                his[i][j] = row[j] == '1' ? his[i - 1][j] + 1 : 0;
        }

        stack<int> stk;
        for (int i = 1; i <= h; i++)
        {
            his[i].push_back(0);
            for (int j = 0; j < his[i].size(); j++)
            {
                while (!stk.empty() && his[i][stk.top()] > his[i][j])
                {
                    int index = stk.top();
                    stk.pop();
                    int w = stk.empty() ? j : (j - stk.top() - 1);
                    int s = w * his[i][index];
                    res = max(res, s);
                }
                stk.push(j);
            }
            while (!stk.empty())
                stk.pop();
        }

        return res;
    }
};
// @lc code=end
