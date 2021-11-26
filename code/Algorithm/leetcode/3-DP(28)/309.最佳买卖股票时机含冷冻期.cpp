/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (57.30%)
 * Likes:    661
 * Dislikes: 0
 * Total Accepted:    71.5K
 * Total Submissions: 124.5K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
 * 
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 * 
 * 
 * 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 * 
 * 
 * 示例:
 * 
 * 输入: [1,2,3,0,2]
 * 输出: 3 
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();

        if(prices.empty())
            return 0;


        vector<int> sell(len, 0); // 代表第i天的状态为卖出时的最佳收益
        vector<int> buy(len, 0);  // 代表到第i天为止，最后一次操作为买入时的最佳收益
        vector<int> cold(len, 0); // 代表到第i天为止，最后一次状态为冷冻的最佳收益

        buy[0] = -prices[0]; // 第一天只能买入，必然为负收益
        for (int i = 1; i < len; i++)
        {
            // 若当前的操作为卖出，则最佳收益为: 到昨天为止，最后一次操作为买入的最佳收益 + 今天卖出的价格
            sell[i] = buy[i - 1] + prices[i];

            // 若当前最后一次操作为买入, 为两种情况：
            // 1. 第i天买入了，损失了prices[i]，cold[i - 1]是保证当前有购买条件
            // 2. 最近一次操作为买入，第i天什么都没做
            buy[i] = max(cold[i - 1] - prices[i], buy[i - 1]);

            // 当前最近一次状态为冷冻期, 两种情况:
            // 1: i-1天卖出了，第i天处于冷冻
            // 2: 最近一次状态为冷冻期, 并且第i天什么都没做
            cold[i] = max(sell[i - 1], cold[i - 1]);
        }

        // 无论如何，最后一天手里都不应该有股票
        return max(sell.back(), cold.back());
    }
};
// @lc code=end
