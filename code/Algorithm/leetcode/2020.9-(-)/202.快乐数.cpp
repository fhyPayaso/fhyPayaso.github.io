/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 *
 * https://leetcode-cn.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (60.54%)
 * Likes:    440
 * Dislikes: 0
 * Total Accepted:    98.6K
 * Total Submissions: 162.6K
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数 n 是不是快乐数。
 * 
 * 「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到
 * 1。如果 可以变为  1，那么这个数就是快乐数。
 * 
 * 如果 n 是快乐数就返回 True ；不是，则返回 False 。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：19
 * 输出：true
 * 解释：
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * 
 */

// @lc code=start

// 这题不能开大数组做, 会超时, 只能用map！！！
// 数组开小了，特殊样例过不了1111111

#include <map>

class Solution
{
public:
    // int M[1000000];

    int getNum(int n)
    {
        int res = 0;

        while (n != 0)
        {
            int cur = n % 10;
            res += (cur * cur);
            n /= 10;
        }

        return res;
    }

    // bool isHappy(int n)
    // {

    //     for (int i = 0; i < 1000000; i++)
    //         M[i] = 0;

    //     if (n == 1)
    //         return true;

    //     int sum = 0;
    //     while (n != 1)
    //     {

    //         M[n]++;
    //         sum = getNum(n);
    //         if (sum == 1)
    //             return true;
    //         if (M[sum] != 0)
    //             return false;
    //         n = sum;
    //     }

    //     return true;
    // }

    bool isHappy(int n)
    {
        std::map<int, int> int_map;
        if (n == 1)
        {
            return true;
        }
        int sum = 0;
        while (n != 1)
        {
            int_map.insert(pair<int, int>(n, n));
            sum = getNum(n);
            if (sum == 1)
            {
                return true;
            }
            if (int_map.count(sum))
                return false;
            n = sum;
        }
        return true;
    }
};
// @lc code=end
