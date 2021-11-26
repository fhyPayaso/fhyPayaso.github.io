/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 *
 * https://leetcode-cn.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (65.91%)
 * Likes:    918
 * Dislikes: 0
 * Total Accepted:    102.7K
 * Total Submissions: 155.8K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和
 * n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,4,2,2]
 *       0 1 2 3 4
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,1,3,4,2]
 * 输出: 3
 * 
 * 
 * 说明：
 * 
 * 
 * 不能更改原数组（假设数组是只读的）。
 * 只能使用额外的 O(1) 的空间。
 * 时间复杂度小于 O(n^2) 。
 * 数组中只有一个重复的数字，但它可能不止重复出现一次。
 * 
 * 
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // 相当于环形链表2，寻找环形链表入口
        int s1 = 0, s2 = 0;
        do
        {
            // 慢指针走1步
            s1 = nums[s1];
            // 快指针走2步
            s2 = nums[s2];
            s2 = nums[s2];

        } while (s1 != s2);
        s1 = 0;
        while (s1 != s2)
        {
            s1 = nums[s1];
            s2 = nums[s2];
        }
        return s1;
    }
};
// @lc code=end
