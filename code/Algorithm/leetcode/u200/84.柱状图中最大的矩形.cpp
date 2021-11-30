/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (42.03%)
 * Likes:    1050
 * Dislikes: 0
 * Total Accepted:    104.2K
 * Total Submissions: 247.8K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 
 * 
 * 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
 * 
 * 
 * 
 * 
 * 
 * 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [2,1,5,6,2,3]
 * 输出: 10
 * 
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int res = 0;
        heights.push_back(0);

        stack<int> stk;

        for (int i = 0; i < heights.size(); i++)
        {
            // 当前元素比栈顶元素小，则可以出栈
            while (!stk.empty() && heights[stk.top()] > heights[i])
            {
                int index = stk.top();
                stk.pop();
                // 弹出后此时的top代表左侧第一个小于heights[index]的位置
                // 所以i - stk.top() - 1即为当前宽度
                // 若栈为空，则说明左侧没有比heights[index]还小的值，
                // 相当于i 即为当前宽度
                int w = stk.empty() ? i : (i - stk.top() - 1);
                int s = heights[index] * w;
                res = max(res, s);
            }
            stk.push(i);
        }

        return res;
    }
};

// 暴力O(n2)
// int largestRectangleArea(vector<int> &heights)
//     {
//         int res = 0;

//         for (int i = 0; i < heights.size(); i++)
//         {
//             int h = heights[i];
//             int w1 = 0;
//             while (i + w1 < heights.size() && heights[i + w1] >= heights[i])
//                 w1++;

//             int w2 = 0;
//             while (i - w2 >= 0 && heights[i - w2] >= heights[i])
//                 w2++;
//             int w = w1 + w2 - 1;
//             res = max(w * h, res);
//         }

//         return res;
//     }

// @lc code=end
