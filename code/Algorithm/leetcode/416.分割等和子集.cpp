/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (49.00%)
 * Likes:    616
 * Dislikes: 0
 * Total Accepted:    89.8K
 * Total Submissions: 183.3K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 注意:
 * 
 * 
 * 每个数组中的元素不会超过 100
 * 数组的大小不会超过 200
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1, 5, 11, 5]
 * 
 * 输出: true
 * 
 * 解释: 数组可以分割成 [1, 5, 5] 和 [11].
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1, 2, 3, 5]
 * 
 * 输出: false
 * 
 * 解释: 数组不能分割成两个元素和相等的子集.
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto n : nums)
            sum += n;
        if (sum % 2 == 1)
            return false;

        sum /= 2;

        // 转化成动态规划问题nums中是否存在排列和为sum
        // 即转化成01背包问题
        int dp[sum + 1];
        for (int i = 0; i <= sum; i++)
            dp[i] = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            int num = nums[i - 1];
            for (int j = sum; j > 0; j--)
            {
                if (j < num)
                    continue;
                dp[j] = max(dp[j], dp[j - num] + num);
                if (j == sum && dp[j] == sum)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
