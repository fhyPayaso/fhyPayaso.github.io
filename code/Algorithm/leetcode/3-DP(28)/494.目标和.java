/*
 * @lc app=leetcode.cn id=494 lang=java
 *
 * [494] 目标和
 *
 * https://leetcode-cn.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (45.45%)
 * Likes:    650
 * Dislikes: 0
 * Total Accepted:    79.8K
 * Total Submissions: 175.6K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或
 * -中选择一个符号添加在前面。
 * 
 * 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：nums: [1, 1, 1, 1, 1], S: 3
 * 输出：5
 * 解释：
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * 一共有5种方法让最终目标和为3。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 数组非空，且长度不会超过 20 。
 * 初始的数组的和不会超过 1000 。
 * 保证返回的最终结果能被 32 位整数存下。
 * 
 * 
 */

// @lc code=start
class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int sum = 0;
        for(int n : nums)
            sum+=n;

        if(sum < target || (target+sum)%2==1)
            return 0;

        int w = (target+sum)/2;
        int[] dp = new int[w+1];
        for(int i = 0;i<w+1;i++)
            dp[i]=0;
        dp[0]=1;

        for(int num : nums)
        {
            for(int j = w ; j>=num;j--)
            {
                dp[j]+=dp[j-num];
            }
        }

        return dp[w];
    }
}
// @lc code=end

