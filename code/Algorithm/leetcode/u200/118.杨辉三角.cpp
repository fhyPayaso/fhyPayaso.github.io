/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (67.15%)
 * Likes:    342
 * Dislikes: 0
 * Total Accepted:    102.4K
 * Total Submissions: 152.3K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> rowVec;
            if (i == 0)
                rowVec.push_back(1);
            else
            {
                   rowVec.push_back(1);
                int length = i + 1;
                for (int j = 1; j < length - 1; j++)
                {
                    int curVal = res[i - 1][j] + res[i - 1][j - 1];
                    rowVec.push_back(curVal);
                }
                rowVec.push_back(1);
            }

            res.push_back(rowVec);
        }
        return res;
    }
};
// @lc code=end
