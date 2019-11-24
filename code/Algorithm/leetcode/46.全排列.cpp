/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (72.41%)
 * Likes:    444
 * Dislikes: 0
 * Total Accepted:    58.3K
 * Total Submissions: 80.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;

    void dfs(vector<int> &nums,
             vector<int> temp,
             int flag[])
    {
        if (nums.size() == temp.size())
        {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (flag[i] == 0)
            {
                temp.push_back(nums[i]);
                flag[i] = 1;
                dfs(nums, temp, flag);
                temp.pop_back();
                flag[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        int flag[10000] = {0};
        vector<int> temp;
        dfs(nums, temp, flag);
        return res;
    }
};
// @lc code=end

