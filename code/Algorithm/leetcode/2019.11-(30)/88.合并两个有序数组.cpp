/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (45.64%)
 * Likes:    350
 * Dislikes: 0
 * Total Accepted:    86.6K
 * Total Submissions: 188.8K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        

        if (m == 0)
        {
            nums1 = nums2;
            return;
        }
        else if (n == 0)
        {
            return;
        }
        int newn[m];

        for (int i = 0; i < m; i++)
            newn[i] = nums1[i];
        int id1 = 0, id2 = 0;
        while (id1 < m || id2 < n)
        {
            int index = id1 + id2;

            if (id1 >= m)
            {
                nums1[index] = nums2[id2++];
                continue;
            }
            else if (id2 >= n)
            {
                nums1[index] = newn[id1++];
                continue;
            }

            if (newn[id1] <= nums2[id2])
                nums1[index] = newn[id1++];
            else
                nums1[index] = nums2[id2++];
        }
    }
};
// @lc code=end
