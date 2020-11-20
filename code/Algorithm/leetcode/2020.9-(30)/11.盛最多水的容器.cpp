/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode-cn.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (64.00%)
 * Likes:    1807
 * Dislikes: 0
 * Total Accepted:    280K
 * Total Submissions: 436.7K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为
 * (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 * 
 * 
 * 
 * 
 * 
 * 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[1,8,6,2,5,4,8,3,7]
 * 输出：49
 * 
 */

// @lc code=start

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        int left = 0;
        int right = height.size() - 1;
        int maxRes = 0;

        while (left < right)
        {
            // 计算当前区域面积,并更新最大值
            int smaller = min(height[left], height[right]);
            int curRes = smaller * (right - left);
            maxRes = max(maxRes, curRes);

            // 因为当前面积由 左右两侧中最短的挡板决定
            // 所以此时移动高挡板必然不会使面积增加
            // 而移动短挡板后则可能提高挡板下限
            // 所以每次只移动
            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxRes;
    }
};

// @lc code=end

// 暴力, 超时
//
// int maxArea(vector<int> &height)
// {

//     int len = height.size();
//     int maxRes = -1;

//     for (int i = 0; i < len; i++)
//     {
//         for (int j = i + 1; j < len; j++)
//         {
//             int smaller = height[i] < height[j] ? height[i] : height[j];
//             int curRes = (j - i) * smaller;
//             if (curRes > maxRes)
//                 maxRes = curRes;
//         }
//     }
//     return maxRes;
// }
