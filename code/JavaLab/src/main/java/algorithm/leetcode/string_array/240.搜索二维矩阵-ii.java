package algorithm.leetcode.string_array;

/**
 * https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
 */
class LC240 {

    public boolean searchMatrix(int[][] matrix, int target) {

        if (matrix.length == 0) {
            return false;
        }


        int i = 0;
        int j = matrix[0].length - 1;

        while (i >= 0 && i < matrix.length && j >= 0 && j < matrix[0].length) {
            if (matrix[i][j] > target) {
                j--;
            } else if (matrix[i][j] < target) {
                i++;
            } else {
                return true;
            }
        }

        return false;
    }
}