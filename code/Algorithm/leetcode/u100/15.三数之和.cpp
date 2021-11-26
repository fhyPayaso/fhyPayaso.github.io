/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (29.57%)
 * Likes:    2700
 * Dislikes: 0
 * Total Accepted:    350.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        set<vector<int>> s;

        for (int k = nums.size() - 1; k >= 2; k--)
        {

            // 选择k作为标志点, 然后双指针当做两数之和来做
            int i = 0, j = k - 1;
            while (i < j)
            {
                int sum = nums[k] + nums[i] + nums[j];
                if (sum == 0)
                {
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    s.insert(v);
                    if (!s.count(v))
                    {
                        res.push_back(v);
                        
                    }
                    i++;
                    j--;

                    while (i < j && nums[i] == nums[i - 1])
                        i++;
                    while (i < j && nums[j] == nums[j + 1])
                        j--;
                }
                else if (sum < 0)
                    i++;
                else if (sum > 0)
                    j--;
            }
            // // k也可以去重复
            // while (k >= 2 && k < nums.size() - 1 && nums[k] == nums[k + 1])
            // {
            //     k--;
            // }
        }

        return res;
    }
};
// @lc code=end

// dfs 暴力超时
// vector<vector<int>> res;

// set<vector<int>> s;

// void dfs(vector<int> &nums, vector<int> cur, vector<bool> vist)
// {
//     if (cur.size() == 3)
//     {
//         if (cur[0] + cur[1] + cur[2] == 0)
//         {

//             sort(cur.begin(), cur.end());
//             if (s.count(cur))
//                 return;
//             s.insert(cur);

//             res.push_back(cur);
//         }

//         return;
//     }

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (vist[i])
//             continue;
//         vist[i] = true;
//         cur.push_back(nums[i]);
//         dfs(nums, cur, vist);
//         cur.pop_back();
//         vist[i] = false;
//     }
// }

// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     vector<int> cur;
//     vector<bool> vist(nums.size(), false);
//     dfs(nums, cur, vist);
//     return res;
// }