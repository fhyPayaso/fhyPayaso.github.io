/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (36.25%)
 * Likes:    1793
 * Dislikes: 0
 * Total Accepted:    115.1K
 * Total Submissions: 317.2K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
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
#include <cmath>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // 首先保证短数组在前面
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 > len2)
        {
            vector<int> tempVec = nums1;
            nums1 = nums2;
            nums2 = tempVec;

            int tempInt = len1;
            len1 = len2;
            len2 = tempInt;
        }

        int left = 0, right = len1;
        int mid = (len1 + len2 + 1) / 2;
        while (left <= right)
        {
            int i = (left + right) / 2;
            int j = mid - i;

            if (nums1[i - 1] > nums2[j])
            {
                right = j;
            }
            else if (nums2[j - 1] > nums1[i])
            {
                left = i;
            }
            else
            {
                int l = max(nums1[i - 1], nums2[j - 1]);
                int r = min(nums1[i], nums2[j]);
                return (l + r) / 2.0;
            }
        }
    }
};
// @lc code=end
