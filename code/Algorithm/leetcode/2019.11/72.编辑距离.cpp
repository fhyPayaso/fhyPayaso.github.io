/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode-cn.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (54.90%)
 * Likes:    409
 * Dislikes: 0
 * Total Accepted:    19.9K
 * Total Submissions: 36.2K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 
 * 你可以对一个单词进行如下三种操作：
 * 
 * 
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * 
 * 
 * 示例 1:
 * 
 * 输入: word1 = "horse", word2 = "ros"
 * 输出: 3
 * 解释: 
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 
 * 
 * 示例 2:
 * 
 * 输入: word1 = "intention", word2 = "execution"
 * 输出: 5
 * 解释: 
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 * 
 * 
 */

// @lc code=start
#include <string>
#include <cmath>
using namespace std;
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int len1 = word1.length();
        int len2 = word2.length();
        int res[len1 + 1][len2 + 1];

        for (int i = 0; i <= len1; i++)
        {
            for (int j = 0; j <= len2; j++)
            {
                // 边界初始化按照最坏情况考虑
                // 即空串 <-> 已有串
                if (i == 0)
                {
                    res[i][j] = j;
                    continue;
                }
                else if (j == 0)
                {
                    res[i][j] = i;
                    continue;
                }
                int diff = word1[i - 1] == word2[j - 1] ? 0 : 1;

                int n1 = min(res[i - 1][j] + 1, res[i][j - 1] + 1);
                int n2 = res[i - 1][j - 1] + diff;
                res[i][j] = min(n1, n2);
            }
        }
        return res[len1][len2];
    }
};
// @lc code=end
