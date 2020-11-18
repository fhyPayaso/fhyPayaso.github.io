/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (58.31%)
 * Likes:    675
 * Dislikes: 0
 * Total Accepted:    96.4K
 * Total Submissions: 165.3K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */

#include<cmath>

using namespace std;

// @lc code=start
class Solution {
public:

    //利用四平方和定理：任何一个整数都可以表示为不超过4个数的平方和
    // 推论：当且仅当n=4^a(8b+7)时，n恰好可以表示为4个数的平方和
    int numSquares(int n) 
    {
        while (0 == n % 4) n /= 4;
        // 若符合公式直接为4
        if (7 == n % 8) return 4;
        for (int i = 0; i * i < n; ++i) 
        {
            // 判断j是否为整数
            int j = pow(n - i * i, 0.5);
            if (n == i * i + j * j) 
            {
                if(i == 0)
                    return 1;
                else
                    return 2;   
            }
        }
        return 3;
    }
};
// @lc code=end

// 这题正常dfs能解 就是剪枝需要特殊处理一下

// class Solution {
// public:

//     int minVal = 4;
    
//     void dfs(int val, int range, int step)
//     {
        
//         if(val == 0)
//         {
//             minVal = min(step, minVal);
//             return;
//         }

//         if(step >= minVal)
//             return;
        
//         if(val < 0)
//             return;

//         for(int i=range ; i>= 1; i--)
//         {
//             int newVal = val - i * i;
//             dfs(newVal, range,  step + 1);
//         }
//     }

//     int numSquares(int n) 
//     {
//         int range = sqrt(n) + 1;
//         dfs(n, range, 0);
//         return minVal;
//     }
// };



