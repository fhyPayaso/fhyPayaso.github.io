package algorithm.leetcode.string_array;


/**
 * https://leetcode-cn.com/problems/search-a-2d-matrix/
 * <p>
 * 二分搜索
 */
class LC74 {

    public boolean searchMatrix(int[][] matrix, int target) {


        int top = 0;
        int bottom = matrix.length - 1;
        int end = matrix[0].length - 1;

        if (bottom == 0 && end == 0) {
            return matrix[0][0] == target;
        } else if (matrix[0][0] > target || matrix[bottom][end] < target) {
            return false;
        }

        while (top < bottom) {

            int mid = (top + bottom) / 2;
            if (matrix[mid][end] > target) {
                bottom = mid - 1;
            } else if (matrix[mid][end] < target) {
                top = mid + 1;
            } else {
                return true;
            }
        }

        if (target > matrix[top][end]) {
            top++;
        } else if (target == matrix[top][end]) {
            return true;
        }


        int left = 0, right = end;
        while (left < right) {
            int mid = (left + right) / 2;
            if (matrix[top][mid] > target) {
                right = mid - 1;

            } else if (matrix[top][mid] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }

        return matrix[top][left] == target;
    }
}