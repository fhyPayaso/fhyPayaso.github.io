package algorithm.leetcode.search;

/**
 * https://leetcode-cn.com/problems/word-search/
 * <p>
 * 给定一个m x n 二维字符网格board 和一个字符串单词word 。如果word 存在于网格中，返回 true ；否则，返回 false 。
 * <p>
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 */
class LC79 {

    public static void main(String[] args) {
        LC79 main = new LC79();

        char[][] board = {{'A', 'B', 'C', 'E' }, {'S', 'F', 'C', 'S' }, {'A', 'D', 'E', 'E' }};
        main.exist(board, "ABCCED");

    }

    boolean res = false;

    public boolean exist(char[][] board, String word) {

        int m = board.length;
        int n = board[0].length;
        char[] words = word.toCharArray();

        boolean[][] vist = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, words, 0, board, vist);
                if (res) return true;
            }
        }
        return res;
    }

    /**
     * @param i     当前访问元素横坐标
     * @param j     当前访问元素纵坐标
     * @param str   要搜索的字符串
     * @param index 当前搜索到的字符串位置
     * @param board 原始图
     * @param vist  访问标记
     */
    public void dfs(int i, int j, char[] str, int index, char[][] board, boolean[][] vist) {

        // 搜索完成
        if (index == str.length) {
            res = true;
            return;
        }
        int m = vist.length;
        int n = vist[0].length;

        // 数组越界或者已经访问过, 或者匹配失败
        if (i < 0 || i >= m || j < 0 || j >= n
                || vist[i][j] || board[i][j] != str[index]) {
            return;
        }

        vist[i][j] = true;
        dfs(i + 1, j, str, index + 1, board, vist);
        dfs(i - 1, j, str, index + 1, board, vist);
        dfs(i, j + 1, str, index + 1, board, vist);
        dfs(i, j - 1, str, index + 1, board, vist);
        vist[i][j] = false;
    }
}