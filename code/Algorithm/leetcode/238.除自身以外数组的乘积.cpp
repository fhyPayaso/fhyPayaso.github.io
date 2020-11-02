/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 *
 * https://leetcode-cn.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (70.89%)
 * Likes:    616
 * Dislikes: 0
 * Total Accepted:    83K
 * Total Submissions: 116.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i]
 * 之外其余各元素的乘积。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [1,2,3,4]
 * 输出: [24,12,8,6]
 * 
 * 
 * 
 * 提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
 * 
 * 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
 * 
 * 进阶：
 * 你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
 * 
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res(nums.size());

        int left = 1, right = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            res[i] = left;
            left *= nums[i];
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            res[i] *= right;
            right *= nums[i];
        }

        return res;
    }
};
// @lc code=end

// 啊 这  做完了发现题目说不能用除法
// vector<int> productExceptSelf(vector<int> &nums)
//     {
//         int tol = 1;
//         int zNum = 0;
//         int zIndex = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] != 0)
//             {
//                 tol *= nums[i];
//             }
//             else
//             {
//                 if(zNum==0)
//                 {
//                     zNum++;
//                     zIndex = i;
//                 }
//                 else
//                 {
//                     vector<int> r(nums.size(),0);
//                     return r;
//                 }

//             }
//         }

//         if(zNum == 1)
//         {
//             vector<int> r(nums.size(),0);
//             r[zIndex] = tol;
//             return r;
//         }

//         vector<int> res;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if(nums[i] == 0)
//                 res.push_back(tol);
//             else
//                 res.push_back(tol / nums[i]);
//         }

//         return res;
//     }