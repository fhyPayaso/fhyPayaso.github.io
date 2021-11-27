/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (34.54%)
 * Likes:    703
 * Dislikes: 0
 * Total Accepted:    95.4K
 * Total Submissions: 275.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start

#include <vector>
#include <algorithm>
using namespace std;

// 从最末位寻找第一个破坏升序的数nums[pos - 1], 然后在遍历过的数里寻找比该数大的最小的一个数。
// 如遍历过的数为[7,6,4,3], nums[pos - 1]为5, 则5需要与6进行交换, 在将[7,5,4,3]改为升序(这里使用reverse)。

// 遍历过的数从后往前一定是升序, 故改为从前往后升序只需要反转该部分即可。
// 寻找第一个比nums[pos - 1]大的数, 只需改为从前往后升序之后, 从升序的第一个数开始遍历比较大小即可


class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 1;
        // 找到第一个非逆序的节点
        while (i > 0 && nums[i - 1] >= nums[i])
            --i;
        if (i == 0)
            reverse(nums.begin(), nums.end());
        else
        {
            // 找到后面大于当前节点的最小值
            int j = nums.size() - 1;
            while (j > i && nums[j] <= nums[i - 1])
                --j;
            // 交换当前节点和最小值
            swap(nums[i - 1], nums[j]);
            // 将后面的值排序
            sort(nums.begin() + i, nums.end());
        }
    }
};

// void nextPermutation(vector<int>& nums) {
//         int i = nums.size() - 1;
//         while (i > 0 && nums[i - 1] >= nums[i]) --i;
//         if (i == 0) reverse(nums.begin(), nums.end());
//         else {
//             int j = nums.size() - 1;
//             while (j > i && nums[j] <= nums[i - 1]) --j;
//             swap(nums[i - 1], nums[j]);
//             sort(nums.begin() + i, nums.end());
//         }
//     }

// @lc code=end
