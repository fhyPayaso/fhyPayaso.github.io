/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (62.27%)
 * Likes:    724
 * Dislikes: 0
 * Total Accepted:    156.2K
 * Total Submissions: 249.9K
 * Testcase Example:  '3\n7'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 例如，上图是一个7 x 3 的网格。有多少可能的路径？
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 * 
 * 
 * 示例 2:
 * 
 * 输入: m = 7, n = 3
 * 输出: 28
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= m, n <= 100
 * 题目数据保证答案小于等于 2 * 10 ^ 9
 * 
 * 
 */
// 机器人一定会走m+n-2步，即从m+n-2中挑出m-1步向下走 即C（（m+n-2），（m-1））
// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        int a = m + n - 2; // 18
        int b = m - 1;     // 8

        int diff = a - b;
        unsigned long long Cab = 1;
        for (int i = 1; i <= diff; i++)
            Cab = Cab * (i + b) / i;
        return Cab;
    }
};
// @lc code=end

// dp
// int uniquePaths(int m, int n)
//     {

//         unsigned long long table[101][101] = {0};

//         for (int i = 1; i <= m; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 if (i == 1 || j == 1)
//                 {
//                     table[i][j] = 1;
//                 }
//                 else
//                 {
//                     table[i][j] = table[i][j - 1] + table[i - 1][j];
//                 }
//             }
//         }
//         return table[m][n];
//     }