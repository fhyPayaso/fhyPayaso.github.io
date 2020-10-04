/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

#include <vector>
#include <cmath>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        // 将出现过的索引所在的数值都变成负数
        // 最终正数的索引值就是未出现过的
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            nums[index] = -abs(nums[index]);
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
                res.push_back(i + 1);

        return res;
    }
};
// @lc code=end
