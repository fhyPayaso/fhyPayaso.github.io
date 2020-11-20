/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 *
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (45.07%)
 * Likes:    644
 * Dislikes: 0
 * Total Accepted:    74.2K
 * Total Submissions: 164.4K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
 * 
 * 示例 1 :
 * 
 * 
 * 输入:nums = [1,1,1], k = 2
 * 输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
 * 
 * 
 * 说明 :
 * 
 * 
 * 数组的长度为 [1, 20,000]。
 * 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
 * 
 * 
 */

#include <vector>
#include <map>
using namespace std;

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {

        int preSum = 0;
        map<int, int> M;
        M[0] = 1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // 维护一个前缀和(不一定递增)
            preSum += nums[i];
            // 如果存在前缀符合距离为k(因为存在负数,所以可能出现多次)
            if(M.find(preSum - k) != M.end())
                count += M[preSum - k];
            M[preSum]++;
        }
        return count;
    }
};
// @lc code=end
