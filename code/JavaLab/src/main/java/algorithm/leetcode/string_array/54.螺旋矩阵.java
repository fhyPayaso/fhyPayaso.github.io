package algorithm.leetcode.string_array;

import java.util.ArrayList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/spiral-matrix/
 * <p>
 * 螺旋打印矩阵
 */
class LC54 {

    public List<Integer> spiralOrder(int[][] matrix) {

        List<Integer> res = new ArrayList<>();

        int left = 0, top = 0;
        int bottom = matrix.length - 1, right = matrix[0].length - 1;
        int i;

        while (left <= right && top <= bottom) {


            for (i = left; i <= right; i++) {
                res.add(matrix[top][i]);
            }
            if (++top > bottom) break;


            for (i = top; i <= bottom; i++) {
                res.add(matrix[i][right]);
            }
            if (--right < left) break;


            for (i = right; i >= left; i--) {
                res.add(matrix[bottom][i]);
            }
            if (--bottom < top) break;


            for (i = bottom; i >= top; i--) {
                res.add(matrix[i][left]);
            }
            if (++left > right) break;

        }

        return res;
    }
}