/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (45.75%)
 * Likes:    1203
 * Dislikes: 0
 * Total Accepted:    176.7K
 * Total Submissions: 386.1K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 * 
 * 示例:
 * 
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4 
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 * 
 * 说明:
 * 
 * 
 * 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 * 你算法的时间复杂度应该为 O(n^2) 。
 * 
 * 
 * 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 * 
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int l = nums.size();

        if (l == 1)
            return 1;

        vector<int> dp(l, 0);
        dp[0] = 1;

        for (int i = 1; i < l; i++)
        {
            int maxv = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] < nums[i])
                    maxv = max(dp[j], maxv);
            }
            dp[i] = maxv + 1;
        }

        int res = dp[0];
        for (int i = 1; i < l; i++)
            res = max(dp[i], res);

        return res;
    }
};
// @lc code=end
