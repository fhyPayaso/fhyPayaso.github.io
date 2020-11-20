/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (69.07%)
 * Likes:    812
 * Dislikes: 0
 * Total Accepted:    85.7K
 * Total Submissions: 124K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 */

// catalan公式 记住就好

// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            int curSum = 0;
            for (int j = 0; j < i; j++)
                curSum += dp[j] * dp[i - j - 1];
            dp[i] = curSum;
        }

        return dp[n];
    }
};
// @lc code=end
