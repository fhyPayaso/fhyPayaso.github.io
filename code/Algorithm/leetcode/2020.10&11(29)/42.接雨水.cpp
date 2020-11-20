/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (52.66%)
 * Likes:    1788
 * Dislikes: 0
 * Total Accepted:    161.8K
 * Total Submissions: 305.4K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 0,1,0,2,1,0,1,3,2,1,2,1
 * 0 0 1 2 2 2 2 3 3 3 3 3
 * 3 3 3 3 3 3 3 3 2 2 1 0
 *     1   1 2 1     1  
 * 0 1  
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 0 
 * 0 
 * 
 * 
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int len = height.size();

        vector<int> left(len, 0), right(len, 0);

        for (int i = 1; i < len - 1; i++)
        {
            left[i] = max(height[i - 1], left[i - 1]);
            int j = len - 1 - i;
            right[j] = max(height[j + 1], right[j + 1]);
        }

        int res = 0;
        for (int i = 0; i < len; i++)
            res += max(0, min(left[i], right[i]) - height[i]);

        return res;
    }
};
// @lc code=end
