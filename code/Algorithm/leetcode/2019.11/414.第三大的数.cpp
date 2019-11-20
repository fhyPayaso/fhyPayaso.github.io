/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 *
 * https://leetcode-cn.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (33.08%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    13.8K
 * Total Submissions: 41.7K
 * Testcase Example:  '[3,2,1]'
 *
 * 给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3, 2, 1]
 * 
 * 输出: 1
 * 
 * 解释: 第三大的数是 1.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1, 2]
 * 
 * 输出: 2
 * 
 * 解释: 第三大的数不存在, 所以返回最大的数 2 .
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: [2, 2, 3, 1]
 * 
 * 输出: 1
 * 
 * 解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
 * 存在两个值为2的数，它们都排第二。
 * 
 * 
 */

// @lc code=start
long long minn = -2147483648 - 1;
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {

        int t = nums[0];
        long long n1 = t, n2 = minn, n3 = minn;
        for (int i = 1; i < nums.size(); i++)
        {
            int n = nums[i];
            if (n > n1)
            {
                n3 = n2;
                n2 = n1;
                n1 = n;
            }
            else if (n < n1 && n > n2)
            {
                n3 = n2;
                n2 = n;
            }
            else if (n < n2 && n > n3)
            {
                n3 = n;
            }
        }

        return n3 == minn ? n1 : n3;
    }
};
// @lc code=end
