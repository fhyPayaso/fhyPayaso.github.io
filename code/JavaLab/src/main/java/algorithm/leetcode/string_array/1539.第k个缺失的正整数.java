package algorithm.leetcode.string_array;

/**
 * https://leetcode-cn.com/problems/kth-missing-positive-number/
 */
class LC1539 {

    public int findKthPositive(int[] arr, int k) {

        if (arr.length == 0 || k == 0) {
            return k;
        }

        int li = 0;
        int cnt = 1;
        int index = 0;


        // 原本长度为1~ k + arr.length
        while (cnt <= k + arr.length) {


            if (index < arr.length && arr[index] == cnt) {
                // 正常没有缺失的数
                index++;
            } else {
                // 缺失的数
                li++;
                if (k == li) {
                    return cnt;
                }
            }

            cnt++;
        }

        return 0;
    }

}