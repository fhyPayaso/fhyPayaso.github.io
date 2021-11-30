/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (79.04%)
 * Likes:    845
 * Dislikes: 0
 * Total Accepted:    162.5K
 * Total Submissions: 205.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠[3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;

    void dfs(vector<int> &nums, vector<int> cur, vector<bool> flag, int len)
    {
        if (cur.size() == len)
        {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (flag[i])
            {
                flag[i] = false;
                cur.push_back(nums[i]);
                dfs(nums, cur, flag ,len);
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {

        
        // 长度从1~len
        for (int i = 0; i <= nums.size(); i++)
        {
            vector<int> vec;
            vector<bool> flag(nums.size(), true);
            dfs(nums, vec, flag, i);
        }
        return res;
    }
};
// @lc code=end
