/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (38.60%)
 * Likes:    3092
 * Dislikes: 0
 * Total Accepted:    245.2K
 * Total Submissions: 634.8K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
 * 
 * 请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        
    }
};
// @lc code=end

/*

简单做法, 直接合并成一个数组, 直接返回中位数即可
复杂度O(n)， 可AC

*/
// double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
// {
//     vector<int> nums;
//     int i = 0, j = 0;
//     while (i < nums1.size() || j < nums2.size())
//     {
//         if (i < nums1.size() && j < nums2.size())
//         {
//             if (nums1[i] <= nums2[j])
//             {
//                 nums.push_back(nums1[i]);
//                 i++;
//             }
//             else
//             {
//                 nums.push_back(nums2[j]);
//                 j++;
//             }
//         }
//         else if (i < nums1.size())
//         {
//             nums.push_back(nums1[i]);
//             i++;
//         }
//         else if (j < nums2.size())
//         {
//             nums.push_back(nums2[j]);
//             j++;
//         }
//     }
//     int len = nums.size();
//     int middle = len / 2;
//     if (len % 2 == 1)
//         return nums[middle];
//     else
//     {
//         if (len == 0)
//             return nums[0];
//         return (nums[middle] + nums[middle - 1]) / 2.0;
//     }
// }