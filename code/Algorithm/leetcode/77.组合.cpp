/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (70.88%)
 * Likes:    177
 * Dislikes: 0
 * Total Accepted:    25K
 * Total Submissions: 35.1K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    void dfs(int n, int k, vector<int> temp, int start)
    {
        // 一次搜索完成
        if (temp.size() == k)
        {
            res.push_back(temp);
            return;
        }
        // 从上个数之后开始遍历, 保证每个数组是递增的, 避免消除重复
        for (int i = start; i <= n; i++)
        {
            temp.push_back(i);
            dfs(n, k, temp, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;
        dfs(n, k, temp, 1);
        return res;
    }
};
// @lc code=end
