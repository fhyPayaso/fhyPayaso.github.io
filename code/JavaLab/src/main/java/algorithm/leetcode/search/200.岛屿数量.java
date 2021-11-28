package algorithm.leetcode.search;

/**
 * https://leetcode-cn.com/problems/number-of-islands/
 */
class LC200 {

    private static int[][] move = {
            {1, -1, 0, 0},
            {0, 0, 1, -1}
    };


    public int numIslands(char[][] grid) {

        if (grid.length == 0) {
            return 0;
        }


        int res = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                // 碰到陆地开始搜索
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;
                }

            }
        }
        return res;
    }


    public void dfs(char[][] grid, int i, int j) {
        if (i >= 0 && i < grid.length && j >= 0 && j < grid[0].length) {
            if (grid[i][j] == '1') {
                grid[i][j] = '0';
                for (int k = 0; k < 4; k++) {
                    dfs(grid, i + move[0][k], j + move[1][k]);
                }
            }
        }
    }
}