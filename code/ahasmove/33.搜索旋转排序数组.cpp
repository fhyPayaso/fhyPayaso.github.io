/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (39.04%)
 * Likes:    1041
 * Dislikes: 0
 * Total Accepted:    185.6K
 * Total Submissions: 471.7K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 给你一个升序排列的整数数组 nums ，和一个整数 target 。
 * 
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。（例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] ）。
 * 
 * 请你在数组中搜索 target ，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 0
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 3
 * 输出：-1
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1], target = 0
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^4 
 * nums 中的每个值都 独一无二
 * nums 肯定会在某个点上旋转
 * -10^4 
 * 
 * 
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    // int biSearch(vector<int> &nums, int target, int left, int right)
    // {
    //     while (left <= right)
    //     {
    //         int mid = (left + right) / 2;
    //         if (nums[mid] == target)
    //             return mid;
    //         if (target > nums[mid])
    //             left = mid + 1;
    //         else
    //             right = mid - 1;
    //     }

    //     return -1;
    // }

    // int search(vector<int> &nums, int target)
    // {
    //     int len = nums.size();

    //     int left = 0, right = nums.size() - 1;
    //     while (left < right)
    //     {
    //         // 判断哪一侧是完全升序的序列
    //         int mid = (left + right) / 2;

    //         if (nums[mid] == target)
    //             return mid;

    //         // 左侧升序
    //         if (nums[left] <= nums[mid - 1])
    //         {
    //             int f = biSearch(nums, target, 0, mid - 1);
    //             if (f != -1)
    //                 return f;
    //             left = mid + 1;
    //         }
    //         else if (nums[mid + 1] <= nums[right])
    //         {
    //             int f = biSearch(nums, target, mid + 1, len - 1);
    //             if (f != -1)
    //                 return f;
    //             right = mid - 1;
    //         }
    //     }

    //     if (nums[left] == target)
    //         return left;
    //     else
    //         return -1;
    // }
    int search(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;

        // nums[0] <= target <= nums[i]
        //            target <= nums[i] < nums[0]
        //                      nums[i] < nums[0] <= target

    }
};
// @lc code=end




// 原来这题就是找下标啊。。。。。。。

// int search(vector<int> &nums, int target)
//     {
//         int res = -1;

//         for (int i = 0; i < nums.size(); i++)
//         {
//             if(nums[i] == target)
//                 res = i;
//         }

//         return res;
//     }