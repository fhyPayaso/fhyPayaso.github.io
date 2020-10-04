/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        vector<int> res;
        res.push_back(nums[0]);
        if (len == 1)
            return res[0];
        else if(len == 2)
            return max(nums[0],nums[1]);
        res.push_back(max(nums[0],nums[1]));

        for (int i = 2; i < len; i++)
        {
            int cur = max(res[i - 2] + nums[i], res[i - 1]);
            res.push_back(cur);
        }

        return res[len - 1];
    }
};
// @lc code=end
