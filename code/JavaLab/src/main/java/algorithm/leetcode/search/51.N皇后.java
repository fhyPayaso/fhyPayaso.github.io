package algorithm.leetcode.search;

import java.util.ArrayList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/n-queens/
 * <p>
 * n皇后问题 研究的是如何将 n个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 给你一个整数 n ，返回所有不同的n皇后问题 的解决方案。
 * 每一种解法包含一个不同的n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 */
class LC51 {

    List<List<String>> res = new ArrayList<>();

    public List<List<String>> solveNQueens(int n) {

        char[][] map = new char[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                map[i][j] = '.';

        helper(map, 0);
        return res;
    }

    public void helper(char[][] map, int row) {

        int n = map.length;

        // 回溯边界
        if (row == n) {
            List<String> list = new ArrayList<>();
            for (char[] chars : map) {
                list.add(new String(chars));
            }
            res.add(list);
            return;
        }

        for (int col = 0; col < n; col++) {

            boolean check = true;
            // 检查是否满足落子要求, 检查之前的行
            for (int r = 0; r < row; r++) {

                // 两者相差之间的行数
                int diff = row - r;

                if (map[r][col] == 'Q' // 同列有落子
                        || (col + diff < n && map[r][col + diff] == 'Q') // 右斜线有落子
                        || (col - diff >= 0 && map[r][col - diff] == 'Q')) { //左斜线有落子
                    check = false;
                    break;
                }
            }

            // 每一行只落子一次
            if (check) {
                map[row][col] = 'Q';
                helper(map, row + 1);
                map[row][col] = '.';
            }
        }
    }

}