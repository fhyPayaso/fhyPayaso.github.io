/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 *
 * https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Medium (35.27%)
 * Likes:    445
 * Dislikes: 0
 * Total Accepted:    43.3K
 * Total Submissions: 122.7K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * 给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
 * 
 * 你找到的子数组应是最短的，请输出它的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [2, 6, 4, 8, 10, 9, 15]
 * 输出: 5
 * 解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
 * 
 * 
 * 说明 :
 * 
 * 
 * 输入的数组长度范围在 [1, 10,000]。
 * 输入的数组可能包含重复元素 ，所以升序的意思是<=。
 * 
 * 
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int left, right;
        for (int i = 0; i < nums.size(); i++)
        {
            if (temp[i] != nums[i])
            {
                left = i;
                break;
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (temp[i] != nums[i])
            {
                right = i;
                break;
            }
        }
        return max(right - left + 1, 0);
    }
};
// @lc code=end
