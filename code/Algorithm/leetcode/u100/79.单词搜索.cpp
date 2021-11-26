/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (43.76%)
 * Likes:    704
 * Dislikes: 0
 * Total Accepted:    124K
 * Total Submissions: 283.3K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

#include <vector>
#include <queue>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    int im[4] = {0, 0, -1, 1};
    int jm[4] = {1, -1, 0, 0};

    bool res = false;

    void dfs(vector<vector<char>> &m, string &word, int &index, int &i, int &j, vector<vector<int>> &vist)
    {

        if (res)
            return;

        if (word.size() == index)
        {
            res = true;
            return;
        }

        int h = m.size();
        int w = m[0].size();

        for (int k = 0; k < 4; k++)
        {
            int ni = i + im[k];
            int nj = j + jm[k];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w)
                continue;
            if (vist[ni][nj])
                continue;
            if (word[index] == m[ni][nj])
            {
                if (word.size() == index + 1)
                {
                    res = true;
                    return;
                }
                vist[ni][nj] = 1;
                int a = index + 1;
                dfs(m, word, a, ni, nj, vist);
                vist[ni][nj] = 0;
            }
        }
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int h = board.size();
        int w = board[0].size();

        vector<vector<int>> vist(h, vector<int>(w, 0));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (res)
                    return true;

                if (board[i][j] == word[0])
                {
                    vist[i][j] = 1;
                    int a = 1;
                    dfs(board, word, a, i, j, vist);
                    vist[i][j] = 0;
                }
            }
        }
        return res;
    }
};
// @lc code=end
