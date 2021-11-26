/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (61.68%)
 * Likes:    175
 * Dislikes: 0
 * Total Accepted:    68K
 * Total Submissions: 110K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */

// @lc code=start

#include <vector>

using namespace std;

/*

利用排列组合公式

杨辉三角第i行第j列的数值为组合数C(i,j)

若求第n行 
C(n,j) = n! / (j! * (n - j)!)
C(n ,j + 1) = n! / (( j + 1)! * (n - j - 1)!)

C(n ,j + 1) / C(n,j) = (n - j) / (j + 1)

*/

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res;
        long temp = 1;
        for (int i = 0; i < rowIndex + 1; i++)
        {
            res.push_back(temp);
            temp = temp * (rowIndex - i) / (i + 1);
        }
        return res;
    }
};
// @lc code=end
