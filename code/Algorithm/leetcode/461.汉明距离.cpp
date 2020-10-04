/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int z = x ^ y;
        int res = 0;
        while (z)
        {
            z = z & (z - 1);
            res++;
        }

        return res;
    }
};
// @lc code=end
