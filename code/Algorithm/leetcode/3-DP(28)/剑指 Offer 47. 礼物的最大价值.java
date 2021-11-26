package algorithm.offer.over.dp;

/* ====================================================
#
#   @Author        : fhyPayaso
#   @Email         : 401619823@qq.com
#   @Date          : 2021/3/13 9:23 下午
#   @Description   :  剑指 Offer 47. 礼物的最大价值
https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
# ====================================================*/
public class Offer47 {

    public int maxValue(int[][] grid) {

        int h = grid.length;
        if (h == 0) {
            return 0;
        }
        int w = grid[0].length;


        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {

                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0) {
                    grid[i][j] += grid[i][j - 1];
                } else if (j == 0) {
                    grid[i][j] += grid[i - 1][j];
                } else {
                    grid[i][j] += Math.max(grid[i][j - 1], grid[i - 1][j]);
                }
            }
        }


        return grid[h - 1][w - 1];
    }
}
