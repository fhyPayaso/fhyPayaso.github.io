/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (29.57%)
 * Likes:    2700
 * Dislikes: 0
 * Total Accepted:    350.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;

    void dfs(vector<int> &nums, vector<int> cur)
    {
        if (cur.size() == 3)
        {
            if (cur[0] + cur[1] + cur[2] == 0)
                res.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            cur.push_back(nums[i]);
            dfs(nums, cur);
            cur.pop_back();
        }
        
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<int> cur;
        dfs(nums, cur);
        return res;
    }
};
// @lc code=end
