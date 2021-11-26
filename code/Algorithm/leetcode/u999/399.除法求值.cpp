/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 *
 * https://leetcode-cn.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (55.03%)
 * Likes:    457
 * Dislikes: 0
 * Total Accepted:    31.5K
 * Total Submissions: 53K
 * Testcase Example:  '[["a","b"],["b","c"]]\n[2.0,3.0]\n[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * 给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和
 * values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
 * 
 * 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj
 * = ? 的结果作为答案。
 * 
 * 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0
 * 替代这个答案。
 * 
 * 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
 * [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 * 输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
 * 解释：
 * 条件：a / b = 2.0, b / c = 3.0
 * 问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 * 结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0],
 * queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 * 输出：[3.75000,0.40000,5.00000,0.20000]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：equations = [["a","b"]], values = [0.5], queries =
 * [["a","b"],["b","a"],["a","c"],["x","y"]]
 * 输出：[0.50000,2.00000,-1.00000,-1.00000]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * equations[i].length == 2
 * 1 i.length, Bi.length 
 * values.length == equations.length
 * 0.0 < values[i] 
 * 1 
 * queries[i].length == 2
 * 1 j.length, Dj.length 
 * Ai, Bi, Cj, Dj 由小写英文字母与数字组成
 * 
 * 
 */
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        set<string> S;
        for (int i = 0; i < equations.size(); i++)
        {
            S.insert(equations[i][0]);
            S.insert(equations[i][1]);
        }
        vector<string> vec;
        map<string, int> indexMap;
        for (auto it = S.begin(); it != S.end(); it++)
        {
            string str = *it;
            indexMap[str] = vec.size();
            vec.push_back(str);
        }

        int len = vec.size();

        double valMap[len][len];
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                valMap[i][j] = i == j ? 1.0 : -1.0;

        for (int i = 0; i < equations.size(); i++)
        {
            int v1 = indexMap[equations[i][0]];
            int v2 = indexMap[equations[i][1]];
            valMap[v1][v2] = values[i];
            if (values[i] != 0)
                valMap[v2][v1] = 1 / values[i];
        }

        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (valMap[i][j] == -1)
                    continue;
                // 对于点ij能到达的下一个节点
                for (int k = 0; k < len; k++)
                {
                    if (valMap[j][k] != -1.0)
                        valMap[i][k] = valMap[i][j] * valMap[j][k];
                }
            }
        }

        vector<double> res;
        for (int i = 0; i < queries.size(); i++)
        {
            auto it0 = indexMap.find(queries[i][0]);
            auto it1 = indexMap.find(queries[i][1]);
            if (it0 == indexMap.end() || it1 == indexMap.end())
            {
                res.push_back(-1.0);
                continue;
            }
            int v1 = indexMap[queries[i][0]];
            int v2 = indexMap[queries[i][1]];
            res.push_back(valMap[v1][v2]);
        }

        return res;
    }
};
// @lc code=end
