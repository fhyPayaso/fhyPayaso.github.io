/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (55.15%)
 * Likes:    182
 * Dislikes: 0
 * Total Accepted:    28.8K
 * Total Submissions: 51.9K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;

    void dfs(vector<int> &nums,
             vector<int> temp,
             bool flag[])
    {
        if (nums.size() == temp.size())
        {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            // 如果之前的数组当中已经存在与当前数相同的数
            if (i > 0 && (nums[i] == nums[i - 1]) && flag[i - 1])
                continue;
            if (!flag[i])
            {
                temp.push_back(nums[i]);
                flag[i] = true;
                dfs(nums, temp, flag);
                temp.pop_back();
                flag[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        bool flag[10000] = {false};
        vector<int> temp;
        dfs(nums, temp, flag);
        return res;
    }
};
// @lc code=end
