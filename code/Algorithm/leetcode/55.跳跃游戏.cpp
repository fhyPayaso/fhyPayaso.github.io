/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 *
 * https://leetcode-cn.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (41.09%)
 * Likes:    859
 * Dislikes: 0
 * Total Accepted:    160K
 * Total Submissions: 388.9K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 判断你是否能够到达最后一个位置。
 * 
 * 示例 1:
 * 
 * 输入: [2,3,1,1,4]
 * 输出: true
 * 解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,1,0,4]
 * 输出: false
 * 解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
 * 
 * 
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int index = 0;
        int temp = 0;
        if (nums.size() == 1)
            return true;

        while (index < nums.size())
        {
            if (index == 0)
            {
                // 第一个值为0无法跳
                if (nums[index] == 0)
                    return false;
                temp = nums[index];
            }
            else
            {
                int curNum = nums[index];
                // 当前最大能走的步数为0，同时当前对应的值也为0(不是最后一位)
                // 则无法跳跃到最后
                if (curNum == 0 && temp == 0 && index < nums.size() - 1)
                    return false;
                // 当前数值若大于当前能走的最大步则更新
                if (curNum > temp)
                    temp = curNum;
            }
            index++;
            // 每次前进一步, 当前能走的最大长度就-1
            temp--;
        }
        return true;
    }
};
// @lc code=end
