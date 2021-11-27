package algorithm.leetcode.string_array;

/**
 * https://leetcode-cn.com/problems/spiral-matrix-ii/
 * <p>
 * 螺旋生成矩阵
 */
class LC59 {

    public int[][] generateMatrix(int n) {

        int[][] matrix = new int[n][n];


        if (n == 0) {
            return matrix;
        }
        int step = 1;

        int left = 0, right = matrix[0].length - 1;
        int top = 0, bottom = matrix.length - 1;

        while (left <= right && top <= bottom) {

            // 从左到右
            for (int i = left; i <= right; i++) {
                matrix[top][i] = step++;
            }
            top++;
            if (top > bottom) {
                break;
            }

            // 从上到下
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = step++;
            }
            right--;
            if (left > right) {
                break;
            }


            // 从右到左
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = step++;
            }
            bottom--;
            if (top > bottom) {
                break;
            }

            // 从下到上
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = step++;
            }
            left++;
            if (left > right) {
                break;
            }
        }

        return matrix;

    }
}