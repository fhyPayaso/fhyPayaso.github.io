/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (41.40%)
 * Likes:    902
 * Dislikes: 0
 * Total Accepted:    149.9K
 * Total Submissions: 358.7K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给定不同面额的硬币 coins 和一个总金额
 * amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 
 * 你可以认为每种硬币的数量是无限的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3 
 * 解释：11 = 5 + 5 + 1
 * 
 * 示例 2：
 * 
 * 
 * 输入：coins = [2], amount = 3
 * 输出：-1
 * 
 * 示例 3：
 * 
 * 
 * 输入：coins = [1], amount = 0
 * 输出：0
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：coins = [1], amount = 1
 * 输出：1
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：coins = [1], amount = 2
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 0 
 * 
 * 
 */

#include <vector>
#include <cmath>
using namespace std;


// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int INT = 999999;
        // 1 2 5 11
        int dp[amount + 1];
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            dp[i] = INT;
            for (int j = 0; j < coins.size(); j++)
            {
                if(i>=coins[j])
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }

        if(dp[amount]!= INT)
            return dp[amount];
        
        return -1;
    }
};
// @lc code=end
